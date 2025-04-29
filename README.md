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
- `pack <input-folder>`:
   * This command packages the given input folder into a .afopmod package.
- `unpack <input-folder> <output-folder>`:
   * This command unpacks the mod file and outputs it's sources to the specified output folder. (`<output-folder>/mod-name/`);
- `info <mod-file>`:
    * This command displays information about a mod package. (Metadata)

## The .afopmod packages:
The .afopmod packages are an addition that is supposed to simplify the modification of the game and is basically just the same as a ZIP-File, just without compression.
Later on, a compression algorithm will be implemented to minimize the size of these packages to further simplify diffusion of mods via all kinds of websites.
These packages will be able to be depackaged by everyone who has access to the AFoP Mod Manager. They are not supposed to be encrypted and/or protected in any way.
