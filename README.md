# Cave Story MD
![Comparison Shot](doc/screen01.png)
[Video](http://www.youtube.com/watch?v=aZU133ekDVk)

This is a rewrite/port of the popular freeware game Cave Story for Sega Mega Drive/Genesis.
The engine uses many parts of SGDK, and written mostly in C.

It should work on any console or emulator. Expect alpha quality.

## Download
"Stable" releases can be found in the [Releases](https://github.com/andwn/cave-story-md/releases) tab.

For something more bleeding edge, try the Nightly: [NTSC](http://www.cavestory.org/md/nightly.zip) / [PAL](http://www.cavestory.org/md/nightlypal.zip) <br/>

Farthest reachable point in `master`: Normal Ending / Hell B3

## Control Defaults
If you have a 6 button controller:

- `C` - Jump, confirm
- `B` - Shoot
- `A` - Fast forward through scripted events
- `Y`, `Z` - Switch weapon
- `Start` - Pause / Item Menu

For 3 button, `A` cycles through weapons. The rest is the same.

To activate Stage Select: 🡩 🡫🡨 🡪  A + Start. Like Sonic. 

## Compilation
0. Dependencies for all this:
  - Ubuntu/Debian: `sudo apt install wget unzip openjdk-8-jre-headless build-essential texinfo python`
  - RedHat/CentOS: `sudo yum groupinstall "Development Tools" && sudo yum install wget unzip java-1.8.0-openjdk-headless texinfo python`
  - Arch: `sudo pacman -Sy wget unzip jre8-openjdk-headless base-devel texinfo python`
1. Set up [Gendev](https://github.com/kubilus1/gendev) following the instructions on that page
2. Clone this repository and do `make -f Makefile.new`, or `make -f Makefile.new pal`.
3. Open `doukutsu.bin` in your emulator of choice, or put it on a flash cart.

## FAQ
#### Why?
To learn MD dev mostly.

#### Will you release this on cartridge?
No. Nicalis would sue me.

## Thanks
I did not know how to sort this list, so I did it alphabetically.

- andwhyisit: A whole lot of testing. Automated builds.
- DavisOlivier: Helped with a few music tracks, namely Gestation, Access, Cave Story, Fanfare 1/2/3
- Sik: Mega Drive tech support. Made the font used ingame.
- Other people I probably forgot
