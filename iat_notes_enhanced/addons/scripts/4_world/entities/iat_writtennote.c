modded class Paper
{
    override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionReadPaper);
	}
    void SetWrittenNoteInitInfo(ItemBase pen = null, ItemBase paper = null)
    {
        // try using "this" for the paper
        GetWrittenNoteData().InitNoteInfo(pen, paper);
        // Print("setting written note info " + pen.GetType() + " " + paper.GetType());
    }
};

modded class Pen_ColorBase
{
    protected string m_WritingColor;

	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionWritePaper);
	}

    string GetPenWritingColor()
    {
        if (!m_WritingColor)
            m_WritingColor = ConfigGetString("writingColor");
        if (m_WritingColor == "")
            m_WritingColor = "#000000";

        return m_WritingColor;
    }
    void SetPenWritingColor(string color)
    {
        m_WritingColor = color;
    }
};