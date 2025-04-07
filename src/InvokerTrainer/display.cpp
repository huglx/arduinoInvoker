#include "display.h"

Display::Display() {
}

void Display::init() {
    Esplora.writeRGB(0, 0, 0); // Turn off RGB LED
    clear();
}

void Display::clear() {
    Esplora.writeDisplay("                ", 0); // Clear first line
    Esplora.writeDisplay("                ", 1); // Clear second line
}

void Display::showSpellName(const char* spellName) {
    char line[17];
    snprintf(line, sizeof(line), "Spell: %s", spellName);
    Esplora.writeDisplay(line, 0);
}

void Display::showInput(const char* input) {
    char line[17];
    snprintf(line, sizeof(line), "Input: %s", input);
    Esplora.writeDisplay(line, 1);
}

void Display::showScore(int score) {
    char line[17];
    snprintf(line, sizeof(line), "Score: %d", score);
    Esplora.writeDisplay(line, 1);
}

void Display::showTime(unsigned long time) {
    char line[17];
    snprintf(line, sizeof(line), "Time: %lu s", time / 1000);
    Esplora.writeDisplay(line, 1);
}

void Display::showGameMode(GameMode mode) {
    clear();
    Esplora.writeDisplay("Select Mode:", 0);
    if (mode == FREE_TRAINING) {
        Esplora.writeDisplay("Free Training", 1);
    } else {
        Esplora.writeDisplay("Timed Mode", 1);
    }
}

void Display::showSuccess() {
    Esplora.writeDisplay("Correct!", 1);
    Esplora.writeRGB(0, 255, 0); // Green LED
    delay(1000);
    Esplora.writeRGB(0, 0, 0); // Turn off LED
}

void Display::showError() {
    Esplora.writeDisplay("Wrong!", 1);
    Esplora.writeRGB(255, 0, 0); // Red LED
    delay(1000);
    Esplora.writeRGB(0, 0, 0); // Turn off LED
}

void Display::showMenu() {
    clear();
    Esplora.writeDisplay("Invoker Trainer", 0);
    Esplora.writeDisplay("Press Joystick", 1);
}

void Display::showGameOver(int finalScore) {
    clear();
    Esplora.writeDisplay("Game Over!", 0);
    char line[17];
    snprintf(line, sizeof(line), "Score: %d", finalScore);
    Esplora.writeDisplay(line, 1);
} 