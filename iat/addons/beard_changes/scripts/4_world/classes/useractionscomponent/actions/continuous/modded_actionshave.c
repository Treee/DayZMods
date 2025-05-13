class IAT_BeardVariantActionReciveData extends ActionReciveData
{
  	string m_IATBeardVariant;
}

class IAT_BeardVariantActionData extends ActionData
{
  	string m_IATBeardVariant;
};

modded class ActionShave
{
	void ActionShave()
	{
		if (!GetGame().IsDedicatedServer())
        {
            GetVariantManager().GetOnUpdateInvoker().Insert(OnUpdateActions);
        }
	}

	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (player.CanShave())
		{
			TStringArray m_BeardTypes = player.GetFacialHairOptions();
			if (m_BeardTypes && m_BeardTypes.Count() > 0)
			{
				if (m_BeardTypes.IsValidIndex(m_VariantID))
					m_Text = string.Format("Shave - %1", m_BeardTypes.Get(m_VariantID));
				else
					m_Text = "Shave - No Beard";
			}
		}
	}

	void OnUpdateActions( Object item, Object target, int component_index )
	{
		PlayerBase player;
		if (Class.CastTo(player, GetGame().GetPlayer()))
		{
			TStringArray m_BeardTypes = player.GetFacialHairOptions();
			if (m_BeardTypes && m_BeardTypes.Count() > 0)
			{
				if (m_BeardTypes.Count() > 0)
					GetVariantManager().SetActionVariantCount(m_BeardTypes.Count());
				else
					GetVariantManager().Clear();
			}
		}
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		super.OnFinishProgressServer(action_data);

		if (action_data.m_Player)
		{
			string newItem = IAT_BeardVariantActionData.Cast(action_data).m_IATBeardVariant;
			GetGame().CreateObjectEx(newItem, action_data.m_Player.GetPosition(), ECE_SETUP|ECE_NOLIFETIME|ECE_DYNAMIC_PERSISTENCY);
		}
	}

	override ActionData CreateActionData()
	{
		IAT_BeardVariantActionData action_data = new IAT_BeardVariantActionData;
		return action_data;
	}

	override bool SetupAction( PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL )
	{
		if ( super.SetupAction( player, target, item, action_data, extra_data ) )
		{
			if ( !GetGame().IsDedicatedServer() )
			{
				TStringArray  m_BeardTypes = player.GetFacialHairClassNames();
				string itemName = m_BeardTypes.Get(m_VariantID);
				IAT_BeardVariantActionData.Cast(action_data).m_IATBeardVariant = itemName;
			}
			return true;
		}
		return false;
	}

	override void WriteToContext(ParamsWriteContext ctx, ActionData action_data)
	{
		super.WriteToContext(ctx, action_data);
		ctx.Write(IAT_BeardVariantActionData.Cast(action_data).m_IATBeardVariant);
	}

	override bool ReadFromContext(ParamsReadContext ctx, out ActionReciveData action_recive_data )
	{
		action_recive_data = new IAT_BeardVariantActionReciveData;
		super.ReadFromContext(ctx, action_recive_data);

		string variantId;
		if ( ctx.Read(variantId) )
		{
			IAT_BeardVariantActionReciveData.Cast( action_recive_data ).m_IATBeardVariant = variantId;
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
		IAT_BeardVariantActionData.Cast(action_data).m_IATBeardVariant = IAT_BeardVariantActionReciveData.Cast( action_recive_data ).m_IATBeardVariant;
	}

};

modded class ActionShaveTarget
{
	void ActionShaveTarget()
	{
		if (!GetGame().IsDedicatedServer())
        {
            GetVariantManager().GetOnUpdateInvoker().Insert(OnUpdateActions);
        }
	}

	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		PlayerBase targetPlayer;
		if (Class.CastTo(targetPlayer,  target.GetObject()))
		{
			if (targetPlayer.CanShave())
			{
				TStringArray m_BeardTypes = targetPlayer.GetFacialHairOptions();
				if (m_BeardTypes && m_BeardTypes.Count() > 0)
				{
					if (m_BeardTypes.IsValidIndex(m_VariantID))
						m_Text = string.Format("Shave - %1", m_BeardTypes.Get(m_VariantID));
					else
						m_Text = "Shave - No Beard";
				}
			}
		}
	}

	void OnUpdateActions( Object item, Object target, int component_index )
	{
		PlayerBase targetPlayer;
		if (Class.CastTo(targetPlayer, target))
		{
			TStringArray m_BeardTypes = targetPlayer.GetFacialHairOptions();
			if (m_BeardTypes && m_BeardTypes.Count() > 0)
			{
				if (m_BeardTypes.Count() > 0)
					GetVariantManager().SetActionVariantCount(m_BeardTypes.Count());
				else
					GetVariantManager().Clear();
			}
		}
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		super.OnFinishProgressServer(action_data);
		PlayerBase man;
		if ( action_data.m_Target && Class.CastTo(man, action_data.m_Target.GetObject()) )
		{
			string newItem = IAT_BeardVariantActionData.Cast(action_data).m_IATBeardVariant;
			GetGame().CreateObjectEx(newItem, man.GetPosition(), ECE_SETUP|ECE_NOLIFETIME|ECE_DYNAMIC_PERSISTENCY);
		}
	}

	override ActionData CreateActionData()
	{
		IAT_BeardVariantActionData action_data = new IAT_BeardVariantActionData;
		return action_data;
	}

	override bool SetupAction( PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL )
	{
		if ( super.SetupAction( player, target, item, action_data, extra_data ) )
		{
			PlayerBase targetPlayer;
			if (Class.CastTo(targetPlayer,  target.GetObject()))
			{
				if ( !GetGame().IsDedicatedServer() )
				{
					TStringArray  m_BeardTypes = targetPlayer.GetFacialHairClassNames();
					string itemName = m_BeardTypes.Get(m_VariantID);
					IAT_BeardVariantActionData.Cast(action_data).m_IATBeardVariant = itemName;
				}
				return true;
			}
		}
		return false;
	}

	override void WriteToContext(ParamsWriteContext ctx, ActionData action_data)
	{
		super.WriteToContext(ctx, action_data);
		ctx.Write(IAT_BeardVariantActionData.Cast(action_data).m_IATBeardVariant);
	}

	override bool ReadFromContext(ParamsReadContext ctx, out ActionReciveData action_recive_data )
	{
		action_recive_data = new IAT_BeardVariantActionReciveData;
		super.ReadFromContext(ctx, action_recive_data);

		string variantId;
		if ( ctx.Read(variantId) )
		{
			IAT_BeardVariantActionReciveData.Cast( action_recive_data ).m_IATBeardVariant = variantId;
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
		IAT_BeardVariantActionData.Cast(action_data).m_IATBeardVariant = IAT_BeardVariantActionReciveData.Cast( action_recive_data ).m_IATBeardVariant;
	}
};