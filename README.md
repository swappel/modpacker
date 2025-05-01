# AFoP Mod Packer

## F.A.Q.
### What is this program for?

This program is used to package your mods so they are in the compatible format for the AFoPModManager.

### When I try to pack mods, the program tells me it's in the wrong format. What did I do wrong?

You may have forgotten one, or multiple things. Please refere to the format further below to make sure everything works out properly.

## Usage
**Here is the current list of commands:**
- `exit`:
    * This command allows you to exit the program
- `help`:
    * This command shows you a list of all commands that are currently available and their usage.
- `pack <input-folder-path> <mod_file_name>`:
   * This command packages the given input folder into a .afopmod package.
- `unpack <modfile-path> <output-folder-path>`:
   * This command unpacks the mod file and outputs it's sources to the specified output folder. (`<output-folder>/mod-name/`);
- `info <mod-file>`:
    * This command displays information about a mod package. (Metadata)
- `generate_info`:
    * Generates the necessary mod.json file in your mod in a way that you can easily fill out. 

## `mod.json` file format:
   Here are the parameters in the Mod's config:
      - `id`: This field contains the mod's **UNIQUE** ID. No other mod can have the same ID!!!
      - `name`: This field contains the name of the mod as it will be displayed.
      - `author`: This field contains the name of the author. Can be left blank.
      - `version`: This field contains the version number of the mod. (Format: `x.x.x[-alpah/beta]`)
      - `description`: This field contains the description of the mod. Can be empty, but not recommended.
   #### This is an example of a `mod.json` file:
   ```javascript
   {
      "id": "QUEST_FIX",
      "name": "Mod Name",
      "author": "Author Name",
      "version": "0.0.1-alpha",
      "description": "Fixes a bug where you get softlocked in a quest."
   }
   ```

## The `.afopmod` packages:
The .afopmod packages are an addition that is supposed to simplify the modification of the game and is basically just the same as a ZIP-File, just without compression.
Later on, a compression algorithm will be implemented to minimize the size of these packages to further simplify diffusion of mods via all kinds of websites.
These packages will be able to be depackaged by everyone who has access to the AFoP Mod Manager. They are not supposed to be encrypted and/or protected in any way.

### The structure of the package:
To make the mod work, you will need to respect the same format as for normal mod. Start from the root folder("blue/") and build from there. Here is what the mdo folder should look like before packing:

```
Mod Folder/
├── blue/
│   ├── localization/
│       ├── packages/
│           ├── english/
│               ├── menus.locpack
│               ├── menus.locpackbin
├── mod.json
```
