# Lab 4 Report

| | |
|---|---|
| Repository | BhavikaSainani/Snake-Game |
| Base tag | `lab4-base` at commit `7340036` |
| Pull request | ___ |

---

## 1. Five rules — [5]

Written before opening the source. Behaviour, with an observable outcome.

| # | Rule |
|---|---|
| 1 | When the snake's head reaches the food coordinates, the score increases. |
| 2 | Eating food causes the snake's length to increase by one segment. |
| 3 | When the snake's head hits the boundary wall, the game ends (game over). |
| 4 | When the snake's head runs into its own body, the game ends (game over). |
| 5 | Changing the movement direction updates the snake's heading, but reversing directly into the opposite direction is prohibited/ignored. |

If you could not state one of your own game's rules without going to look, say which and
why. It costs no marks.

None. All five behavioral rules were formulated directly from standard Snake gameplay mechanics and memory before inspecting the codebase.

---

## 2. What you could test, and what stopped you — [10]

No source changes in this part. Every `file:line` below is a line in `lab4-base`.

| # | Rule | Test written? | Blocking dependency (`file:line` + what it is) |
|---|---|---|---|
| 1 | When the snake's head reaches the food coordinates, the score increases. | Yes | None (exercised via `logic()` with direct state initialization). |
| 2 | Eating food causes the snake's length to increase by one segment. | Yes | None (exercised via `logic()` with direct state initialization). |
| 3 | When the snake's head hits the boundary wall, the game ends (game over). | Yes | None (exercised via `logic()` with direct state initialization). |
| 4 | When the snake's head runs into its own body, the game ends (game over). | Yes | None (exercised via `logic()` with direct state initialization). |
| 5 | Changing the movement direction updates the snake's heading, but reversing directly into the opposite direction is prohibited/ignored. | No | `SnakeGame.cpp:203` (and `SnakeGame.cpp:206`) — `_kbhit()` and `_getch()` / `kbhit()` and `getch()` called directly inside `input()`, reading synchronously from hardware/terminal buffer with no parameter or interface seam to supply keystrokes. |

> **Rules testable without modifying the source: 4 / 5**

`SnakeGame.cpp` implements core game update rules inside `logic()`, which operates on mutable global state (`snake`, `fruit`, `score`, `gameOver`, `dirX`, `dirY`). Because `logic()` takes no parameters and does not directly block on I/O, Rules 1 through 4 can be directly exercised in a test harness by populating globals and asserting on post-execution state. In contrast, Rule 5 is coupled entirely within `input()` (`SnakeGame.cpp:201-236`), which polls OS-level terminal input via `_kbhit()` / `_getch()` without an abstraction or parameter seam to pass inputs programmatically.

---

## 3. Coverage, and what it missed — [6]

| | |
|---|---|
| Line coverage | 23.78 % |
| Branch coverage | 20.63 % |
| Command used | `g++ --coverage -O0 -g -o lab4/tests.exe lab4/test_part_b.cpp; .\lab4\tests.exe; gcov -b test_part_b.gcno` |

**One rule that is executed by the suite but not verified by it:**

| | |
|---|---|
| Rule | When food is eaten, a new fruit is spawned at a valid coordinate inside the boundaries without overlapping snake segments or obstacles. |
| Line that runs | `SnakeGame.cpp:283` (invokes `placeFruit()`, which executes `SnakeGame.cpp:92-104`) |
| The assertion that is missing | `assert(fruit.first > 0 && fruit.first < width - 1 && fruit.second > 0 && fruit.second < height - 1);` and `assert(std::find(snake.begin(), snake.end(), fruit) == snake.end());` |

During the execution of Rule 1 and Rule 2 tests (`test_rule_1_score_increase_on_food` and `test_rule_2_snake_growth_on_food`), `logic()` detects head-on-fruit collision and automatically executes `placeFruit()` at `SnakeGame.cpp:283`. This executes the random fruit relocation loop (lines 92–104). However, the test assertions only verify `score` and `snake.size()`, completely ignoring whether the regenerated `fruit` coordinates are valid and non-colliding.

---

## 4. The seam — [10]

| | |
|---|---|
| Rule made testable | Rule 5: Changing the movement direction updates the snake's heading, but reversing directly into the opposite direction is prohibited/ignored. |
| Commit 1 (seam) | `86aa3f0` |
| Commit 2 (test) | `205f17d` |
| Seam kind | object |
| Enabling point | `inputProvider` function pointer definition at `SnakeGame.cpp:225` and invocation inside `input()` at `SnakeGame.cpp:228` |
| What production code gave up | Production code gave up direct inlined invocation of console I/O, incurring a single indirect function pointer dereference per game loop tick (a negligible sub-nanosecond cost relative to the 150ms frame sleep), and introduced a mutable function pointer into the global scope. |

---

## 5. The double — [4]

| | |
|---|---|
| What you passed through the seam | stub |
| The method under test | `void input()` |

The collaborator (`inputProvider`) was asked a question because the method under test queries it for a return value (the next key/scan code) to decide state transitions rather than telling it to perform an action. Because it provides canned answers to those queries without recording calls or verifying interactions, it is classified as a stub.

---

## 6. Two smells in your own tests — [5]

| | Smell | `file:line` | One-line fix |
|---|---|---|---|
| 1 | General fixture | `lab4/tests.cpp:26` | Pass what each test needs as a parameter or state struct instead of resetting shared global variables. |
| 2 | Eager test | `lab4/tests.cpp:121` | Split the multiple directional turn and reversal scenarios into distinct single-behavior test functions. |

---
