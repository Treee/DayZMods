modded class ItemActionsWidget
{
    override protected void SetWeaponQuantity(int chamber, int mag, string itemWidget, string quantityPBWidget, string quantityTextWidget, bool enabled)
	{
		Widget widget;

		widget = m_Root.FindAnyWidget(itemWidget);

		if (enabled)
		{
			string wpn_qty = "";

			ProgressBarWidget progressBar;
			TextWidget textWidget;
			Class.CastTo(progressBar, widget.FindAnyWidget(quantityPBWidget));
			Class.CastTo(textWidget, widget.FindAnyWidget(quantityTextWidget));

			Weapon_Base wpn;
			Magazine maga;
			int mag_quantity = -1;
            int mag_quantity_max = -1;

			if (Class.CastTo(wpn, m_EntityInHands))
			{
				if (Magnum_Base.Cast(wpn))
				{
					mag_quantity = 0;
					for (int j = 0; j < wpn.GetMuzzleCount(); j++)
					{
						if (wpn.IsChamberFull(j)&& !wpn.IsChamberFiredOut(j))
							mag_quantity++;
					}
					wpn_qty = mag_quantity.ToString();
                    mag_quantity_max = wpn.GetMuzzleCount();
				}
				else
				{
					for (int i = 0; i < wpn.GetMuzzleCount(); i++)
					{
						if (i > 0 && (wpn.GetMuzzleCount() < 3 ||  i%2 == 0))
						{
							wpn_qty = wpn_qty + " ";
						}
						if (wpn.IsChamberEmpty(i))
						{
							wpn_qty = wpn_qty + "0";
						}
						else if (wpn.IsChamberFiredOut(i))
						{
							wpn_qty = wpn_qty + "F";
						}
						else
						{
							wpn_qty = wpn_qty + "1";
						}

						maga = wpn.GetMagazine(i);
						if (maga)
						{
							mag_quantity = maga.GetAmmoCount();
                            mag_quantity_max = maga.GetAmmoMax();
						}
						else if (wpn.GetInternalMagazineMaxCartridgeCount(i) > 0)
						{
							mag_quantity = wpn.GetInternalMagazineCartridgeCount(i);
                            mag_quantity_max = wpn.GetInternalMagazineMaxCartridgeCount(i);
						}

					}

					if (wpn.IsJammed())
					{
						if (mag_quantity != -1)
							wpn_qty = string.Format("X (+%1)", mag_quantity);
						else
							wpn_qty = "X";
					}
					else
					{
						if (mag_quantity != -1)
						{
							wpn_qty = wpn_qty + " (" + mag_quantity.ToString() + ")";
						}
					}
				}
			}

			// progressBar.Show(false);
            float value;
            if (mag_quantity_max == 0)
                value = 0;
            else
                value = Math.Round((mag_quantity / mag_quantity_max) * 100);

            // PrintFormat("mag: %1 magMax: %2", mag_quantity, mag_quantity_max);
            progressBar.SetCurrent(value);
            progressBar.Show(true);
			// textWidget.SetText(wpn_qty);
			// textWidget.Show(true);
			textWidget.Show(false);
			textWidget.GetParent().Show(true);
		}
		else
			widget.Show(false);
	}
};