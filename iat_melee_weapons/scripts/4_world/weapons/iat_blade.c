//================================ 2H SWORD
class IAT_Melee_BerserkSword_ColorBase extends Sword{};
class IAT_Melee_BerserkSword_Basic extends IAT_Melee_BerserkSword_ColorBase{};
class IAT_Melee_BerserkSword_Illusive extends IAT_Melee_BerserkSword_ColorBase{};
class IAT_Melee_BerserkSword_theiliusiveman extends IAT_Melee_BerserkSword_ColorBase{};

class IAT_Melee_JawBladeSword_ColorBase extends Sword{};
class IAT_Melee_JawBladeSword_Basic extends IAT_Melee_JawBladeSword_ColorBase{};
class IAT_Melee_JawBladeSword_Obamamama2580 extends IAT_Melee_JawBladeSword_ColorBase{};

class IAT_Melee_Aerondight_ColorBase extends Sword{};
class IAT_Melee_Aerondight_Basic extends IAT_Melee_Aerondight_ColorBase{};
class IAT_Melee_Aerondight_bloodkill1347 extends IAT_Melee_Aerondight_ColorBase{};

class IAT_Melee_ClaymoreSword_ColorBase extends Sword{};
class IAT_Melee_ClaymoreSword_Basic extends IAT_Melee_ClaymoreSword_ColorBase{};
class IAT_Melee_ClaymoreSword_autumn2187 extends IAT_Melee_ClaymoreSword_ColorBase{};

class IAT_Melee_ClaymoreSwordSheathe_ColorBase: Belt_Base {};
class IAT_Melee_ClaymoreSwordSheathe_Basic: IAT_Melee_ClaymoreSwordSheathe_ColorBase {};

//================================ SCYTHE
class IAT_Melee_FriedesScythe_ColorBase extends Sword{};
class IAT_Melee_FriedesScythe_Basic extends IAT_Melee_FriedesScythe_ColorBase{};
class IAT_Melee_FriedesScythe_theamontiladoraven extends IAT_Melee_FriedesScythe_ColorBase{};

class IAT_Melee_ReaperScythe_ColorBase extends Sword{};
class IAT_Melee_ReaperScythe_Basic extends IAT_Melee_ReaperScythe_ColorBase{};
class IAT_Melee_ReaperScythe_legacylives extends IAT_Melee_ReaperScythe_ColorBase{};

//================================ 1H SWORD
class IAT_Melee_GrinningBlade_ColorBase extends Sword{};
class IAT_Melee_GrinningBlade_Basic extends IAT_Melee_GrinningBlade_ColorBase{};
class IAT_Melee_GrinningBlade_itsb14nk extends IAT_Melee_GrinningBlade_ColorBase{};

class IAT_Katana_ColorBase extends Sword{};
class IAT_Katana_Basic extends IAT_Katana_ColorBase{};
class IAT_Katana_delaineyrp extends IAT_Katana_ColorBase{};

class IAT_KatanaSheathe_ColorBase: Belt_Base {};
class IAT_KatanaSheathe_Basic: IAT_KatanaSheathe_ColorBase {};
class IAT_KatanaSheathe_delaineyrp: IAT_KatanaSheathe_ColorBase {};

class IAT_KatanaFlower_ColorBase extends Sword{};
class IAT_KatanaFlower_Basic extends IAT_KatanaFlower_ColorBase{};
class IAT_KatanaFlower_zero_hurts extends IAT_KatanaFlower_ColorBase{};

//================================ GLAIVE
class IAT_Melee_Glaive_ColorBase extends Sword{};
class IAT_Melee_Glaive_Basic extends IAT_Melee_Glaive_ColorBase{};
class IAT_Melee_Glaive_autumn2187 extends IAT_Melee_Glaive_ColorBase{};

//================================ KNIVES
class IAT_Narsil_ColorBase extends ToolBase
{
	override bool IsMeleeFinisher()
	{
		return true;
	}

	override array<int> GetValidFinishers()
	{
		return {EMeleeHitType.FINISHER_LIVERSTAB,EMeleeHitType.FINISHER_NECKSTAB};
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionUnrestrainTarget);
		AddAction(ActionSkinning);
		AddAction(ActionMineBush);
		AddAction(ActionMineTreeBark);
		AddAction(ActionDigWorms);
		AddAction(ActionShaveTarget);
		AddAction(ActionShave);
		AddAction(ActionCraftBolts);
	}
};
class IAT_Narsil_Basic extends IAT_Narsil_ColorBase {};
class IAT_Narsil_Obamamama2580 extends IAT_Narsil_ColorBase {};

class IAT_DamascusBowieKnife_ColorBase extends ToolBase
{
	override bool IsMeleeFinisher()
	{
		return true;
	}

	override array<int> GetValidFinishers()
	{
		return {EMeleeHitType.FINISHER_LIVERSTAB,EMeleeHitType.FINISHER_NECKSTAB};
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionUnrestrainTarget);
		AddAction(ActionSkinning);
		AddAction(ActionMineBush);
		AddAction(ActionMineTreeBark);
		AddAction(ActionDigWorms);
		AddAction(ActionShaveTarget);
		AddAction(ActionShave);
		AddAction(ActionCraftBolts);
	}
};
class IAT_DamascusBowieKnife_Basic extends IAT_DamascusBowieKnife_ColorBase {};
class IAT_DamascusBowieKnife_sir_bman extends IAT_DamascusBowieKnife_ColorBase {};

class IAT_TrenchKnife_ColorBase extends ToolBase
{
	override bool IsMeleeFinisher()
	{
		return true;
	}

	override array<int> GetValidFinishers()
	{
		return {EMeleeHitType.FINISHER_LIVERSTAB,EMeleeHitType.FINISHER_NECKSTAB};
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionUnrestrainTarget);
		AddAction(ActionSkinning);
		AddAction(ActionMineBush);
		AddAction(ActionMineTreeBark);
		AddAction(ActionDigWorms);
		AddAction(ActionShaveTarget);
		AddAction(ActionShave);
		AddAction(ActionCraftBolts);
	}
};
class IAT_TrenchKnife_Basic extends IAT_TrenchKnife_ColorBase {};
class IAT_TrenchKnife_weebyboi extends IAT_TrenchKnife_ColorBase {};

class IAT_MorgulBlade_ColorBase extends ToolBase
{
	override bool IsMeleeFinisher()
	{
		return true;
	}

	override array<int> GetValidFinishers()
	{
		return {EMeleeHitType.FINISHER_LIVERSTAB,EMeleeHitType.FINISHER_NECKSTAB};
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionUnrestrainTarget);
		AddAction(ActionSkinning);
		AddAction(ActionMineBush);
		AddAction(ActionMineTreeBark);
		AddAction(ActionDigWorms);
		AddAction(ActionShaveTarget);
		AddAction(ActionShave);
		AddAction(ActionCraftBolts);
	}
};
class IAT_MorgulBlade_Basic extends IAT_MorgulBlade_ColorBase {};
class IAT_MorgulBlade_comradeg extends IAT_MorgulBlade_ColorBase {};