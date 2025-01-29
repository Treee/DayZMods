modded class PlayerBase
{
	override void SetActions(out TInputActionMap InputActionMap)
    {
        super.SetActions(InputActionMap);
        AddAction(IAT_ActionReadPaperTarget, InputActionMap);
	}

    override void EEItemIntoHands(EntityAI item)
    {
        super.EEItemIntoHands( item );

        Paper paper;
        // if the item brought into hands is paper
        if (Class.CastTo(paper, item))
        {
            // reset lifetime to whatever the default is
            SetLifetimeMax(GetLifetimeMax());
        }
    }
};