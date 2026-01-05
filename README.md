# Snake-Game
🐍 Snake Game – Cross-Platform (C++)

📖 Overview
Snake Game – Cross-Platform is a fun and interactive terminal-based implementation of the classic Snake game, developed as a college project using C++.
It enhances the traditional gameplay with emoji-based graphics, random obstacles, power fruits, and a pause/resume feature, while remaining lightweight and fully terminal-driven.

The game runs on multiple platforms and offers smooth, responsive controls.
Players guide the snake to eat food, grow longer, and score points—while avoiding walls, obstacles, and self-collisions. The challenge increases as the snake grows, making survival progressively harder.

✨ Features
🎮 Core Gameplay

Classic Snake mechanics with increasing difficulty

Snake grows longer after consuming food

Game ends on collision with:

Walls 🧱

Obstacles 🪨

Snake’s own body

🌍 Cross-Platform Support

Built entirely in C++

Runs in terminal environments on supported systems

😄 Emoji-Based Graphics

🐍 Snake

🍎 Normal Food

🍇 Power Fruit

🧱 Walls

🪨 Obstacles

🪨 Random Obstacles

Obstacles are placed randomly on the grid

Adds strategic difficulty to movement planning

⭐ Power Fruit System

Appears randomly after every 4–6 apples

Eating it:

Doubles the snake’s length instantly

Grants bonus score

Normal apples resume afterward

⏸️ Pause / Resume

Press P at any time to pause or resume gameplay

🧮 Score Tracking

Displays current score and maximum score during the session

🔄 Restart & Quit

After game over:

R → Restart

Q → Quit

🎮 Controls
Key	Action
⬅️ ⬆️ ⬇️ ➡️	Move Snake
P	Pause / Resume
Q	Quit Game
R	Restart (after Game Over)
🧠 Gameplay Mechanics

Eat 🍎 and 🍇 to grow and score points

Avoid 🪨 obstacles and 🧱 walls

Snake length increases difficulty

Power fruits provide high-risk, high-reward gameplay

🏗️ System Architecture

The game follows a modular and structured design for clarity and maintainability.

🔧 Game Initialization (setup())

Initializes:

Snake (starting with 3 segments)

Food and power fruits

Obstacles

Score variables

Ensures no overlapping placements

🎹 Input Handling (input())

Handles real-time key input:

Arrow keys → Movement

P → Pause / Resume

Q → Quit

R → Restart

⚙️ Game Logic (logic())

Snake movement and growth

Collision detection:

Walls

Obstacles

Snake body

Food consumption handling

Power fruit effects (size doubling + bonus score)

🎨 Rendering (draw())

Redraws the grid every frame

Displays:

Walls 🧱

Snake 🟩

Apples 🍎

Power Fruits 🍇

Obstacles 🪨

Shows score, direction, and game status

🍎 Random Placement (placeFood())

Randomly places food and obstacles

Prevents overlap with snake and obstacles

Triggers power fruits after a few apples

🔌 Terminal Input / Output

Uses termios for non-buffered, real-time input

ANSI escape sequences for:

Screen clearing

Smooth frame updates

Emoji rendering depends on terminal font support

🔁 Game Flow Overview

Initialize game state

Start main loop:

Read input

Update logic

Detect collisions

Render frame

Control speed using timed delays

Pause anytime with P

End game on collision

🛠️ Technical Implementation
Language

C++

Data Structures

Snake stored as a vector of coordinate pairs

Obstacles stored dynamically using vectors

Game Timing

Controlled using usleep(150000) for balanced speed

Memory Management

Efficient use of vectors for dynamic resizing

🧪 Installation & Compilation
Prerequisites

C++ Compiler (g++)

Terminal environment (Linux / macOS recommended)

Build
g++ -o snake_game main.cpp

Run
./snake_game

🎯 Objective

Eat 🍎 and 🍇

Avoid 🪨 and 🧱

Grow your snake

Achieve the highest possible score

🧩 Design Patterns & Best Practices
Design Patterns

Singleton Pattern – Centralized game state

Strategy Pattern – Dynamic movement handling

Best Practices

Modular functions (setup, input, logic, draw)

Constants for dimensions and speed

Clear separation of logic and rendering

Clean and intuitive game loop

🚀 Future Enhancements

GUI version using SFML / SDL

Multiplayer mode

Additional power-ups (speed boost, shield)

Custom grid size and difficulty

Persistent high-score system

Sound effects and background music

👥 Team Contributors

👩‍💻 Bhavika

👩‍💻 Zalak

👩‍💻 Megha

👩‍💻 Hardi

We worked collaboratively on all aspects of the project, including game logic, UI design, input handling, optimization, and feature development such as the Pause and Power Fruit systems.
