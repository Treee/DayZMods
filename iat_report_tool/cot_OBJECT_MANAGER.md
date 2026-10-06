# IAT COT Object Manager

The new module files use the `cot_` prefix. Existing report-tool config loads these script directories and already depends on COT.

## Use

Rebuild the scripts PBO with the new scripts and layout, load the updated report-tool mod on the server and clients, restart, and reconnect.

Open COT's **IAT Object Manager (OM)**. Create a group, enter its name, and browse scope 1 classes. Double-click a class to place a local preview at the pointer's surface hit, or use **Place at crosshair**.

Select an entry in the object list, click its object outside COT windows, or use **Select at crosshair**. Enter position X/Y/Z, yaw/pitch/roll in degrees, and uniform scale. Scrolling a focused numeric field changes it by 0.1; Shift changes the step to 1.0. Smaller adjustments can be typed.

**Duplicate**, **Delete**, and **Snap** operate on the selected entry. Snap casts down from ten metres above the object's origin without changing rotation or compensating for model-base offsets.

**Save Group** writes the JSON and immediately applies the group on the server. Enable/disable and rename changes also require saving. **Discard / reload** abandons the draft. Save or discard before switching groups or closing the editor.

To delete a saved group and its live objects, discard any unsaved edits, then click **Delete saved group** twice within five seconds.

Group names are unique without regard to case. Names may contain up to 80 characters and must not be empty. There is no uniqueness requirement for object entries: repeated classnames, identical transforms, and multiple objects at the same position are allowed.

## JSON

All groups are stored in one file:

`$profile:CommunityOnlineTools/ObjectManager/cot_objectgroups.json`

The file is a plain JSON array; an empty configuration is `[]`:

```json
[
  {
    "m_Name": "Trading post wells",
    "m_Enabled": true,
    "m_Objects": [
      {
        "m_ClassName": "Land_Misc_Well_Pump_Blue",
        "m_Position": [7500.0, 300.0, 7500.0],
        "m_Orientation": [30.0, 0.0, 0.0],
        "m_Scale": 1.0
      }
    ]
  },
  {
    "m_Name": "Workshop",
    "m_Enabled": false,
    "m_Objects": []
  }
]
```

There are no saved IDs, world names, versions, revisions, or network records. Stop the server before editing the file manually. The unreleased schema uses the member names shown above for both saved JSON and editor JSON payloads. Earlier development field names are superseded; recreate development configurations or rename their keys to this schema.

Enabled groups spawn once at startup. The server keeps an array of live Object references per group, aligned with the JSON entries. A save reuses same-class objects at matching array positions, creates new/replacement objects, and deletes references no longer needed. Repeated saves therefore do not accumulate objects. Deleting/reordering entries can change which instance occupies an array position; the saved placements remain authoritative.

The normal engine handles object replication. This module sends RPCs only for editor data and save/delete requests; there are no custom network snapshots, scale polling, or client transform enforcement. Client-side world selection associates visible objects with saved classnames/positions and caches their references for the editing session. Exactly overlapping objects can be selected individually using the object list; coincident objects from different groups can be visually ambiguous.

Unsaved placement previews are local to the editor. Existing saved objects being edited are concealed locally while their previews are displayed. Other players see the saved server state until Save Group. Cleanup restores saved visuals on save/discard/hide.

Groups are written directly with JsonFileLoader.SaveFile and loaded with JsonFileLoader.LoadFile, following iat_simple_building. File errors are reported through ErrorEx and failed saves also appear in the editor status. No temporary files or automatic backups are created. Every save, rename and group deletion writes the complete groups array to the same file. Other groups remain in that array. Startup creates [] if the file is missing. An unreadable file, invalid group or duplicate group name prevents loading and saving until corrected, with an error in the server log. Missing classes are skipped at startup but remain in the JSON; restore the required mod or remove those entries before saving that group.

Limits remain 2000 entries and 48 KB of compact JSON per group, with scale 0.01-100. Names are checked for duplicates during save, including new groups and renames. There is no concurrent-edit revision protection: the last successful save wins.

The selected class retains its normal scripts. Use functional well/workbench classes for interactions. Inventory, attachments, health and door state are not saved. Building pathgraph updates run after transform changes/deletion. Avoid loading the same placements with another spawner.

No new permissions are registered. Existing COT Entity.View controls the UI; Entity.Spawn.Position and Entity.Delete control save/delete on the server.

## Files and validation

- `IAT_COTObjectEntry.c`: JSON object entry and cloning.
- `IAT_COTObjectGroup.c`: JSON group, owned entries and cloning.
- `IAT_COTObjectRules.c`: object/group validation and limits.
- `IAT_Enums.c`: report categories and RPC enums, including `IAT_COTObjectRPC`.
- `IAT_COTObjectStore.c`: JSON storage, startup spawning and runtime arrays.
- `IAT_COTObjectManagerModule.c`: COT/editor RPCs.
- `IAT_COTObjectManagerForm.c`: editing and previews.
- `JMModuleConstructor.c`: module registration.
- `cot_objectmanager.layout`: UI layout.

The packed mod compiles in the installed diagnostic client. Engine-backed tests cover validation/cloning and disabled-group save/rename/delete/reload; see [coverage](tests/README.md) and [review findings](REVIEW.md). Check live group creation/duplicate names, renaming, duplicate entries, numeric scrolling, preview cleanup, repeated saves, enable/disable/delete, and two restarts in game. Verify well/workbench actions, building collision, and position/orientation/scale from another client and a newly connecting client.

The previous `.dayz-autotest/cot_objectmanager/` helpers are absent from this workspace. Use the maintained `dayz-test-harness` and this mod's tests addon.
