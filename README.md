# AFoP Mod Manager

## F.A.Q.
### What is this?

This is the repository that contains the Frontiers of Pandora Mod Manager.
This tool will allow you to simply drag and drop your mods into a folder, enter a word and have the commands work instantly.

### Will there be a User Interface to this some day?

Yes! The UI will soon be implemented. I currently put the focus on the functions of the tool and getting it to work as seamlessly as possibe.
If you encounter any bugs, please open an issue on this very repository. 

## Usage

This tool can seem quite overwhelming for many people at first if they don't know how to use a command line.
The idea is that you enter a command that allows you to... say turn mods on or off. 
**Here is the current list of commands:**
- `exit`:
    * Allows you to exit the program
- `help`:
    * Shows you a list of all commands that are currently available and their usage.
- `enable <MOD_ID>`:
    * This command turns on the given mod, identified by it's unique Mod-ID.
- `disable <MOD_ID>`: 
    * This command turns off the given mod, identified by it's unique Mod-ID.
- `package <name> <path>`:
    * This command allows mod creators to package their mods into *.afopmod files. A new universal file format to make modding easier.
      more information later.
- `depackage <name> <output-path>`:
    * This command allows anyone to depackage the mod they downloaded into the given output-directory.

