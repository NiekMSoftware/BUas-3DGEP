# Game Engine Template Documentation
> Template, BUAS version https://www.buas.nl/games
IGAD/BUAS(NHTV)/UU - Jacco Bikker - 2006-2020

The template has been designed to make it easy to start coding C++ using games and graphics. It intends to offer the programmer a simple library with the main purpose of providing a 32-bit graphical window with a linear frame buffer. Some basic additional functionality is available, such as sprites, bitmap fonts, and vector math support.

This documentation is written by me to better help understand the Template Engine. All the rights of creating this template goes to Jacco Bikker. Some elements in this document are copied over from the `_readme.txt` file inside the template.

---

## Table of Contents

1. [Introduction](#introduction)
2. [Surface Class](#surface-class)
3. [Sprite Class](#sprite-class)
4. [Font Class](#font-class)
5. [Vector and Matrix Classes](#vector-and-matrix-classes)
6. [Timer Class](#timer-class)
7. [Utility Functions](#utility-functions)
8. [After Word](#after-word)

---

## Introduction

This template includes key classes for:

- **Surface**: Drawing pixels, lines, and loading images.
- **Sprite**: Handling animated sprites (like characters or objects).
- **Font**: Drawing text on a surface.
- **Vectors and Matrices**: Performing common math operations for 2D/3D transformations.
- **Timer**: Keeping track of time (useful for animations and frame rate control).

---

## Surface Class

The `Surface` class is like a drawing canvas. It stores pixels and lets you draw, clear the screen, or load images.

### Key Properties

- **`m_Buffer`**: Where the pixels are stored.
- **`m_Width, m_Height`**: Size of the surface (in pixels).
- **`m_Pitch`**: How many pixels are in one row (helps with alignment).

### Key Methods

- **`Surface(int a_Width, int a_Height)`**: Creates a blank surface.
- **`Surface(char* a_File)`**: Loads an image from a file.
- **`Clear(Pixel a_Color)`**: Fills the entire surface with one color.
- **`Plot(int x, int y, Pixel c)`**: Draws a single pixel.
- **`Line(float x1, float y1, float x2, float y2, Pixel c)`**: Draws a line between two points.
- **`Box(int x1, int y1, int x2, int y2, Pixel c)`**: Draws a rectangle outline.
- **`Bar(int x1, int y1, int x2, int y2, Pixel c)`**: Draws a filled rectangle.
- **`CopyTo(Surface* a_Dst, int a_X, int a_Y)`**: Copies the surface onto another surface.

---

## Sprite Class

The `Sprite` class handles animations. A sprite is a series of images (or frames) that can be drawn on the screen, often used for characters or moving objects.

### Key Properties

- **`m_Surface`**: Holds the sprite's image data.
- **`m_NumFrames`**: How many frames (images) the sprite has.
- **`m_CurrentFrame`**: The frame that is currently being shown.

### Key Methods

- **`Sprite(Surface* a_Surface, unsigned int a_NumFrames)`**: Creates a sprite from a surface and splits it into frames.
- **`Draw(Surface* a_Target, int a_X, int a_Y)`**: Draws the current frame on the target surface at the specified location.
- **`DrawScaled(int a_X, int a_Y, int a_Width, int a_Height, Surface* a_Target)`**: Draws the sprite, but scales it to fit the specified width and height.

---

## Font Class

The `Font` class lets you print text on a surface.

### Key Properties

- **`m_Surface`**: The bitmap of all characters in the font.
- **`m_Offset, m_Width`**: Holds the position and width of each character in the font.

### Key Methods

- **`Font(char* a_File, char* a_Chars)`**: Loads the font from a file.
- **`Print(Surface* a_Target, char* a_Text, int a_X, int a_Y)`**: Prints the text at the given position.
- **`Centre(Surface* a_Target, char* a_Text, int a_Y)`**: Centers the text horizontally and prints it at the given vertical position.

---

## Vector and Matrix Classes

These classes are used to do math for moving and rotating objects. They support 2D and 3D graphics.

### vec2 (2D Vector)

- **Properties**: `float x, y`
- **Key Methods**:
  - `length()`: Returns how long the vector is.
  - `dot()`: Finds how much two vectors point in the same direction.

### vec3 (3D Vector)

- **Properties**: `float x, y, z`
- **Key Methods**:
  - `cross()`: Finds a vector perpendicular to two vectors.
  - `normalized()`: Resizes the vector to have a length of 1 (unit vector).

### vec4 (4D Vector)

- **Properties**: `float x, y, z, w`
- **Key Method**:
  - `operator*(const mat4& M)`: Multiplies a 4D vector by a 4x4 matrix.

### mat4 (4x4 Matrix)

Used for rotations, scaling, and translations in 3D graphics.

- **Key Methods**:
  - `identity()`: Returns a matrix with no transformations.
  - `rotate(vec3 v, float a)`: Creates a rotation matrix for rotating around vector `v` by `a` degrees.

---

## Timer Class

The `timer` class is used to measure time, which is helpful for animations or frame timing.

### Key Properties

- **`start`**: Stores when the timer started.

### Key Methods

- **`timer()`**: Starts the timer.
- **`elapsed()`**: Returns how much time has passed since the timer started.
- **`reset()`**: Resets the timer back to zero.

---

## Utility Functions

There are also some handy functions provided in the template:

- **`Rand(float range)`**: Generates a random float between 0 and `range`.
- **`IRand(int range)`**: Generates a random integer between 0 and `range`.

---

## After Word
The Template is a 'quickstart' template, and not meant to be elaborate
performant or complete. 
At some point, and depending on your requirements, you may want to
advance to a more full-fledged library, or you can expand the template
with OpenGL or SDL2 code.

### Credits
Although the template is small and bare bones, it still uses a lot of
code gathered over the years:
- EasyCE's 5x5 bitmap font (primarily used for debugging);
- EasyCE's surface class (with lots of modifications);
- This version of the template uses SDL2 for low-level window handling,
  hopefully improving on the compatibility of earlier versions.

Of course all the credits furthermore go to Jacco Bikker.

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
