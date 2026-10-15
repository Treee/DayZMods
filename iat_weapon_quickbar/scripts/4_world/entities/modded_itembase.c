// If items are given weapon slots and can go into cargo then this will need to be uncommented
// modded class ItemBase
// {
//     override void OnItemLocationChanged(EntityAI old_owner, EntityAI new_owner)
//     {
//         super.OnItemLocationChanged(old_owner, new_owner);

//         if (IsEmpty())
//             return;
//         if (GetSlotsCountCorrect() == -1)
//             return;

//         // handle bags with slots for weapons
//         EntityAI attachedItem;
//         PlayerBase rootPlayer;
//         TStringArray slotNames = GetWeaponAttachmentSlots();
//         foreach (string slotName : slotNames)
//         {
//             // short circuit
//             if (!Class.CastTo(attachedItem, FindAttachmentBySlotName(slotName)))
//                 continue;
//             else
//             {
//                 if (new_owner && !attachedItem.CanAssignToQuickbar())
//                 {
//                     if (Class.CastTo(rootPlayer, new_owner.GetHierarchyRootPlayer()))
//                         rootPlayer.RemoveQuickBarEntityShortcut(attachedItem);
//                 }
//             }
//         }
//     }
// };