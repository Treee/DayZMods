class IAT_VariantIdActionReciveData extends ActionReciveData
{
  int m_IATVariantId;
}
class IAT_VariantIdActionData extends ActionData
{
  int m_IATVariantId;
};

class IAT_ActioncraftOnWorkbenchCB extends ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(2.0);
	}
};
class IAT_ActionCraftOnWorkbench extends ActionContinuousBase
{
  void IAT_ActionCraftOnWorkbench()
	{
    m_CallbackClass = IAT_ActioncraftOnWorkbenchCB;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_FullBody = true;
    if (!GetGame().IsDedicatedServer())
    {
      GetVariantManager().GetOnUpdateInvoker().Insert(OnUpdateActions);
    }
	}
//====================================== EVENTS
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
    m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
  }
  override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
    IAT_CraftingPlus_CraftingBench_Base craftingWorkbench;
    if (Class.CastTo(craftingWorkbench, target.GetObject()))
    {
      if (craftingWorkbench.HasCraftableMatches())
			  m_Text = "Craft " + craftingWorkbench.GetCraftableItemDisplayNameByIndex(m_VariantID);
    }
	}
override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
{
  if (!target)
    return false;
  IAT_CraftingPlus_CraftingBench_Base craftingWorkbench;
  if (Class.CastTo(craftingWorkbench, target.GetObject()))
  {
    // is item in hands an item this bench considers the tool?
    if (!craftingWorkbench.CanAcceptTool(item))
      return false;
    // string.Format("Looking at the correct bench, has recipes? %1", craftingWorkbench.HasCraftableMatches());
    return craftingWorkbench.HasCraftableMatches();
  }
  return false;
}
	override void OnFinishProgressServer( ActionData action_data )
	{
    IAT_CraftingPlus_CraftingBench_Base craftingWorkbench;
    if (Class.CastTo(craftingWorkbench, action_data.m_Target.GetObject()))
    {
      int variantId = IAT_VariantIdActionData.Cast(action_data).m_IATVariantId;
      IAT_CraftableItem newItem = craftingWorkbench.GetCraftableItemByIndex(variantId);
      craftingWorkbench.ReduceAttachedQuantities(newItem);
      // because players are fucking huge ass babies
			// craftingWorkbench.DecreaseHealth( craftingWorkbench.GetCraftingDamage(), false );
      // Print(string.Format("Creating %1 from inded %2",newItem.GetDisplayName(), variantId));
      Object newObject = GetGame().CreateObjectEx(newItem.GetItemClassName(), craftingWorkbench.GetMemoryPointPosition("item_spawn_position"), ECE_SETUP|ECE_NOSURFACEALIGN|ECE_KEEPHEIGHT|ECE_NOLIFETIME|ECE_DYNAMIC_PERSISTENCY);
      if (newItem.GetItemQuantity() > 1)
      {
        Magazine ammo;
        ItemBase newItemBase;
        if (Class.CastTo(ammo, newObject))
          ammo.ServerSetAmmoCount(newItem.GetItemQuantity());
        else if (Class.CastTo(newItemBase, newObject))
          newItemBase.SetQuantity(newItem.GetItemQuantity());
      }
    }
	}
  override ActionData CreateActionData()
	{
		IAT_VariantIdActionData action_data = new IAT_VariantIdActionData;
		return action_data;
	}
  override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL)
	{
		if (super.SetupAction(player, target, item, action_data, extra_data))
		{
      if (!GetGame().IsDedicatedServer())
      {
        if (!target || !target.GetObject())
          return false;

        IAT_VariantIdActionData.Cast(action_data).m_IATVariantId = m_VariantID;
        SetupAnimation(target.GetObject().GetType());
      }
			return true;
		}
		return false;
	}
//====================================== RPC STUFF
  override void WriteToContext(ParamsWriteContext ctx, ActionData action_data)
	{
		super.WriteToContext(ctx, action_data);
		ctx.Write(IAT_VariantIdActionData.Cast(action_data).m_IATVariantId);
	}
	override bool ReadFromContext(ParamsReadContext ctx, out ActionReciveData action_recive_data )
	{
		action_recive_data = new IAT_VariantIdActionReciveData;
		super.ReadFromContext(ctx, action_recive_data);

		int variantId;
		if ( ctx.Read(variantId) )
		{
      // Print("[ReadFromContext] - " + variantId)
			IAT_VariantIdActionReciveData.Cast( action_recive_data ).m_IATVariantId = variantId;
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
		IAT_VariantIdActionData.Cast(action_data).m_IATVariantId = IAT_VariantIdActionReciveData.Cast( action_recive_data ).m_IATVariantId;
	}
//====================================== Custom Events
  void OnUpdateActions( Object item, Object target, int component_index )
	{
    IAT_CraftingPlus_CraftingBench_Base craftingWorkbench;
		if (Class.CastTo(craftingWorkbench, target))
		{
      if (craftingWorkbench.HasCraftableMatches())
        GetVariantManager().SetActionVariantCount(craftingWorkbench.GetPotentialCraftableItemCount());
		}
		else
			GetVariantManager().Clear();
	}
  void SetupAnimation(string targetBench)
	{
    // switch(targetBench)
    // {
    //   // case "SRP_PrefabCrafting_carpentry":
    //   // case "SRP_PrefabCrafting_metalworking":
    //   // case "SRP_PrefabCrafting_smithing":
		// 		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
    //   break;
    //   // case "SRP_PrefabCrafting_drugtub":
    //   // case "SRP_PrefabCrafting_tailoring":
    //   // case "SRP_PrefabCrafting_printingpress":
    //   // case "SRP_PrefabCrafting_ammocrafting":
		// 		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_RESTRAINTARGET;
    //   break;
    // }
	}
//====================================== END
};
