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
    EsploraTFT.setTextSize(0.5);
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
    unsigned long secs = time / 1000;
    if (currentTime != time && lastDisplayedSeconds != secs) {
        currentTime = time;
        lastDisplayedSeconds = secs;
        char timeText[20];
        sprintf(timeText, "Time: %lu s", secs);
        EsploraTFT.fillRect(6, 100, EsploraTFT.width(), 16, 0);
        EsploraTFT.text(timeText, 5, 100);
    }
}

void Display::showGameMode(GameMode mode) {
    if (currentMode != mode) {
        currentMode = mode;
        EsploraTFT.fillRect(0, 55, EsploraTFT.width(), 16, 0);
        EsploraTFT.text("Select Mode:", 5, 30);
        if (mode == FREE_TRAINING) {
            EsploraTFT.text("Free Training", 5, 55);
        } else {
            EsploraTFT.text("Timed Mode", 5, 55);
        }
    }
}

void Display::showSuccess(unsigned long spellCastTime) {
    EsploraTFT.background(0, 0, 0);
    EsploraTFT.stroke(0, 255, 0);
    char text[40];
    sprintf(text, "Your spell time cast is: \n %lu.%02lu sec", spellCastTime / 1000, (spellCastTime % 1000) / 100);
    EsploraTFT.text("Correct!", 5, 5);
    EsploraTFT.text(text, 5, 20);
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
    EsploraTFT.background(0, 0, 0);
    EsploraTFT.text("Invoker Trainer", 5, 5);
    EsploraTFT.text("Select Mode:", 5, 30);
    if (currentMode == FREE_TRAINING) {
        EsploraTFT.text("Free Training", 5, 55);
    } else {
        EsploraTFT.text("Timed Mode", 5, 55);
    }
}

void Display::showGameOver(int finalScore) {
    EsploraTFT.background(0, 0, 0);
    EsploraTFT.text("Game Over!", 5, 5);
    char scoreText[20];
    sprintf(scoreText, "Score: %d", finalScore);
    EsploraTFT.text(scoreText, 5, 30);
} 

void Display::showBestScore(unsigned long avg, int bestScore) {
    unsigned long sec = avg / 1000;
    unsigned long tenths = (avg % 1000) / 100;
    char avgText[35];
    sprintf(avgText, "Fastest training avg: %lu.%02lu sec", sec, tenths);

    char scoreText[35];
    sprintf(scoreText, "Timed mode best: %d", bestScore);
    EsploraTFT.text(avgText, 5, 85);
    EsploraTFT.text(scoreText, 5, 95);

}