# Map Annotations

Draw freehand on the normal 2D map screen. The server stores strokes on the
physical map item, so its next holder can open it and see the same annotations.
Separate maps have separate drawings. Annotations use normal item persistence;
they last as long as that map survives the server's persistence and cleanup rules.

## Install and use

Pack the `scripts` addon and load the resulting mod on both server and clients.
No new item types, loot entries, Community Framework, or Expansion dependencies
are required. Vanilla `ChernarusMap` items and script subclasses inherit the
feature. Both the code and the UI layouts live in `scripts.pbo`.

Hold a map and use its normal **Unfold map** action with the server configured
to show the 2D map (`use3DMap: false`). The annotation toolbar appears at the top.
The menu starts in **Pan** mode, using normal map navigation. Click **Mode: Pan**
to switch to **Draw**, then hold the left mouse button to draw. Release to save.
Switch back to Pan for navigation and zoom. A click makes a dot.

- **Ink:** cycles black, red, blue, and green.
- **Width:** cycles 2, 4, and 6 screen pixels. Width stays readable as you zoom;
  stroke positions stay anchored to the terrain.
- **Undo last:** removes the last saved stroke, including a previous holder's.
- **Clear map:** click twice within five seconds to erase all strokes.
- **Reload:** fetches the authoritative server copy again.
- **Hide ink:** temporarily hides the drawings on your screen.

No pen is required in this initial version. Hold the physical map to read or
change its annotations; a generic map shortcut without an item does not attach
drawings to a player profile. Only one edit may await acknowledgment at a time.
Wait for **Saved** before dropping the map or handing it over. Closing the map
discards an unfinished stroke; a completed stroke already sent still awaits
normal server processing. Saving is acknowledgment of server memory, with disk
durability following DayZ's ordinary persistence cycle.

## Network and storage budget

The client samples at most 30 times a second, ignores movements under three
screen pixels, and simplifies a finished stroke with Ramer-Douglas-Peucker.
It increases the simplification tolerance if needed to retain the whole stroke
within 128 points. A gesture stops automatically at 512 raw samples; release and
press again to continue. Mouse movement never streams RPCs.

Each terrain X/Z pair is quantized to two 16-bit values and packed into one
32-bit integer. Altitude is unnecessary for a flat map. The maximum coordinate
rounding error on 15,360 m Chernarus is about 12 cm per axis. Positions use the
current terrain extent, and stored terrain name/size prevent displaying a map's
coordinates against a different terrain.

| Operation | Serialized application data, before engine/network overhead |
| --- | --- |
| Add a stroke | 24-byte header + 12-byte brush/count + up to 512 bytes of coordinates: 548 bytes maximum |
| Add acknowledgment | 36-byte header + the accepted stroke: 560 bytes maximum |
| Undo or clear | 24-byte request and 36-byte acknowledgment |
| Download a page | 36-byte header + up to 16 strokes and 512 points: 2,276 bytes maximum |
| Persist a map | Up to 32 KiB of coordinates plus stroke metadata and terrain/schema fields |

Adds send only the new stroke. Undo/clear send an operation code. An open map
pulls successive pages, with at most one outstanding request and at least 200 ms
between requests. Completed edits obey the same spacing. The server additionally
limits accepted requests to one per 100 ms per map. Budget figures describe the
application's fields, not measured wire traffic, engine framing, or compression.

Maps accept at most **256 strokes and 8,192 points**, whichever limit is reached
first. Strokes and pages have independently bounded scalar counts that are
checked before decoding points. At the client request limit, a sequence of
maximum-size new strokes carries about 2.7 KiB/s upstream before overhead.

The server checks that the sender is alive, conscious, unrestrained, and holding
that exact map. Replies target that player's identity, never all clients.
Revisions reject stale or duplicate edits; request IDs and per-open tokens
discard old replies. A changed revision triggers a fresh download. An uncertain
timeout disables editing until Reload, rather than automatically resubmitting
an edit that may already have succeeded. Empty snapshots are explicit, so clearing
all strokes synchronizes correctly.

## Persistence and compatibility

The feature extends the `ChernarusMap` script class: DayZDiag rejects direct
modification of the engine `ItemMap` class. Its item save hooks retain parent
serialization and append a versioned annotation record. Old maps without this
extension start blank; malformed nonempty records fail loading. Use a copy of
your server persistence for initial testing. Removing a persistence-extending
mod from an existing save is not a supported migration in this first version.

The feature has its own storage and RPCs; it does not depend on vanilla marker
synchronization. The map menu tolerates subclasses without a vanilla marker
array, including the initialization pattern in `iat_custom_map`.

Mods that replace `MapMenu`, the unfold-map action, or ChernarusMap save/RPC hooks
need integration testing and must preserve the relevant parent calls. Map item
replacement by a trader or another mod also needs testing: a newly spawned map
does not automatically inherit arbitrary script data from the deleted original.

Drawings appear in the 2D map UI. This version does not alter the physical map's
3D material, provide typed labels, save through a wipe, or export drawings to a
different server. Everyone holding a map can add, undo, and erase its strokes.

## Manual verification

1. Load the mod on a server and two clients. Open map A and draw a route, a closed
   circle, a short mark, and dots in several colors and widths. Wait for Saved.
2. Pan, zoom, resize/change resolution, close, and reopen. Confirm ink stays on
   the intended places. Verify Pan and Draw modes do not fight over dragging.
3. Open a second physical map B; it should remain blank. Return to A and confirm
   its own ink is present.
4. Drop A, have the second client pick it up and open it, then add a stroke and
   pass it back. Repeat via a corpse and a container.
5. Undo, clear with confirmation, close/reopen, and hand over the now-empty map.
   Confirm old ink does not return.
6. Preserve A through an ordinary persistence save and server restart. Reconnect
   with both clients and verify it again.
7. Test rapid short strokes, long scribbles, a nearly full map, interruption by
   death/drop, and Reload after interrupted connectivity. Confirm failures show
   feedback and another map's data never appears.
8. Repeat using the server's usual map/UI mods. Test a pre-mod saved map and
   inventory/storage locations that your server normally preserves.

See [tests/README.md](tests/README.md) for automated checks and their limits.
