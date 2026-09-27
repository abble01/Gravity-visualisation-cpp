# Gravity Visualisation (C++)

This is my long-term Physics for Year 12. The goal is to build a gravity simulator that models how planets and stars pull on each other. 

I originally built a prototype of this in Python, but I am rewriting it in C++ to make it run much faster and handle way more objects at the same time.

## Project Files

* main.cpp - The main loop that runs the program.
* Body.h - Defines what a "Body" is (its mass, size, position, and speed).
* Physics.cpp / Physics.h - Where the actual gravity math and movement calculations happen.
* UI.h - Handles how the simulation looks on screen and user inputs.

## What I'm Planning to Build (My Goals)

### Step 1: The Basics (What I'm doing now)
* Get the basic C++ code working and clean up the old Python logic.
* Get standard Newtonian gravity working so objects actually attract each other.

### Step 2: Adding Features
* Make a simple user interface so I can click to add or change planets while the simulation is running.
* Add orbit lines so you can see the path a planet has taken.
* Fix any glitches where planets fly off at infinite speeds if they collide.

### Step 3: Advanced Stuff (End of Year 12)
* Try adding Einstein's General Relativity concepts. Instead of just basic gravity, I want to try adding math that simulates how massive objects warp space (like black holes or the orbit of Mercury).
* To make the measurement of orbits and eliminate any numerical drift.

## How to Run It
This project is set up using Microsoft Visual Studio. Open the `Gravity_visualisation.slnx` file in Visual Studio to load the project and press the Run button.
