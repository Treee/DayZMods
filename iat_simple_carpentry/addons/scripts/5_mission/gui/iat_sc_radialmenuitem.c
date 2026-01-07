class IAT_SC_RadialMenuItem
{
	protected int 					m_ID;
	protected string 				m_Name;
	protected IAT_SC_RadialMenuCategories 	m_Category;
	//radial menu
	protected Widget 				m_RadialMenuSelector;
	protected Widget				m_RadialMenuItemCard;

	void IAT_SC_RadialMenuItem(int id, string name, IAT_SC_RadialMenuCategories category)
	{
		m_ID				= id;
		m_Name 				= name;
		m_Category 			= category;
	}

	string GetName()
	{
		return m_Name;
	}
	int GetID()
	{
		return m_ID;
	}

	IAT_SC_RadialMenuCategories GetCategory()
	{
		return m_Category;
	}

	Widget GetRadialItemCard()
	{
		return m_RadialMenuItemCard;
	}

	void SetRadialItemCard( Widget widget )
	{
		m_RadialMenuItemCard = widget;
	}
};