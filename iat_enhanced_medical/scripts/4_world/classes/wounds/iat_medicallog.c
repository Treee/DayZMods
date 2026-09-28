// Server script-log diagnostics. No RPCs or additional saved fields.
class IAT_MedicalLog
{
 static bool Enabled = true;
 static string Bones(int mask)
 {
  string result;
  foreach (string bone : PluginIATMedical.IAT_GetBones())
  {
   if ((mask & PluginIATMedical.IAT_GetBulletBoneBit(bone)) == 0)
    continue;
   if (result != "")
    result += ",";
   result += bone;
  }
  return "[" + result + "]";
 }
 static void Event(PlayerBase player, string eventName, string detail = "")
 {
  if (!Enabled || !g_Game || !g_Game.IsServer() || !player)
   return;
  int a, b, c, d;
  player.GetPersistentID(a, b, c, d);
  PrintFormat("[IAT MEDICAL] event=%1 pid=%2:%3:%4:%5 entity=%6 %7", eventName, a, b, c, d, player, detail);
 }
 static void Snapshot(PlayerBase player, string eventName)
 {
  if (!Enabled || !g_Game || !g_Game.IsServer() || !player)
   return;
  IAT_MedicalState state = player.IAT_GetMedicalState();
  Event(player, eventName, string.Format("version=%1 wounds=%2 bullets=%3 dressed=%4 activeBleeds=%5", IAT_MedicalState.STORAGE_VERSION, state.Wounds, state.Bullets, state.DressedWounds, player.GetBleedingBits()));
  Event(player, "BONES", "wounds=" + Bones(state.Wounds) + " bullets=" + Bones(state.Bullets) + " dressed=" + Bones(state.DressedWounds));
  string attachments;
  foreach (string slot : PluginIATMedical.IAT_GetBandageSlots())
  {
   EntityAI item = player.FindAttachmentBySlotName(slot);
   if (item)
    attachments += string.Format(" %1=%2(ruined=%3)", slot, item.GetType(), item.IsRuined());
   else
    attachments += " " + slot + "=empty";
  }
  Event(player, "ATTACHMENTS", attachments);
  string pools;
  foreach (string zone : PluginIATMedical.IAT_GetDamageZones())
   pools += string.Format(" %1=%2/%3", zone, player.GetHealth(zone, "Blood"), player.GetMaxHealth(zone, "Blood"));
  Event(player, "BLOOD_POOLS", pools);
 }
}
