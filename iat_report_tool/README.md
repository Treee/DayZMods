# Report Tool

Press F7 (configurable in controls) to open the report menu. Reports include the player's Steam identity, location, heading and timestamp; an optional Discord username can be supplied. Automatic chat-filter and VOIP-mute reports use the same server pipeline.

The mod requires Community Framework, Community Online Tools, Admirals Chat Filter and WesternZ VOIP Mute, as configured in the scripts addon. There is no report cooldown. Required RPC fields and categories are validated; older clients may omit the optional trailing Discord name.

## Tests

The mod includes 33 engine-backed behavior cases in its tests addon. See [test coverage and run instructions](tests/README.md) and the [comprehensive review and evidence](REVIEW.md).

## COT integration

Configure report webhook destinations and enabled connections in Community Online Tools. The Report Tool no longer creates or reads ItsATreeMods/ReportToolConfig.json. Existing copies of that legacy file are ignored and can be removed.

Terrain reports automatically add a TRPT entry to COT's IAT Terrain Reports category when its teleport module is available and loaded.

All COT Discord messages retain this mod's plain-text conversion, disabled automatic mentions and suppressed link previews. Webhook destinations remain managed by COT.

The bundled [COT object manager](cot_OBJECT_MANAGER.md) stores and edits groups of scope 1 objects. Its remaining interactive, network and restart checks are listed in the review.

## Localization

Localization assets are in `languagecore`; the layouts also contain hardcoded English text. Translation maintenance uses [dayz-stringtable](https://github.com/WoozyMasta/dayz-stringtable).
