class IAT_NoteVariantActionReciveData extends ActionReciveData
{
  	int m_IATNoteVariant;
}
class IAT_NoteVariantActionData extends ActionData
{
  	int m_IATNoteVariant;
};


class IAT_ActionSelectReadNoteCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		EnableStateChangeCallback();
		m_ActionData.m_ActionComponent = new CAContinuousTime(-1.0);
	}

	override void EndActionComponent(){}

	override void OnStateChange(int pOldState, int pCurrentState)
	{
		if (pCurrentState == STATE_NONE && (!GetGame().IsDedicatedServer()))
		{
			if (GetGame().GetUIManager() && GetGame().GetUIManager().IsMenuOpen(MENU_NOTE))
				GetGame().GetUIManager().FindMenu(MENU_NOTE).Close();
		}
		else if (pCurrentState == STATE_LOOP_LOOP && pOldState != STATE_LOOP_LOOP && (!GetGame().IsMultiplayer() || GetGame().IsServer()))
		{
            IAT_LiteraryDevices_Notebook_ColorBase multiSelectNote;
            if (Class.CastTo(multiSelectNote, m_ActionData.m_MainItem))
            {
                if (multiSelectNote.HasSelectableNotes())
                {
                    int variantId = IAT_NoteVariantActionData.Cast(m_ActionData).m_IATNoteVariant;
                    if (multiSelectNote.HasSelectableNote(variantId))
                    {
                        Paper paper;
                        if (Class.CastTo(paper, multiSelectNote.GetAttachedPaper(variantId)))
                        {
                            Param1<string> text = new Param1<string>(paper.GetWrittenNoteData().GetNoteText());
                            paper.RPCSingleParam(ERPCs.RPC_READ_NOTE, text, true, m_ActionData.m_Player.GetIdentity());
                        }
                    }
                }
            }
		}
	}
};

class IAT_ActionSelectReadNote extends ActionContinuousBase
{
	void IAT_ActionSelectReadNote()
	{
		m_CallbackClass = IAT_ActionSelectReadNoteCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_VIEWNOTE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_PRONE;
		m_Text = "#read";
        if (!GetGame().IsDedicatedServer())
        {
            GetVariantManager().GetOnUpdateInvoker().Insert(OnUpdateActions);
        }
	}
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
    override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
        IAT_LiteraryDevices_Notebook_ColorBase multiSelectNote;
        if (Class.CastTo(multiSelectNote, item))
        {
            if (multiSelectNote.HasSelectableNotes())
            {
                if (multiSelectNote.HasSelectableNote(m_VariantID))
                {
                    int formattedIndex = m_VariantID + 1;
                    m_Text = string.Format("Read - Note: %1", formattedIndex);
                }
                else
                {
                    m_Text = "Empty Slot";
                }
            }
        }
	}
	override bool HasTarget()
	{
		return false;
	}
    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        IAT_LiteraryDevices_Notebook_ColorBase multiSelectNote;
        if (Class.CastTo(multiSelectNote, item))
        {
            if (multiSelectNote.HasSelectableNotes())
            {
                if (multiSelectNote.HasSelectableNote(m_VariantID))
                {
                    return true;
                }
            }
        }
		return false;
	}
    override void OnUpdate(ActionData action_data)
	{
		super.OnUpdate(action_data);

		if(!GetGame().IsDedicatedServer())
		{
			if (action_data.m_State == UA_FINISHED && GetGame().GetUIManager() && !GetGame().GetUIManager().IsMenuOpen(MENU_NOTE))
			{
				ActionManagerClient.Cast(action_data.m_Player.GetActionManager()).RequestEndAction();
			}
		}
	}
	override void OnEndRequest(ActionData action_data)
	{
		if (action_data.m_Callback)
		{
			action_data.m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_INTERRUPT);
		}
	}

    override ActionData CreateActionData()
	{
		IAT_NoteVariantActionData action_data = new IAT_NoteVariantActionData;
		return action_data;
	}
    override bool SetupAction( PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL )
	{
		if ( super.SetupAction( player, target, item, action_data, extra_data ) )
		{
			if ( !GetGame().IsDedicatedServer() )
			{
				IAT_NoteVariantActionData.Cast(action_data).m_IATNoteVariant = m_VariantID;
			}
			return true;
		}
		return false;
	}
	override void WriteToContext(ParamsWriteContext ctx, ActionData action_data)
	{
		super.WriteToContext(ctx, action_data);
		ctx.Write(IAT_NoteVariantActionData.Cast(action_data).m_IATNoteVariant);
	}
	override bool ReadFromContext(ParamsReadContext ctx, out ActionReciveData action_recive_data )
	{
		action_recive_data = new IAT_NoteVariantActionReciveData;
		super.ReadFromContext(ctx, action_recive_data);

		int variantId;
		if ( ctx.Read(variantId) )
		{
			IAT_NoteVariantActionReciveData.Cast( action_recive_data ).m_IATNoteVariant = variantId;
			return true;
		}
		else
		{
			return false;
		}
	}
	override void HandleReciveData(ActionReciveData action_recive_data, ActionData action_data)
	{
		super.HandleReciveData(action_recive_data, action_data);
		IAT_NoteVariantActionData.Cast(action_data).m_IATNoteVariant = IAT_NoteVariantActionReciveData.Cast( action_recive_data ).m_IATNoteVariant;
	}

    void OnUpdateActions( Object item, Object target, int component_index )
	{
        IAT_LiteraryDevices_Notebook_ColorBase multiSelectNote;
        if (Class.CastTo(multiSelectNote, item))
        {
            if (multiSelectNote.HasSelectableNotes())
                GetVariantManager().SetActionVariantCount(multiSelectNote.GetReadableNotesCount());
        }
        else
            GetVariantManager().Clear();
	}
};
