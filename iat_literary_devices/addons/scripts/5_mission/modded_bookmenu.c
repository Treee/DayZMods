modded class BookMenu
{
    void ~BookMenu()
    {
        MissionGameplay mission;
        if(Class.CastTo(mission, g_Game.GetMission()))
        {
            mission.RemoveActiveInputExcludes({"menu"}, true);
            mission.GetHud().ShowQuickbarUI(true);
        }
    }

    override void ReadBook(InventoryItem book)
    {
        ItemBook selectedBook;
        if (Class.CastTo(selectedBook, book))
        {
            m_content.LoadFile(selectedBook.GetBookFilePath());
            m_author.SetText(selectedBook.GetBookAuthor());
            m_title.SetText(selectedBook.GetBookTitle());
            m_content_total_height = m_content.GetContentHeight();
            m_content_pos = 0;
            NextPrevPage(false);

            MissionGameplay mission;
            if(Class.CastTo(mission, g_Game.GetMission()))
            {
                mission.AddActiveInputExcludes({"menu"});
                mission.GetHud().ShowQuickbarUI(false);
            }
        }
	}

    override Widget Init()
	{
		layoutRoot = g_Game.GetWorkspace().CreateWidgets("iat_literary_devices/gui/iat_bookmenu.layout");
		Class.CastTo(m_content, layoutRoot.FindAnyWidget("HtmlWidget"));
		Class.CastTo(m_author, layoutRoot.FindAnyWidget("Author"));
		Class.CastTo(m_title, layoutRoot.FindAnyWidget("Title"));
		Class.CastTo(m_page, layoutRoot.FindAnyWidget("Page"));

		float width;
		m_content.GetScreenSize(width, m_page_height);
		return layoutRoot;
	}
};