# IAT Codelock Mod

A comprehensive codelock system for DayZ that provides secure access control for containers, doors, and other items with a combination lock slot.

**IAT Codelock** is a thoughtfully designed alternative to traditional codelock systems in DayZ. Built to seamlessly integrate with existing gameplay and community standards, this mod offers a modern take on base access control without disrupting how players already use codelocks. This mod is meant to replace or supplement the existing Codelock mod that servers are using.

## Features

### 🔒 Core Security

-   **Password Protection**: Secure passcode system with show/hide toggle. Allows text and is case sensitive
-   **Steam ID Whitelist**: Owner-based access control with ability to add trusted players via passcode entry
-   **Attachment Security**: Prevents unauthorized removal when locked
-   **Auto-Reset**: Automatically clears settings when detached for security
-   **Configurable Raid Tools**: Json server settings to define what items can be used to raid and how long they take to destroy the lock

### 🎮 User Interface

-   **Intuitive Dialogs**: Clean, user-friendly password entry and management interfaces
-   **Management Panel**: Easy access to lock toggle and passcode changes.
-   **Visual Feedback**: Clear indicators for locked/unlocked states
-   **Accessibility**: Show/hide password option for secure entry

### ⚙️ Technical Features

-   **Invulnerability System**: Configurable damage protection (disableBaseBuildingDamage in cfgGameplay.json)
-   **Event System**: Script invokers for UI updates and state changes
-   **Network Optimization**: Efficient synchronization with signal-based updates
-   **Modular Design**: Easy integration with existing mod setups. Can run with existing codelock mods

## Usage

### Setting Up a Codelock

1. Bring a codelock into your players hands
2. Target a fence with gate or a tent
3. Attach the codelock

### Managing Access

#### Change Passcode

Update your security code anytime

1. Target a fence with gate or a tent
2. Hold [F] to **Manage Codelock**
3. Enter your password
4. Click **Change Password**
5. Click **Ok** to confirm

`Note - Changing a password will clear any whitelisted ids currently on the lock and flag to the lock permissions need to be synced for other clients.`

#### Adding Players

Add players to your locks whitelist

1. Target a fence with gate or a tent
2. Hold [F] to **Interact with Codelock**
3. Enter the password
4. The doors open prompt should now be available

`Note - The server owner can configure maximum amount of failure attempts, the time it takes for failed attempts to degenerate, and how much damage a player takes on a failed attempt.`

### Unlocking Doors

Allow access to your object by unlocking it for temporary access.

1. Target locked object owned by you
2. Hold [F] to **Manage Codelock**
3. Click **Unlock**
4. Close the dialog menu
5. Observe other players can now open your door

`Note - The codelock is still secure and assigned to you. Make sure to lock the object when you are done providing temporary access.`

### Accessing Locked Containers

If you own the codelock on the container, you will always see its cargo and have the option to bring into your hands (if already allowed).

1. Target a cargo container with a codelock attached
2. Hold [F] to **Interact with Codelock**
3. Enter the password
4. The cargo is now visible to you.

`Note - Failed attempts are treated the same as fences and if configured, will harm the player.`

`Note - If you do not own the lock you will be unable to take the cargo container.`

## Configuration

```json
{
    "m_SaveToDatabase": 1,
    "m_ShowHpOnCodelock": 1,
    "m_CanAttachCodelockToBaseBuilding": 1,
    "m_CanAttachCodelockToTents": 1,
    "m_CanAttachCodelockToContainers": 1,
    "m_DamagePlayerOnFailedPasscodeEntry": 1,
    "m_ClearAllPasscodeEntriesOnInterval": 1,
    "m_DamagePerFailedPasscodeEntry": 20,
    "m_MaxPasscodeEntriesPerInterval": 5,
    "m_MaxPasscodeEntriesCooldown": 600,
    "m_RaidTools": [
        {
            "m_ItemName": "Hacksaw",
            "m_DamagePerUse": 10.0,
            "m_CodelockDamagePerUse": 250,
            "m_TimePerDamage": 20,
            "m_DeleteLockOnRaid": 1
        },
        {
            "m_ItemName": "Crowbar",
            "m_DamagePerUse": 15.0,
            "m_CodelockDamagePerUse": 150,
            "m_TimePerDamage": 60,
            "m_DeleteLockOnRaid": 0
        },
        {
            "m_ItemName": "IAT_RaidHacksaw_Admin",
            "m_DamagePerUse": 0.0,
            "m_CodelockDamagePerUse": 1500,
            "m_TimePerDamage": 2,
            "m_DeleteLockOnRaid": 1
        },
        {
            "m_ItemName": "IAT_RaidHacksaw_Colorbase",
            "m_DamagePerUse": 10.0,
            "m_CodelockDamagePerUse": 250,
            "m_TimePerDamage": 20,
            "m_DeleteLockOnRaid": 1
        }
    ]
}
```

### m_SaveToDatabase

`0 or 1` Flag to the game if codelocks should persist their internal data to CF Mod storage or vanilla DB. Default 1

### m_ShowHpOnCodelock

`0 or 1` Flag to the destroy codelock action if the hp of the codelock should be displayed. If set to false, the hp is no longer synced either to reduce network traffic. Default 1

### m_CanAttachCodelockToBaseBuilding

`0 or 1` Flag to the attach action if base building objects are allowed to have a codelock. This will impact things like Fences or anything that uses a Fence class and `HasHinges() = true`. Default 1

### m_CanAttachCodelockToTents

`0 or 1` Flag to the attach action if tents are allowed to have a codelock. This will impact things like Medium Tents and Large Tents, even Car Tents. Default 1

### m_CanAttachCodelockToContainers

`0 or 1` Flag to the attach action if objects with cargo are allowed to have a codelock. This will impact things like Sea Chests or Wooden Crates. Default 0

### m_DamagePlayerOnFailedPasscodeEntry

`0 - 1` Flag to signal if the player should receive damage on a failed passcode entry attempt. Best practice is to set this always to 1. Default 1

### m_ClearAllPasscodeEntriesOnInterval

`0 or 1` Flag to signal if ALL failed attempts are erased on the cooldown or only the last one. When true, all failed attempts are removed on the interval defined below. When false, the cooldown will run for each failed entry. Default 1

```
Example 1: 5 failed attempts within 30 seconds.

- m_ClearAllPasscodeEntriesOnInterval: 1 (true)
- m_MaxPasscodeEntriesPerInterval: 5 (max attempts)
- m_MaxPasscodeEntriesCooldown: 600 (10 minutes in seconds)

After 10 minutes I will be able to attempt 5 more failed entries.

Example 2: 5 failed attempts within 30 seconds.

- m_ClearAllPasscodeEntriesOnInterval: 0 (false)
- m_MaxPasscodeEntriesPerInterval: 5 (max attempts)
- m_MaxPasscodeEntriesCooldown: 600 (10 minutes in seconds)

After 10 minutes I will be able to attempt 1 failed entries since I still have 4 other attempts that will need to cooldown (for a total of 40 more minutes).
```

This is to help limit spamming codelocks by method of brute forcing which should never be encouraged with this type of codelock. Vanilla locks, fine.

### m_DamagePerFailedPasscodeEntry

`0 - 100` Value to define the damage the player receives on a failed passcode attempt. 100 is the maximum player health so default setting is set to 20 which implies 5 uses before the 6th becomes lethal. You are allowed to configure the damage to be higher than 100 if needed. Default 20

### m_MaxPasscodeEntriesPerInterval

`0 - {x}` Value to define how many failed passcode entry attempts a player can have in a given cooldown window. It is a good practice to keep this number low. Default 5

### m_MaxPasscodeEntriesCooldown

`0 or {x}` Value to define how long the player needs to wait before failed passcode entries are removed. It is good practice to keep this number somewhat high. Value is in seconds. Default 600 (10 minutes)

### m_RaidTools

`jsonObject` A list of raid tools that can be configured by server owners. This allows different tiers of raiding tool to be in circulation and the ability to quickly add/remove/edit a tool on restart.

```json
{
    "m_ItemName": "Hacksaw",
    "m_DamagePerUse": 10.0,
    "m_CodelockDamagePerUse": 250,
    "m_TimePerDamage": 20,
    "m_DeleteLockOnRaid": 1
}
```

#### m_ItemName

`string` The classname of raid item. This can be the exact class name or `inherited` class as seen with `IAT_RaidHacksaw_Colorbase` in the default config. The algorithm for picking raid tool will use the most specific option available to it first so good practice is to leave wider base classes at the bottom of the list.

#### m_DamagePerUse

`0 - {x}` The damage applied to the tool being used to raid. A value of 0 will create an infinite raiding tool.

#### m_CodelockDamagePerUse

`0 - {x}` The damage applied to the codelock on each action. Codelocks normally have 1500 health.

#### m_TimePerDamage

`0 - {x}` The time, in seconds, is how long the continuous action takes to complete before looping again. A value of 0 will effectively create an instant action.

#### m_DeleteLockOnRaid

`0 - 1` The value that flags if the codelock being cut should be destroyed or dropped on the ground.

## Compatibility

-   **Server/Client**: Full multiplayer support
-   **Other Mods**: Compatible with any container/tent/basebuilding mod that adds the `Att_CombinationLock` attachment
-   **CF ModStorage**: Optional integration available

**Note**: This mod requires both server and client installation for full functionality. Ensure all players have the mod installed before joining the
