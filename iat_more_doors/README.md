# IAT More Doors Mod

**IAT More Doors** expands DayZ's building options with an extensive collection of door types and materials. This mod provides both construction doors for player base building and land doors for map integration, featuring multiple materials and configurations to suit any building project.

## Features

### 🚪 Door Material Types

-   **Wood**
-   **Metal**
-   **Iron**

### 🚪 Door Opening Directions

-   **Left Swing**
-   **Right Swing**

### 🚪 Door Types

-   **Single Door**
-   **Double Door**

### 🔨 Construction System

#### **Player-Craftable Doors**

-   **Construction Door Kits**: Craftable door components for base building; [70x Nail + 10x WoodenPlank]
-   **Material Variants**: Choose from wooden, metal, or iron materials
-   **Flexible Placement**: Single and double door configurations for any opening
-   **Interactive Operation**: Smooth door opening/closing with realistic animations

#### **Land Doors (Map Integration)**

-   **Map-Ready Assets**: Doors designed for terrain integration
-   **Proper Collision**: Full collision detection and navigation mesh carving
-   **Realistic Properties**: Appropriate weight, size, and physical characteristics
-   **Texture Variants**: Multiple visual styles for different environments

### 🔒 Security Integration

#### **Codelock Compatibility**

-   **IAT Codelock Support**: Full integration with IAT Codelock system
-   **Vanilla Codelock Support**: Compatible with standard DayZ combination locks
-   **Attachment Slots**: Dedicated combination lock attachment points

### 🎮 User Experience

#### **Realistic Interactions**

-   **Sound Effects**: Material-appropriate door sounds (wood, metal, iron)
-   **Visual Feedback**: Clear open/closed states with smooth animations
-   **Intuitive Controls**: Standard DayZ interaction system

#### **Building Integration**

-   **Modular Design**: Doors integrate seamlessly with existing base building
-   **Standard Sizing**: Compatible with common door frame dimensions
-   **Damage System**: Realistic damage zones and destruction mechanics
-   **Inventory Management**: Appropriate item sizes and cargo restrictions

## Usage

### Crafting Construction Doors

#### Materials Needed

-   **Nails 70x**
-   **WoodenPlank 10x**

#### Building Process

1. **Gather Materials**: Collect the required crafting components
2. **Access Crafting Menu**: Use the crafting system to create door kits
3. **Choose Configuration**: Select single or double door variant
4. **Place Door**: Position the door in your desired location
5. **Secure Access**: Attach codelocks for security (optional)

### Using Land Doors (Map Makers)

#### Integration Steps

1. **Select Door Type**: Choose appropriate material and configuration
2. **Position on Terrain**: Place doors using map editing tools
3. **Test Functionality**: Verify door operation and collision detection

## Installation

1. Add mod to server startup
2. Start the server

**Note**: This mod requires both server and client installation for full functionality. All players must have the mod installed to see and interact with the custom doors.

## Types

### Land Doors (Map placed)

```
land_iat_singledoor_left_wooden
land_iat_singledoor_right_wooden
land_iat_singledoor_left_metal
land_iat_singledoor_right_metal
land_iat_singledoor_left_iron
land_iat_singledoor_right_iron
land_iat_doubledoor_wooden
land_iat_doubledoor_metal
land_iat_doubledoor_iron
```

### Kits

```
IAT_MoreDoor_Kit
```

### Construction Doors (Player created)

```
IAT_ConstructionDoor_Single_Left_Wooden
IAT_ConstructionDoor_Single_Right_Wooden
IAT_ConstructionDoor_Single_Left_Metal
IAT_ConstructionDoor_Single_Right_Metal
IAT_ConstructionDoor_Single_Left_Iron
IAT_ConstructionDoor_Single_Right_Iron
IAT_ConstructionDoor_Double_Wooden
IAT_ConstructionDoor_Double_Metal
IAT_ConstructionDoor_Double_Iron
```

### Vanilla digital code lock (DayZ 1.30)

Construction and land doors support `DigitalCodeLock` in `Att_CodeLock`.
Insert a charged 9V battery before or after attaching the lock. Look at the
panel or frame from the keypad side to use **Set Code** or **Enter Code**.
With a PIN configured and the lock unlocked, use **Reset Code** to choose a
replacement PIN, or **Lock** to lock it again. The physical back side offers
release when the lock is locked; it does not offer PIN setting or reset.

`IAT_ActionInteractDoorCodeLock` and `IAT_ActionResetDoorCodeLock` are separate
IAT actions, explicitly registered in each door family's `SetActions()`.
They keep the door as the action target and resolve its attached lock inside
their own callbacks. The lock and operation captured during setup are checked
again on the server, including physical side, power and current lock state.
The existing vanilla PIN UI and lock component handle code entry and storage.

Vanilla lock actions, including their `Can` and `SetupAction` methods, are not
modified. Direct lock targeting continues to use vanilla actions. A mod that
changes the digital lock's methods can still affect the underlying lock;
changes made only to vanilla action callbacks do not automatically apply to
these separate IAT door actions. Door subclasses inherit the registrations
when they retain `super.SetActions()`.

A locked digital lock prevents either construction-door leaf from opening.
An attached digital lock also prevents dismantling the construction door.
Existing IAT and older combination-lock support remains in place.

See [digital lock test notes](tests/README.md) for component coverage and the
remaining in-game checks.
