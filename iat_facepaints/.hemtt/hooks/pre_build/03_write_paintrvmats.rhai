let femalePersonas = ["baty", "eva", "frida", "gabi", "helga", "irena", "judy", "keiko", "linda", "maria", "naomi"];
let malePersonas = ["adam", "boris", "cyril", "denis", "elias", "francis", "guo", "hassan", "indar", "jose", "kaito", "lewis", "manua", "niki", "oliver", "peter", "quinn", "rolf", "seth", "taiki"];
let lifespanStates = ["shaved", "unshaved", "bearded"];

// foreach category folder inside /addons/paints
let paintCategories = HEMTT_VFS.join("addons").join("paints").list();
for (paintCategory, index) in paintCategories {

	let formattedPaintCategory = paintCategory.to_string();
	formattedPaintCategory.replace(`${HEMTT_VFS.join("addons").join("paints").to_string()}/`, "");

	// skip the template folder
	if (formattedPaintCategory == "atemplates")	{ continue; }
	if (formattedPaintCategory == "atemplates_emmissive") { continue; }

	if (HEMTT_VFS.join("addons").join("paints").join(formattedPaintCategory).is_dir())
	{
		print(`Generating Category ${formattedPaintCategory}`);

		let paintItems = HEMTT_VFS.join("addons").join("paints").join(formattedPaintCategory).list();
		// foreach paint folder inside a category
		for (paintItem, index) in paintItems {

			let formattedPaintItem = paintItem.to_string();
			formattedPaintItem.replace(`${HEMTT_VFS.join("addons").join("paints").join(formattedPaintCategory).to_string()}/`, "");
			// print(`Generating Paint Item ${formattedPaintItem}`);

			// foreach paa inside a paint folder should have 2 items _unshaved_mc.paa and _shaved_mc.paa
			let paintTextures = HEMTT_VFS.join("addons").join("paints").join(formattedPaintCategory).join(formattedPaintItem).list();
			// categories can flag if they have emmissives to select a different rvmat set
			let hasEmmissiveTexture = false;
			for (paintTexture, index) in paintTextures {
				let formattedPaintTexture = paintTexture.to_string();
				formattedPaintTexture.replace(`${HEMTT_VFS.join("addons").join("paints").join(formattedPaintCategory).join(formattedPaintItem).to_string()}/`, "");

				// flag emmissives
				if (formattedPaintTexture.contains("_e_co.paa")) { hasEmmissiveTexture = true; }
				// only process mc paa's
				if (!formattedPaintTexture.contains("_mc.paa")) { continue; }


				// female persona only needs shaved version
				if (formattedPaintTexture.to_string().contains("_shaved"))
				{
					// print(`Generating Female RVMAT Item ${formattedPaintTexture.to_string()}`);
					// foreach female persona for a given paint
					for (persona, index) in femalePersonas {
						// read the template for the given persona
						let femaleTemplateFileName = `hhl_f_${persona}_body.rvmat`;
						let femaleRvmatTemplate = HEMTT_VFS.join("addons").join("paints").join("atemplates").join(femaleTemplateFileName).open_file().read();
						// branch for emmisive textures
						if (hasEmmissiveTexture)
						{
							femaleRvmatTemplate = HEMTT_VFS.join("addons").join("paints").join("atemplates_emmissive").join(femaleTemplateFileName).open_file().read();
						}
						// replace the parts that are templated
						femaleRvmatTemplate.replace("${FACEPAINT_CATEGORY}", `${formattedPaintCategory}\${formattedPaintItem}`);
						femaleRvmatTemplate.replace("${FACEPAINT_FILENAME}", formattedPaintTexture);
						femaleRvmatTemplate.replace("${FACEPAINT_EMMISSIVE_FILENAME}", "iat_glow_e_co.paa");

						// play aroudbn with just copyingf it to build output instead of creating it phyisically

						// write the file
						HEMTT_RFS.join("addons").join("paints").join(formattedPaintCategory).join(formattedPaintItem).join(femaleTemplateFileName).create_file().write(femaleRvmatTemplate);
					}
				}

				// foreach male personal for a given paint
				for (persona, index) in malePersonas {
					// foreach male lifespan type
					for (lifespanState, index) in lifespanStates {
						let maleTemplateFileName = `hhl_m_${persona}_body_${lifespanState}.rvmat`;
						// read the template for the given persona
						let maleRvmatTemplate = HEMTT_VFS.join("addons").join("paints").join("atemplates").join(maleTemplateFileName).open_file().read();
						if (hasEmmissiveTexture)
						{
							maleRvmatTemplate = HEMTT_VFS.join("addons").join("paints").join("atemplates_emmissive").join(maleTemplateFileName).open_file().read();
						}
						if (lifespanState == "unshaved" || lifespanState == "shaved")
						{
							if (formattedPaintTexture.to_string().contains("_shaved"))
							{
								// replace the parts that are templated
								maleRvmatTemplate.replace("${FACEPAINT_CATEGORY}", `${formattedPaintCategory}\${formattedPaintItem}`);
								maleRvmatTemplate.replace("${FACEPAINT_FILENAME}", formattedPaintTexture);
								maleRvmatTemplate.replace("${FACEPAINT_EMMISSIVE_FILENAME}", "iat_glow_e_co.paa");

								// play aroudbn with just copyingf it to build output instead of creating it phyisically

								// write the file
								HEMTT_RFS.join("addons").join("paints").join(formattedPaintCategory).join(formattedPaintItem).join(maleTemplateFileName).create_file().write(maleRvmatTemplate);

							}
						}
						else
						{
							if (formattedPaintTexture.to_string().contains("_unshaved"))
							{
								// replace the parts that are templated
								maleRvmatTemplate.replace("${FACEPAINT_CATEGORY}", `${formattedPaintCategory}\${formattedPaintItem}`);
								maleRvmatTemplate.replace("${FACEPAINT_FILENAME}", formattedPaintTexture);
								maleRvmatTemplate.replace("${FACEPAINT_EMMISSIVE_FILENAME}", "iat_glow_e_co.paa");

								// play aroudbn with just copyingf it to build output instead of creating it phyisically

								// write the file
								HEMTT_RFS.join("addons").join("paints").join(formattedPaintCategory).join(formattedPaintItem).join(maleTemplateFileName).create_file().write(maleRvmatTemplate);

							}
						}
					}
				}
			}
		}
		print("");
	}
}