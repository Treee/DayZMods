# IAT Item Blacklist Mod

Removes configured exact item class names from player inventories on dedicated
server connection and disconnection. Names are case-sensitive; listing a base
class does not blacklist all of its descendants. Server configuration is created
at `$profile:ItsATreeMods/ItemBlacklistConfig.json` with an empty list by default.

## Native annotated tests

The optional `tests` addon contains nine native `[Test]` functions in two suites.
The engine discovers them without an explicit registration list. Build `scripts`
and `tests`, then use the repository's launcher from `dayz-launch`:

```bash
./dayz.sh autotest profiles/item-blacklist
```

See [launcher setup](../dayz-launch/README.md#native-annotated-autotests) for packing
the support addon and example mod. The selected mission is the existing
`vanilla.chernarusplus`, running locally without economy or saved-player access.

Coverage includes an empty blacklist, first/later entries, unlisted names,
case sensitivity, exact names rather than prefixes/inheritance, duplicates,
serialization round trips, missing-file defaults, and existing-file loading.
File fixtures use only `$profile:IAT_Autotest_ItemBlacklist` and remove their
JSON files. No production configuration or public/protected API was changed.

The local cases do not establish dedicated-server initialization, connection and
disconnection callback dispatch, inventory deletion, player identities, or
multiplayer replication. Those paths require separate server-backed verification.
