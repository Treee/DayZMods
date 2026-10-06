# Report Tool behavior tests

The tests addon contains 33 cases using the workspace's frame-driven DayZ harness. Assertions call real packed classes. Added cases cover Discord serialization, object rules/storage, the m_-named object JSON contract and report RPC behavior. See [review evidence](../REVIEW.md) for the green refactor checkpoints, mutation detection and red-green cycles.

Run from the workspace root in the Windows context that can access P: and the configured tools:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\dayz-test-harness\run.ps1 -Mod 'P:\iat_report_tool' -HashArtifacts
```

For one case, add `-Test TerrainSubmissionEmitsLocation` (or another registered name). The runner builds `scripts`, `languagecore`, and `tests` from this mod into `P:/Mods/@IAT_ReportTool`, then loads it with local WesternZ VOIP Mute and Workshop CF, COT, and Admirals Chat Filter dependencies. It uses the builder's saved build options, including signing. Dependency paths are in `dayz-tests.json`; machine paths remain in the harness configuration. Both diagnostic and harness defines guard test scripts; the harness is not a mandatory addon dependency.

## Behavior-to-test map

| Existing behavior | Registered cases | Evidence boundary |
| --- | --- | --- |
| Construction preserves report fields and optional embed/Discord arguments | `ReportFieldsWithDefaultOptions`, `ReportFieldsWithExplicitOptions` | Real `IAT_ReportData` constructor and public fields/getters |
| Declared categories display their enum names; only terrain is a terrain report | `TerrainCategory`, `BugCategory`, `SuggestionCategory`, `PlayerMuteCategory`, `BadWordCategory`, `ExploitCategory`, `PlayerCategory`, `NoSelectionCategory` | Real report-data classification; category alone does not set the embed flag |
| Out-of-range categories use the fallback label and are not terrain | `NegativeUnknownCategory`, `AboveRangeUnknownCategory` | Values -1 and 8, immediately outside the declared enum range |
| Steam links use the supplied name/ID; Discord full-date markup uses Unix time independently of UTC text | `StandardLinkAndTimestamp`, `AlternateLinkAndEpochTimestamp`, `EmptyLinkAndNegativeTimestamp` | Exact strings; distinct identities, epoch zero, negative time, empty identity inputs |
| Submission delegates the same report once and emits one TRPT terrain location | `TerrainSubmissionEmitsLocation` | Real public `SubmitReport`, recording delivery double, real location event |
| Non-terrain categories emit no location | `BugSubmissionHasNoTerrainLocation`, `UnknownSubmissionHasNoTerrainLocation` | Same boundary with category alternatives |
| The legacy Report Tool config class is no longer loaded | `LegacyConfigTypeRemoved` | Runtime typename lookup in the packed mod |
| Plain Discord JSON escapes text, disables automatic mentions and suppresses previews | `DiscordTextJSONEscaping` | Real `JMWebhookDiscordMessage.Prepare`; short payload decoded independently |
| Multiple embeds/fields flatten in order; null and empty entries are skipped | `DiscordEmbedFlattening` | Exact resulting text, including newline normalization and spacing |
| 1900 characters remain intact; 1901 characters trigger the existing suffix | `DiscordExactTruncationBoundary`, `DiscordAboveTruncationBoundary` | Exact serialized ASCII wire value; native decoding clipped long fixture strings at 1023 characters in the installed build |
| Names, numeric and object-count boundaries are enforced; clones isolate changes | `ObjectValidationAndClone` | Real public rules and DTOs; 80/81-character names, minimum/maximum scale, position/orientation limits, 2000/2001 entries, null/missing classes |
| Save/rename/delete/reload preserve order, uniqueness and other groups | `ObjectStoreSaveRenameDeleteReload` | Real JSON I/O in per-run profile; disabled groups, no live spawning |
| Object-group JSON uses the m_-named schema for every field | `ObjectPayloadUsesMemberNames` | Independent schema reader checks all seven fields and omission of former keys; storage case also reloads a disabled group's object transform |
| Consecutive decoded reports are submitted without a cooldown | `RPCConsecutiveReportsWithoutCooldown` | Real `OnRPC` and submission; identity enrichment and external delivery replaced by recording doubles |
| Legacy optional fields, Discord normalization and 64-character bound are preserved | `RPCLegacyTwoFieldReport`, `RPCDiscordNameLengthLimit` | Real native read/write context and decoder; exact forwarded values |
| Missing descriptions and unknown/unselected categories do not reach enrichment | `RPCMissingDescriptionRejected`, `RPCUnknownCategoryRejected`, `RPCNoSelectionRejected` | Malformed/invalid packets rejected through real `OnRPC` |
| Missing identity/report produces no delivery | `AbsentSenderAndReportHaveNoDelivery` | Real identity absence handling, public submission and senderless RPC; only delivery is replaced |

Empty identities and negative Unix-time cases record current formatting behavior. Terrain entries always use TRPT; webhook enablement and destinations are configured in COT.

## Isolation and limits

Submission cases use a recording server and remove their location event listener in cleanup. Tests do not expose protected production helpers or replace game configuration. The config-removal case verifies that the obsolete class is absent from the loaded scripts; it does not establish live webhook delivery.

These tests prove in-process RPC decoding/normalization, but not multiplayer transport or connected identity enrichment. They do not prove live webhook delivery, COT connection enablement, teleport persistence, UI/input routing, multiplayer or dedicated-server behavior. Object rules and disabled-group JSON storage are covered; live spawning, collision, previews and replication require separate checks. Menu fixture attempts hit compiler/native failures and were excluded rather than weakening harness verification. No production callbacks or helpers were made public for tests.

