modded class DayZGame
{
	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, target, rpc_type, ctx);

		if (rpc_type == IAT_MOLOTOV_ERPCs.RPC_SOUND_INCENDIARY)
		{
			vector soundPos;

			// if we cannot get the data, short circuit
			Param1<vector> playIncendiarySound = new Param1<vector>(vector.Zero);
			if (ctx.Read(playIncendiarySound))
			{
				soundPos = playIncendiarySound.param1;
				if (soundPos == vector.Zero)
					return;
			}
			else
				return;

			// if there is no player, short circuit
			if (!GetGame().GetPlayer())
				return;

			// play the close artillery sound
			EffectSound closeArtySound = SEffectManager.PlaySound("Artillery_Close_SoundSet", soundPos);
			closeArtySound.SetAutodestroy(true);

			// We add camera shake upon shell detonation
			float distance_to_player = vector.DistanceSq(soundPos, GetGame().GetPlayer().GetPosition());
			if (distance_to_player <= GameConstants.CAMERA_SHAKE_ARTILLERY_DISTANCE2)
			{
				float strength_factor = Math.InverseLerp(GameConstants.CAMERA_SHAKE_ARTILLERY_DISTANCE, 0, Math.Sqrt(distance_to_player));
				DayZPlayerCamera camera = GetGame().GetPlayer().GetCurrentCamera();
				if (camera)
					camera.SpawnCameraShake(strength_factor * 4);
			}

			ParticleManager.GetInstance().PlayInWorld(ParticleList.IAT_GRENADE_INCENDIARY_SHELL, soundPos);
		}
	}
};