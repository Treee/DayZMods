modded class ItemBase
{
    protected string m_BookTitle;
    protected string m_BookAuthor;
    protected string m_BookFilePath;

    string GetBookTitle()
    {
        if (!m_BookTitle)
        {
            if (ConfigIsExisting("title"))
            {
                SetBookTitle(ConfigGetString("title"));
            }
        }
        // Print(string.Format("Getting Book Title: %1", m_BookTitle));
        return m_BookTitle;
    }
    void SetBookTitle(string title)
    {
        m_BookTitle = title;
    }

    string GetBookAuthor()
    {
        if (!m_BookAuthor)
        {
            if (ConfigIsExisting("author"))
            {
                SetBookAuthor(ConfigGetString("author"));
            }
        }
        // Print(string.Format("Getting Book Author: %1", m_BookAuthor));
        return m_BookAuthor;
    }
    void SetBookAuthor(string author)
    {
        m_BookAuthor = author;
    }

    string GetBookFilePath()
    {
        if (!m_BookFilePath)
        {
            if (ConfigIsExisting("file"))
            {
                SetBookFilePath(ConfigGetString("file"));
            }
        }
        // Print(string.Format("Getting Book FIlepath: %1", m_BookFilePath));
        return m_BookFilePath;
    }
    void SetBookFilePath(string path)
    {
        m_BookFilePath = path;
    }
};