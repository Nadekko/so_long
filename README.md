# SO_LONG

So_long is a project from 42 Paris school. It's a little game in 2D coding in C.

## Installation

To run this game, you'll need the MiniLibx library installed. The makefile will automatically clone it when you run `make`, but this may vary depending on your OS. Feel free to change the repo link in the makefile to match the MiniLibx version that suits your system.

### Supported OS

- **Ubuntu**: Tested and working
- **macOS**: Untested (may have compatibility issues)
- **Fedora**: Not compatible (due to MiniLibx function incompatibilities)

## Usage

```
make
./so_long <map/random_map>
```

## Goal

You will need to collect all gems to open the exit. On some map some skeleton are wandering and you only have three lives.

## Controls

- W/A/S/D (or Z/Q/S/D) or Arrow Keys: move
- ESC: Exit

## Demo

<p align="center">
  <img src="demo/demo_idle_animation.gif" width="45%" alt="Idle animation">
</p>
<p align="center">
  <img src="demo/demo_exit.gif" width="45%" alt="End win">
  <img src="demo/demo_death.gif" width="45%" alt="Death">
</p>

## Grade

125/100 (pass with bonus)
