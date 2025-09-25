modded class DayZGame
{
	private bool m_IAT_SIS_IsLeftShiftDown = false;

    bool IAT_SIS_IsLeftShiftDown()
    {
        return m_IAT_SIS_IsLeftShiftDown;
    }
    override void OnKeyPress(int key)
    {
        if (key == KeyCode.KC_LSHIFT)
        {
            m_IAT_SIS_IsLeftShiftDown = true;
        }
        super.OnKeyPress(key);
    }
    override void OnKeyRelease(int key)
    {
        if (key == KeyCode.KC_LSHIFT)
        {
            m_IAT_SIS_IsLeftShiftDown = false;
        }
        super.OnKeyRelease(key);
    }
};