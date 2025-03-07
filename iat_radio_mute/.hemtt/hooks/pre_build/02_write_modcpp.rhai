let modcpp = HEMTT_VFS.join("mod.cpp").open_file().read(); // Read the contents of mod.cpp
modcpp.replace("0.0.0", HEMTT.project().version().to_string_short()); // Replace the placeholder version with the actual version
HEMTT_VFS.join("mod.cpp").create_file().write(modcpp); // Write the new contents over the old contents
