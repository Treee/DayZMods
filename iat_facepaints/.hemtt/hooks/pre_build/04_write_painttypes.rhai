let facepaintOptionsTemplate = HEMTT_VFS.join("addons").join("paints").join("atemplates").join("iat_facepaintoptions.c").open_file().read();

let paintMap = #{};

// foreach category folder inside /addons/paints
let paintCategories = HEMTT_VFS.join("addons").join("paints").list();
for (paintCategory, index) in paintCategories {

	let formattedPaintCategory = paintCategory.to_string();
	formattedPaintCategory.replace(`${HEMTT_VFS.join("addons").join("paints").to_string()}/`, "");

	// skip the template folder
	if (formattedPaintCategory == "atemplates")	{ continue; }
	if (formattedPaintCategory == "atemplates_emmissive")	{ continue; }
	// only consider directories
	if (HEMTT_VFS.join("addons").join("paints").join(formattedPaintCategory).is_dir())
	{
		paintMap.set(formattedPaintCategory, []);

		let paintItems = HEMTT_VFS.join("addons").join("paints").join(formattedPaintCategory).list();
		let paintItemArray = [];
		// foreach paint folder inside a category
		for (paintItem, index) in paintItems {

			let formattedPaintItem = paintItem.to_string();
			formattedPaintItem.replace(`${HEMTT_VFS.join("addons").join("paints").join(formattedPaintCategory).to_string()}/`, "");

			paintItemArray.push(formattedPaintItem);
		}
		paintMap.set(formattedPaintCategory, paintItemArray);
	}
}

let replacementString = "protected void AutoGeneratedInit()\n\t{\n";

let categories = paintMap.keys();
categories.sort();
for (category, index) in categories {
	let categoryString = `category${index}`;
	replacementString += "\t\tarray<string> " + categoryString + "_options = new array<string>;\n";

	let paints = paintMap[category];
	paints.sort();
	for (item, index) in paints
	{
		replacementString += "\t\t" + categoryString + "_options.Insert(""" + item + """);\n";
	}
	replacementString += "\t\ts_FacePaintOptionsMap.Insert(""" + category + """, " + categoryString + "_options);\n\n";
}
replacementString += "\t}\n";
facepaintOptionsTemplate.replace("protected void AutoGeneratedInit(){}", replacementString);
//print(replacementString);
HEMTT_RFS.join("addons").join("scripts").join("3_game").join("iat_facepaintoptions.c").create_file().write(facepaintOptionsTemplate);
