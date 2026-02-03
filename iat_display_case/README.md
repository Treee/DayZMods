# IAT Display Case

- Adds a placeable, lockable display case for safely showcasing items on your base.

## Usage

As a server owner you can add the kits for default display cases into your loot pool. A types.xml is provided with reasonable defaults that you should change to fit your server as needed.

### How To

- Use a kit to deploy a display case by bringing the kit to your hands and placing the object via the provided action.
- By default the display case is locked, however, you can drag an item into the cargo regardless of locked or not.
- To dismantle a display case, make sure it is empty and unlocked. use a screwdriver, pliers, or hammer.

## config.cpp Properties

For those that want to make their own display case models, there are a few properties on the base class (`IAT_DisplayCase_ColorBase`) that you can use to add behavior to your model.

```cs
class IAT_DisplayCase_ColorBase
{
	// ... scope, displayname, etc defined

	/*
	* Should the base of this display case be hidden when something is in the cargo?
	* Useful when you want a clean display of the object.
	*/
	m_IAT_HideDisplayBaseWhenFull = "false";
	/*
	* Is this display case supposed to animate the displayed object? true/false
	* When false, this will ensure no frame/simulation is being added to the display
	*/
	m_IAT_IsAnimated = "false";
	/*
	* Given a full cycle, how much distance does the displayed object travel in one direction.
	* The up/down movement is driven by a Math.Sin(dt * 2Pi * Frequency) curve to ensure the object
	* oscillates in mirrored movement. The amplitude increases/descreases the amount this object
	* swings from Pi to -Pi.
	*/
	m_IAT_BobAmplitude = 0.0;
	/*
	* How large of a step should each movement be? Given the above Sin function, the frequency will influence
	* how often a full cycle will take to complete. Smaller numbers slows the up/down movement and
	* larger numbers speeds up the bob.
	*/
	m_IAT_BobFrequency = 0.0;
	/*
	* How fast should the displayed object rotate per update? Smaller numbers will yield slower rotation
	* while larger numbers will result in faster rotation. Take note that since this is trigonometry
	* 360 degrees is the largest "effective" value you need. Anything higher will just wrap around (mathematically)
	* to the beginning of the circle. Negative numbers will reverse the default direction of the rotation
	*/
	m_IAT_RotationSpeedDegrees = 0.0;
};
```

# Attribution

- "Display Case" (https://skfb.ly/oOAMS) by chronickev is licensed under Creative Commons Attribution (http://creativecommons.org/licenses/by/4.0/).
