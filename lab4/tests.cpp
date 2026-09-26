#include <iostream>
#include <cassert>

// Named constants for key codes
constexpr int KEY_UP = 72;
constexpr int KEY_RIGHT = 77;
constexpr int KEY_LEFT = 75;

// Global stubbed key for the inputProvider seam
static int stubbed_key = -1;

int stubInputProvider() {
    int key = stubbed_key;
    stubbed_key = -1; // consume key
    return key;
}

// Alias main so SnakeGame.cpp can be included as a translation unit
#define main snake_main
#include "../SnakeGame.cpp"
#undef main

int passed = 0;
int total = 0;

void resetGameState() {
    snake.clear();
    obstacles.clear();
    dirX = 1;
    dirY = 0;
    score = 0;
    appleCount = 0;
    gameOver = false;
    paused = false;
    isPowerFruit = false;
    fruit = {15, 15};
    stubbed_key = -1;
    inputProvider = defaultInputProvider;
}

void test_rule_1_score_increase_on_food() {
    total++;
    resetGameState();
    snake.push_back({10, 10});
    snake.push_back({9, 10});
    snake.push_back({8, 10});
    dirX = 1;
    dirY = 0;
    fruit = {11, 10};

    logic();

    if (score == 1) {
        std::cout << "[PASS] Rule 1: Score increases when food is eaten\n";
        passed++;
    } else {
        std::cout << "[FAIL] Rule 1: Expected score 1, got " << score << "\n";
    }
}

void test_rule_2_snake_growth_on_food() {
    total++;
    resetGameState();
    snake.push_back({10, 10});
    snake.push_back({9, 10});
    snake.push_back({8, 10});
    dirX = 1;
    dirY = 0;
    fruit = {11, 10};

    size_t initial_length = snake.size();
    logic();
    size_t new_length = snake.size();

    if (new_length == initial_length + 1) {
        std::cout << "[PASS] Rule 2: Snake length increases by 1 segment\n";
        passed++;
    } else {
        std::cout << "[FAIL] Rule 2: Expected length " << (initial_length + 1) << ", got " << new_length << "\n";
    }
}

void test_rule_3_wall_collision_game_over() {
    total++;
    resetGameState();
    snake.push_back({width - 2, 10});
    snake.push_back({width - 3, 10});
    dirX = 1;
    dirY = 0;

    logic();

    if (gameOver == true) {
        std::cout << "[PASS] Rule 3: Wall collision triggers game over\n";
        passed++;
    } else {
        std::cout << "[FAIL] Rule 3: Expected gameOver=true on wall collision\n";
    }
}

void test_rule_4_self_collision_game_over() {
    total++;
    resetGameState();
    snake.push_back({10, 10});
    snake.push_back({10, 11});
    snake.push_back({9, 11});
    snake.push_back({9, 10});
    dirX = -1;
    dirY = 0;

    logic();

    if (gameOver == true) {
        std::cout << "[PASS] Rule 4: Self collision triggers game over\n";
        passed++;
    } else {
        std::cout << "[FAIL] Rule 4: Expected gameOver=true on self collision\n";
    }
}

void test_rule_5_seam_direction_change_and_reversal_block() {
    total++;
    resetGameState();
    inputProvider = stubInputProvider;

    // Initially moving Right (dirX = 1, dirY = 0)
    dirX = 1;
    dirY = 0;

    // 1. Valid 90-degree turn: Send UP (72) -> dirX becomes 0, dirY becomes -1
    stubbed_key = KEY_UP;
    input();
    assert(dirX == 0 && dirY == -1);

    // 2. Valid 90-degree turn: Send LEFT (75) -> dirX becomes -1, dirY becomes 0
    stubbed_key = KEY_LEFT;
    input();
    assert(dirX == -1 && dirY == 0);

    // 3. Prohibited 180-degree reversal: Send RIGHT (77) while moving Left -> must be ignored!
    stubbed_key = KEY_RIGHT;
    input();
    assert(dirX == -1 && dirY == 0);

    // 4. Valid 90-degree turn: Send UP (72) -> dirX becomes 0, dirY becomes -1
    stubbed_key = KEY_UP;
    input();
    assert(dirX == 0 && dirY == -1);

    // 5. Valid 90-degree turn: Send RIGHT (77) -> dirX becomes 1, dirY becomes 0
    stubbed_key = KEY_RIGHT;
    input();
    assert(dirX == 1 && dirY == 0);

    // 6. Prohibited 180-degree reversal: Send LEFT (75) while moving Right -> must be ignored!
    stubbed_key = KEY_LEFT;
    input();
    assert(dirX == 1 && dirY == 0);

    std::cout << "[PASS] Rule 5 (Seam): Direction updates properly on valid turns and blocks 180-degree reversals\n";
    passed++;
}

int main() {
    std::cout << "========================================\n";
    std::cout << " Running Automated Tests for Snake Game \n";
    std::cout << "========================================\n";
    test_rule_1_score_increase_on_food();
    test_rule_2_snake_growth_on_food();
    test_rule_3_wall_collision_game_over();
    test_rule_4_self_collision_game_over();
    test_rule_5_seam_direction_change_and_reversal_block();
    std::cout << "========================================\n";
    std::cout << " Results: " << passed << " / " << total << " tests passed.\n";
    std::cout << "========================================\n";
    return (passed == total) ? 0 : 1;
}
