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
🔧 Game Initialization (setup())

Initializes snake, food, obstacles, and scores

Starts snake with three body segments

Ensures no overlapping placements

🎹 Input Handling (input())

Arrow keys → Movement

P → Pause / Resume

Q → Quit

R → Restart

⚙️ Game Logic (logic())

Snake movement and growth

Collision detection

Food and power fruit handling

🎨 Rendering (draw())

Redraws the game board every frame

Displays snake, food, obstacles, and walls

Shows score and game status

🍎 Random Placement (placeFood())

Places food and obstacles randomly

Prevents overlap

Triggers power fruits after a few apples

🔌 Terminal Input / Output

Uses termios for non-buffered input

ANSI escape sequences for screen clearing

Smooth frame rendering

🔁 Game Flow Overview

Initialize game state

Process input

Update game logic

Render frame

Control speed and timing

🛠️ Technical Implementation
Language

C++

Data Structures

Snake stored as a vector of coordinate pairs

Obstacles stored dynamically

Game Timing

Controlled using usleep(150000)

Memory Management

Efficient vector-based storage

🧪 Installation & Compilation
Prerequisites

C++ Compiler (g++)

Terminal environment

Build
g++ -o snake_game main.cpp

Run
./snake_game

🎯 Objective

Eat 🍎 and 🍇

Avoid 🪨 and 🧱

Grow your snake

Maximize your score

🧩 Design Patterns & Best Practices
Design Patterns

Singleton Pattern

Strategy Pattern

Best Practices

Modular code structure

Clear separation of logic and rendering

Efficient memory usage

Intuitive game loop

🚀 Future Enhancements

GUI using SFML / SDL

Multiplayer mode

Additional power-ups

Custom grid size and difficulty

Persistent high scores

Sound effects

👥 Team Contributors

👩‍💻 Bhavika

👩‍💻 Zalak

👩‍💻 Megha

👩‍💻 Hardi
