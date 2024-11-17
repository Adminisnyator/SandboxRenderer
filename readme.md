# Your average trans fem python enthusiast to raylib enjoyer gpu shader pipeline.
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C: 23](https://img.shields.io/badge/C-23-blue.svg)](https://en.cppreference.com/w/c/23)
[![Raylib: 5.0+](https://img.shields.io/badge/Raylib-5.0+-green.svg)](https://www.raylib.com/)

This is a small rendering and audio playing demo.
## Goals:
- Render small scene similar to Quake
- Load and Display Textures
- Simple Lighting
- Play audio
- Player Movement
- Particle Effects

## Resources
- [Random Number Generator](https://www.pcg-random.org/download.html)
- [Makefile Reference](https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/)
- [Other Raylib Projects by Tsoding](https://github.com/tsoding)
- [Raylib Github](https://github.com/raysan5/raylib/)

## Building

Install raylib either through your package manager or by cloning it.
For instance with fedora you would:
```bash
$ sudo dnf install raylib-devel
$ make
```
If you want to build it without automatically running it you can also call.
```bash
$ make build-tiny-quake
$ make run-tiny-quake
```
Please be aware that through differences between OS and windowing systems as well as
hardware you might get a different behaviour from the program than the author intended.

