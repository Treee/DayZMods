# Powered Radio Towers

# 🎮 Player Actions

## Flip Switch

-   Interact with the console to toggle its power state.
-   Server/Relay/CPU switches only function if Power is ON.
-   Power switch only becomes available if:
    -   The global power grid has enough charge.
    -   Or, no grid exists (always available).

## Turn Dial

-   Adjusts the auto-shutdown timer (0–7 restarts) before the console deactivates on restart.

# 🧱 Console Entity Details

-   Class Name: StaticObj_iat_wallconsole
-   Scope: 1 (auto-spawned via object builder)
-   Map Support: Defaults configured for Bitterroot
-   Networking: Console state is synced once from the server on creation

# 📡 Radio Tower Console Configuration

This system allows server admins to configure and control radio tower consoles via JSON. It includes customizable power settings, broadcast features, and shutdown timers, all manageable through in-game actions.

---

## 🔧 JSON Configuration

Define tower consoles in a `json` file with the following structure:

### 🔢 Configurable Fields

-   m_ConsoleId: Unique ID for retrieving the console
-   m_IsPoweredOn: 1 = ON, 0 = OFF
-   m_IsCPUOn: 1 = ON (Cipher Tech)
-   m_IsServerConnected: 1 = ON (PDA Messages)
-   m_IsRelayConnected: 1 = ON (IC/Discord Messages)
-   m_DialSetting: Range 0–7 (Auto shutoff countdown)
-   m_ConsolePosition: Console spawn coordinates

m_ConsoleOrientation: Console orientation in world

m_NumRestartsLeft: Initial value synced with dial

```json
{
    "m_TowerConsoleData": [
        {
            "m_ConsoleId": 0,
            "m_IsPoweredOn": 1,
            "m_IsCPUOn": 1,
            "m_IsServerConnected": 1,
            "m_IsRelayConnected": 1,
            "m_DialSetting": 6,
            "m_ConsolePosition": [6407.31982421875, 1192.0, 8926.4404296875],
            "m_ConsoleOrientation": [-155.99989318847657, 0.0, 0.0],
            "m_NumRestartsLeft": 6
        }
    ]
}
```

# Attribution

-   "Wall Console" (https://skfb.ly/6TQ8L) by LuddePudde is licensed under Creative Commons Attribution (http://creativecommons.org/licenses/by/4.0/).
