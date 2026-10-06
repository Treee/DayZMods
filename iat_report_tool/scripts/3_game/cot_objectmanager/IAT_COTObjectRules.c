class IAT_COTObjectRules
{
	static const int MAX_NAME_LENGTH = 80;
	static const int MAX_OBJECTS = 2000;
	static const int MAX_PAYLOAD_LENGTH = 48000;
	static const float MIN_SCALE = 0.01;
	static const float MAX_SCALE = 100.0;
	static const float MAX_POSITION_COMPONENT = 1000000.0;
	static const float MAX_ORIENTATION_COMPONENT = 360000.0;

	static string NameKey(string name)
	{
		name.TrimInPlace();
		name.ToLower();
		return name;
	}

	static bool ValidName(string name)
	{
		return name.Length() >= 1 && name.Length() <= MAX_NAME_LENGTH && NameKey(name) != "";
	}

	static bool ValidNumber(float value, float limit)
	{
		return value >= -limit && value <= limit;
	}

	static bool ValidClass(string type)
	{
		string path = "CfgVehicles " + type;
		return type != "" && g_Game.ConfigIsExisting(path) && g_Game.ConfigGetInt(path + " scope") == 1;
	}

	static bool Validate(IAT_COTObjectGroup group, out string error, bool requireClasses = true)
	{
		if (!group || !group.m_Objects)
		{
			error = "Invalid group data.";
			return false;
		}
		group.m_Name.TrimInPlace();
		if (!ValidName(group.m_Name) || group.m_Objects.Count() > MAX_OBJECTS)
		{
			error = "Use a non-empty group name of at most 80 characters; maximum 2000 objects.";
			return false;
		}
		array<ref IAT_COTObjectEntry> entries = group.m_Objects;
		foreach (IAT_COTObjectEntry entry : entries)
		{
			if (!entry || entry.m_Scale < MIN_SCALE || !ValidNumber(entry.m_Scale, MAX_SCALE))
			{
				error = "Invalid object or scale (allowed range 0.01-100).";
				return false;
			}
			for (int axis = 0; axis < 3; axis++)
			{
				if (!ValidNumber(entry.m_Position[axis], MAX_POSITION_COMPONENT) || !ValidNumber(entry.m_Orientation[axis], MAX_ORIENTATION_COMPONENT))
				{
					error = "Invalid position or orientation.";
					return false;
				}
			}
			if (requireClasses && !ValidClass(entry.m_ClassName))
			{
				error = "Unavailable scope 1 class: " + entry.m_ClassName;
				return false;
			}
		}
		return true;
	}
}
