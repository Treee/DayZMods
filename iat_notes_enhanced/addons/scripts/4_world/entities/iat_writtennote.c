modded class WrittenNoteData
{
    override void SetNoteText(string text)
	{
        super.SetNoteText(text);
        // if paper exists and is not empty
        Paper paper;
        if (Class.CastTo(paper, m_Paper) && m_SimpleText != "")
        {
            paper.SetHasWrittenText(true);
            paper.SetSynchDirty();
        }
	}
};

modded class Paper
{
    protected bool m_HasWrittenText = false;

    void Paper()
    {
        RegisterNetSyncVariableBool("m_HasWrittenText");
    }

    override void DeferredInit()
	{
        super.DeferredInit();
        UpdateVisualState();
    }

    override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionReadPaper);
	}

    override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

        if (!GetGame().IsDedicatedServer())
        {
            // update client side texture
            UpdateVisualState();
        }
	}

    override string GetDisplayName()
	{
        string itemName = super.GetDisplayName();
        if (GetHasWrittenText())
        {
            itemName = string.Format("%1 with Text", itemName);
        }
		return itemName;
	}

    override void AfterStoreLoad()
	{
		super.AfterStoreLoad();

        if (GetGame().IsDedicatedServer())
        {
            if (GetWrittenNoteData() && GetWrittenNoteData().GetNoteText() != "")
            {
                SetHasWrittenText(true);
                SetSynchDirty();
            }
        }
	}

    void SetHasWrittenText(bool newState)
    {
        m_HasWrittenText = newState;
    }
    bool GetHasWrittenText()
    {
        return m_HasWrittenText;
    }

    void SetWrittenNoteInitInfo(ItemBase pen = null, ItemBase paper = null)
    {
        GetWrittenNoteData().InitNoteInfo(pen, paper);
    }
    void UpdateVisualState()
    {
        int selectionIdx = GetHiddenSelectionIndex("zbytek");
        if (GetHasWrittenText())
        {
            SetObjectTexture(selectionIdx, "iat_notes_enhanced\\consumables\\data\\iat_paper_written_co.paa");
        }
        else
        {
            SetObjectTexture(selectionIdx, "DZ\\gear\\consumables\\data\\loot_paper_co.paa");
        }
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