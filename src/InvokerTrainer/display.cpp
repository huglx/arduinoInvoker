#include "display.h"
#include "constants.h"

Display::Display() {
    currentSpellName[0] = '\0';
    currentInput[0] = '\0';
    currentScore = -1;
    currentTime = 0;
    currentMode = FREE_TRAINING;
    isMenuShowns = false;
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

void Display::clearArea(int y, int height) {
    EsploraTFT.fill(0, 0, 0);
    EsploraTFT.rect(0, y, EsploraTFT.width(), height);
}

void Display::showSpellName(const char* spellName) {
    clearArea(SPELL_TEXT_Y, LINE_HEIGHT);
    if (strcmp(currentSpellName, spellName) != 0) {
        strcpy(currentSpellName, spellName);
        EsploraTFT.text(currentSpellName, 0, SPELL_TEXT_Y);
    }
}

void Display::showInput(const char* input) {
    clearArea(INPUT_TEXT_Y, LINE_HEIGHT);
    if (strcmp(currentInput, input) != 0) {
        strcpy(currentInput, input);
        EsploraTFT.text(currentInput, 0, INPUT_TEXT_Y);
    }
}

void Display::showScore(int score) {
    clearArea(SCORE_Y, LINE_HEIGHT);
    if (currentScore != score) {
        currentScore = score;
        char scoreText[20];
        sprintf(scoreText, "Score: %d", score);
        EsploraTFT.text(scoreText, 0, SCORE_Y);
    }
}

void Display::showTime(unsigned long time) {
    if (currentTime != time) {
        currentTime = time;
        char timeText[20];
        sprintf(timeText, "Time: %lu s", time / 1000);
        clearArea(TIME_Y, LINE_HEIGHT);
        EsploraTFT.text(timeText, 0, TIME_Y);
    }
}

void Display::showGameMode(GameMode mode) {
    clearArea(MODE_Y, LINE_HEIGHT);
    if (currentMode != mode) {
        currentMode = mode;
        const char* modeText = (mode == FREE_TRAINING) ? "Free Training" : "Timed Mode";
        EsploraTFT.text(modeText, 0, MODE_Y);
    }
}

void Display::showSuccess() {
    clearArea(SCORE_Y, LINE_HEIGHT);
    EsploraTFT.stroke(0, 255, 0);
    EsploraTFT.text("Correct!", 0, SCORE_Y);
    delay(1000);
    EsploraTFT.stroke(255, 255, 255);
}

void Display::showError() {
    clearArea(SCORE_Y, LINE_HEIGHT);
    EsploraTFT.stroke(255, 0, 0);
    EsploraTFT.text("Wrong!", 0, SCORE_Y);
    delay(1000);
    EsploraTFT.stroke(255, 255, 255);
}

void Display::showMenu() {
    if (!isMenuShown) {
        isMenuShown = true;
        EsploraTFT.text("Invoker Trainer", 0, TITLE_Y);
        EsploraTFT.text("Select Mode:", 0, MODE_Y);
        if (currentMode == FREE_TRAINING) {
            EsploraTFT.text("Free Training", 0, MODE_Y + LINE_HEIGHT);
        } else {
            EsploraTFT.text("Timed Mode", 0, MODE_Y + LINE_HEIGHT);
        }
    }
}

void Display::showGameOver(int finalScore) {
    clear();
    EsploraTFT.text("Game Over!", 0, TITLE_Y);
    char scoreText[20];
    sprintf(scoreText, "Final Score: %d", finalScore);
    EsploraTFT.text(scoreText, 0, SCORE_Y);
} 