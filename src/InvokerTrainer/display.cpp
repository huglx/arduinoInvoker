#include "display.h"

Display::Display() {
    currentSpellName[0] = '\0';
    currentInput[0] = '\0';
    currentScore = -1;
    currentTime = 0;
    currentMode = FREE_TRAINING;
    isMenuShown = false;
}

void Display::init() {
    EsploraTFT.begin();
    EsploraTFT.background(0, 0, 0);
    EsploraTFT.setTextSize(2);
    EsploraTFT.stroke(255, 255, 255);
    clear();
}

void Display::clear() {
    EsploraTFT.background(0, 0, 0);
    currentSpellName[0] = '\0';
    currentInput[0] = '\0';
    currentScore = -1;
    currentTime = 0;
    isMenuShown = false;
}

void Display::showSpellName(const char* spellName) {
    if (strcmp(currentSpellName, spellName) != 0) {
        strcpy(currentSpellName, spellName);
        EsploraTFT.background(0, 0, 0);
        EsploraTFT.text("Spell:", 5, 5);
        EsploraTFT.text(currentSpellName, 5, 30);
    }
}

void Display::showInput(const char* input) {
    if (strcmp(currentInput, input) != 0) {
        strcpy(currentInput, input);
        EsploraTFT.background(0, 0, 0);
        EsploraTFT.text("Input:", 5, 5);
        EsploraTFT.text(currentInput, 5, 30);
    }
}

void Display::showScore(int score) {
    if (currentScore != score) {
        currentScore = score;
        char scoreText[20];
        sprintf(scoreText, "Score: %d", score);
        EsploraTFT.text(scoreText, 5, 55);
    }
}

void Display::showTime(unsigned long time) {
    if (currentTime != time) {
        currentTime = time;
        char timeText[20];
        sprintf(timeText, "Time: %lu s", time / 1000);
        EsploraTFT.background(0, 0, 0);
        EsploraTFT.text(timeText, 5, 5);
    }
}

void Display::showGameMode(GameMode mode) {
    if (currentMode != mode) {
        currentMode = mode;
        EsploraTFT.background(0, 0, 0);
        EsploraTFT.text("Select Mode:", 5, 5);
        if (mode == FREE_TRAINING) {
            EsploraTFT.text("Free Training", 5, 30);
        } else {
            EsploraTFT.text("Timed Mode", 5, 30);
        }
    }
}

void Display::showSuccess() {
    EsploraTFT.background(0, 0, 0);
    EsploraTFT.stroke(0, 255, 0);
    EsploraTFT.text("Correct!", 5, 5);
    delay(1000);
    EsploraTFT.stroke(255, 255, 255);
    clear();
}

void Display::showError() {
    EsploraTFT.background(0, 0, 0);
    EsploraTFT.stroke(255, 0, 0);
    EsploraTFT.text("Wrong!", 5, 5);
    delay(1000);
    EsploraTFT.stroke(255, 255, 255);
    clear();
}

void Display::showMenu() {
    if (!isMenuShown) {
        isMenuShown = true;
        EsploraTFT.background(0, 0, 0);
        EsploraTFT.text("Invoker Trainer", 5, 5);
        EsploraTFT.text("Select Mode:", 5, 30);
        if (currentMode == FREE_TRAINING) {
            EsploraTFT.text("Free Training", 5, 55);
        } else {
            EsploraTFT.text("Timed Mode", 5, 55);
        }
    }
}

void Display::showGameOver(int finalScore) {
    EsploraTFT.background(0, 0, 0);
    EsploraTFT.text("Game Over!", 5, 5);
    char scoreText[20];
    sprintf(scoreText, "Score: %d", finalScore);
    EsploraTFT.text(scoreText, 5, 30);
} 