class IAT_LiteraryDevices_Book_Colorbase extends ItemBook
{
    override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionReadBook);
	}
};
class IAT_LiteraryDevices_Scroll_Colorbase extends ItemBook
{
    override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionReadBook);
	}
};

//=============================== VARIABLE ATTACHED BOOK LISTS
class IAT_LiteraryDevices_MultiBook_Colorbase extends ItemBook
{
    protected ref array<string> m_BooksInArchive;
//========================================= EVENTS
    override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionSelectReadBook);
	}
	override void EEItemAttached( EntityAI item, string slot_name )
	{
        super.EEItemAttached( item, slot_name );
        GetBooksFromSlots();
	}
	override void EEItemDetached( EntityAI item, string slot_name )
	{
        super.EEItemDetached( item, slot_name );
        GetBooksFromSlots();
    }
    override void InitItemVariables()
	{
        super.InitItemVariables();
        IAT_InitItemVariables();
    };
//========================================= CUSTOM STUFF
    void IAT_InitItemVariables()
    {
        // Print("Initing item: " + GetType());
        m_BooksInArchive = new array<string>;
    }
    void GetBooksFromSlots()
    {
        m_BooksInArchive.Clear();

        ItemBook attachment;
        int totalSlots = GetInventory().AttachmentCount();
        for (int i = 0; i < totalSlots; i++)
        {
            // Print("Sending: index " + i + " with max " + totalSlots);
            if (Class.CastTo(attachment, GetInventory().GetAttachmentFromIndex(i)))
            {
                m_BooksInArchive.Insert(attachment.GetType());
            }
        }
    }
    TStringArray GetBooksInArchive()
    {
        return m_BooksInArchive;
    }
    bool HasSelectableBooks()
    {
        return m_BooksInArchive.Count() > 0;
    }
    string GetBookTitleByIndex(int index)
    {
        // short circuit not working for some reason. probly move to book name array that is lazy loaded
        // short circuit the last book checked so we are not scraping the config each frame
        // if (m_LastIndex == index)
        //   return m_LastBookTitle;
        // if this thing has books, check for valid index
        if (HasSelectableBooks() && m_BooksInArchive.IsValidIndex(index))
        {
            string bookName = m_BooksInArchive.Get(index);
            // scrape the config
            string title = "";
            GetGame().ConfigGetText(string.Format("CfgVehicles %1 %2", bookName, "title"), title);
            // m_LastIndex = index;
            // m_LastBookTitle = title;
            // Print("Scraping the config for book title: " + m_LastBookTitle + " index: " + index);
            return title;
        }
        return "";
    }
    string GetBookClassByIndex(int index)
    {
        // if this thing has books, check for valid index
        if (HasSelectableBooks() && m_BooksInArchive.IsValidIndex(index))
        {
            return m_BooksInArchive.Get(index);
        }
        return "";
    }
    void SetBookByIndex(int index)
    {
        string bookName = GetBookClassByIndex(index);

        string title = "";
        GetGame().ConfigGetText(string.Format("CfgVehicles %1 title", bookName), title);
        SetBookTitle(title);

        string author = "";
        GetGame().ConfigGetText(string.Format("CfgVehicles %1 author", bookName), author);
        SetBookAuthor(author);

        string file = "";
        GetGame().ConfigGetText(string.Format("CfgVehicles %1 file", bookName), file);
        SetBookFilePath(file);
        // Print(string.Format("Title: %1 Author: %2 File: %3 Book: %4", title, author, file, bookName))
    }
    int GetReadableBooksCount()
    {
        return m_BooksInArchive.Count();
    }
};

//=============================== PREDEFINED BOOK LISTS
class IAT_LiteraryDevices_MultiBookTablet_Colorbase extends IAT_LiteraryDevices_MultiBook_Colorbase
{
//========================================= EVENTS
	override bool HasFlammableMaterial()
	{
		return false;
	}
	override bool CanBeIgnitedBy( EntityAI igniter = NULL )
	{
		return false;
	}
	override bool CanIgniteItem( EntityAI ignite_target = NULL )
	{
		return false;
	}
	override void OnIgnitedTarget( EntityAI ignited_item ){}
	override void OnIgnitedThis( EntityAI fire_source ){}
	override bool IsThisIgnitionSuccessful( EntityAI item_source = NULL )
	{
		return false;
	}
//========================================= CUSTOM
    override void IAT_InitItemVariables()
    {
        super.IAT_InitItemVariables();

        if (ConfigIsExisting("booksInArchive"))
        {
            ConfigGetTextArray("booksInArchive", m_BooksInArchive);
        }
    }
    override void GetBooksFromSlots(){}
};
class IAT_LiteraryDevices_HandHeldTablet_Colorbase extends IAT_LiteraryDevices_MultiBookTablet_Colorbase{};

