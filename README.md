# Game Engine Documentation

This document covers the classes made for the Template Game Engine that BUas produced, this documentation is simply for me understanding it better. Therefore I write it down from what I understand in this document, down below the original `readme` file will be written down as well.

---

## Table of Contents

- [Surface Class](#surface-class)
- [Sprite Class](#sprite-class)
- [Original ReadMe](#read-me)

---

## Surface Class

The `Surface` class represents a 2D pixel surface where drawing and image manipulation operations can be performed. This is also able to initialise a specified window.

### Attributes

- `Pixel* m_Buffer`: Pointer to the pixel buffer.
- `int m_Width, m_Height`: Dimensions of the surface.
- `int m_Pitch`: Number of pixels per row (used for memory alignment).
- `int m_Flags`: Indicates ownership of the buffer.

### Key Methods

- **Constructors**:
  - `Surface(int a_Width, int a_Height)`: Initializes an empty surface.
  - `Surface(char* a_File)`: Loads an image from the provided file.

- **LoadImage(char* a_File)**: Loads an image from the specified file.

- **Print(char* a_String, int x1, int y1, Pixel color)**: Draws a string of text onto the surface at the given position.

- **Plot(int x, int y, Pixel c)**: Draws a single pixel at the specified coordinates.

- **Line(float x1, float y1, float x2, float y2, Pixel color)**: Draws a line between two points.

- **Box(int x1, int y1, int x2, int y2, Pixel color)**: Draws a rectangle.

- **Bar(int x1, int y1, int x2, int y2, Pixel color)**: Draws a filled rectangle.

- **CopyTo(Surface* a_Dst, int a_X, int a_Y)**: Copies the surface contents to another surface.

- **BlendCopyTo(Surface* a_Dst, int a_X, int a_Y)**: Copies the surface to another surface with blending.

- **Resize(Surface* a_Orig)**: Resizes the surface to match the dimensions of the original.

---

## Sprite Class

The `Sprite` class handles animated image sequences. It supports multiple frames and provides drawing capabilities.

### Attributes

- `Surface* m_Surface`: The surface that contains the sprite image.
- `int m_Width, m_Height`: Dimensions of a single frame.
- `unsigned int m_NumFrames`: Number of frames in the sprite.
- `unsigned int m_CurrentFrame`: Current frame for rendering.

### Key Methods

- ***Sprite(Surface* a_Surface, unsigned int a_NumFrames)**: Constructor that initializes a sprite from a surface and splits it into frames.

- ***Draw(Surface* a_Target, int a_X, int a_Y)**: Draws the sprite at the specified location on a surface.

- ***DrawScaled(int a_X, int a_Y, int a_Width, int a_Height, Surface* a_Target)**: Draws the sprite scaled to the given dimensions.

---

## Read Me 
BRIEF INFO ON THE 2019-08 TEMPLATE
Template, BUAS version https://www.buas.nl/games
IGAD/BUAS(NHTV)/UU - Jacco Bikker - 2006-2020

### Purpose:
The template has been designed to make it easy to start coding C++
using games and graphics. It intends to offer the programmer a
simple library with the main purpose of providing a 32-bit graphical
window with a linear frame buffer. Some basic additional functionality
is available, such as sprites, bitmap fonts, and vector math support.

How to use:
1. Copy the template folder (or extract the zip) to a fresh folder for
   your project. 
2. Open the .sln file with any version of Visual Studio 2019.
3. Replace the example code in game.cpp with your own code.
4. Copy the 64-bit dll's from dlls_x64 to the project folder if you
   want to run a 64-bit build.

You can go further by:
- Expanding the game class in game.h;
- Implementing some of the empty functions for mouse and keyboard
  handling;
- Exploring the code of the template in surface.cpp and template.cpp.

---

When handing in assignments based on this template, please run
clean.bat prior to zipping the folder. This deletes any intermediate
files created during compilation.

The Template is a 'quickstart' template, and not meant to be elaborate
performant or complete. 
At some point, and depending on your requirements, you may want to
advance to a more full-fledged library, or you can expand the template
with OpenGL or SDL2 code.

---

### Credits
Although the template is small and bare bones, it still uses a lot of
code gathered over the years:
- EasyCE's 5x5 bitmap font (primarily used for debugging);
- EasyCE's surface class (with lots of modifications);
- This version of the template uses SDL2 for low-level window handling,
  hopefully improving on the compatibility of earlier versions.

### Copyright
This code is completely free to use and distribute in any form.

### Template Naming
Starting January 2017, the name of the template represents the version.
This version also appears in the title of the window. Make sure you
are using the most recent version.

Breda, 2014-2019, Games @ Breda University (NHTV/IGAD)
Utrecht, 2015-2019, Utrecht University
Report problems and suggestions to Robbie Grigg if working on this 
connected to Breda University then email grigg.r@buas.nl
otherwise bikker.j@gmail.com .

---

### Changelog

v2019-08:
removed headers from the precompiled header file to speed up compilation 
fixed uninitialised values in the surface class. 

v2017-01: 
initial DGDARC release.

v2017-02:
added a changelog.
debug mode now also emits .exe to project folder.
removed rogue SDL2 folder.
added assert.h to precomp.h.