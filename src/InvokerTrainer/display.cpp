#include "display.h"

Display::Display() {
}

void Display::init() {
    screen.begin();
    screen.background(0, 0, 0);
    screen.setTextSize(2);
    screen.stroke(255, 255, 255);
    clear();
}

void Display::clear() {
    screen.background(0, 0, 0);
}

void Display::showSpellName(const char* spellName) {
    screen.background(0, 0, 0);
    screen.text("Spell:", 5, 5);
    screen.text(spellName, 5, 30);
}

void Display::showInput(const char* input) {
    screen.background(0, 0, 0);
    screen.text("Input:", 5, 5);
    screen.text(input, 5, 30);
}

void Display::showScore(int score) {
    char scoreText[20];
    sprintf(scoreText, "Score: %d", score);
    screen.background(0, 0, 0);
    screen.text(scoreText, 5, 5);
}

void Display::showTime(unsigned long time) {
    char timeText[20];
    sprintf(timeText, "Time: %lu s", time / 1000);
    screen.background(0, 0, 0);
    screen.text(timeText, 5, 5);
}

void Display::showGameMode(GameMode mode) {
    screen.background(0, 0, 0);
    screen.text("Select Mode:", 5, 5);
    if (mode == FREE_TRAINING) {
        screen.text("Free Training", 5, 30);
    } else {
        screen.text("Timed Mode", 5, 30);
    }
}

void Display::showSuccess() {
    screen.background(0, 0, 0);
    screen.stroke(0, 255, 0);
    screen.text("Correct!", 5, 5);
    delay(1000);
    screen.stroke(255, 255, 255);
}

void Display::showError() {
    screen.background(0, 0, 0);
    screen.stroke(255, 0, 0);
    screen.text("Wrong!", 5, 5);
    delay(1000);
    screen.stroke(255, 255, 255);
}

void Display::showMenu() {
    screen.background(0, 0, 0);
    screen.text("Invoker Trainer", 5, 5);
    screen.text("Press Joystick", 5, 30);
}

void Display::showGameOver(int finalScore) {
    screen.background(0, 0, 0);
    screen.text("Game Over!", 5, 5);
    char scoreText[20];
    sprintf(scoreText, "Score: %d", finalScore);
    screen.text(scoreText, 5, 30);
} 