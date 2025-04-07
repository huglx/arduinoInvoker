#include "game_logic.h"
#include "constants.h"

GameLogic::GameLogic() {
    currentSpellIndex = 0;
    score = 0;
    isGameActive = false;
}

void GameLogic::initGame(GameMode mode) {
    currentMode = mode;
    score = 0;
    isGameActive = true;
    startTime = millis();
    generateRandomSpell();
}

bool GameLogic::checkSpell(int spellIndex) {
    if (spellIndex == currentSpellIndex) {
        score++;
        return true;
    }
    return false;
}

void GameLogic::getCurrentSpell(int* spell) {
    for (int i = 0; i < SPELL_LENGTH; i++) {
        spell[i] = SPELL_COMBINATIONS[currentSpellIndex][i];
    }
}

void GameLogic::updateGame() {
    if (currentMode == TIMED_MODE && isGameActive) {
        if (millis() - startTime > 60000) { // 60 seconds time limit
            isGameActive = false;
        }
    }
}

int GameLogic::getScore() {
    return score;
}

unsigned long GameLogic::getRemainingTime() {
    if (currentMode == TIMED_MODE && isGameActive) {
        return 60000 - (millis() - startTime);
    }
    return 0;
}

bool GameLogic::isActive() {
    return isGameActive;
}

void GameLogic::resetGame() {
    score = 0;
    isGameActive = false;
    currentSpellIndex = 0;
}

void GameLogic::generateRandomSpell() {
    currentSpellIndex = random(0, MAX_SPELLS);
}

GameMode GameLogic::getCurrentMode() {
    return currentMode;
}

int GameLogic::getCurrentSpellIndex() {
    return currentSpellIndex;
} 