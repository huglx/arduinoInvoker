#include "game_logic.h"
#include "constants.h"
#include <EEPROM.h>

GameLogic::GameLogic() {
    currentSpellIndex = 0;
    score = 0;
    isGameActive = false;
    EEPROMWritelong(AVG_ADDR, 0);
    EEPROM.write(TIMED_BEST_SCORE_ADDR, 0);
}

void GameLogic::initGame(GameMode mode) {
    currentMode = mode;
    score = 0;
    totalSpellTime = 0;
    isGameActive = true;
    startTime = millis();
    generateRandomSpell();
}

bool GameLogic::checkSpell(int spellIndex) {
    if (spellIndex == currentSpellIndex) {
        score++;
        unsigned long now = millis();
        totalSpellTime += (now - lastSpellTime);
        //lastSpellTime = now;
        return true;
    }
    return false;
}

void GameLogic::getCurrentSpell(int* spell) {
    for (int i = 0; i < SPELL_LENGTH; i++) {
        spell[i] = SPELL_COMBINATIONS[currentSpellIndex][i];
    }
}


unsigned long GameLogic::getAvgSpellTime() {
    if(score == 0) return 0;
    return totalSpellTime / score;
}

unsigned long GameLogic::getCurrentSpellTime() {
    return millis() - lastSpellTime;
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
    if(currentMode == FREE_TRAINING) {
        saveAvgToEEPROM();
    }

    if(currentMode == TIMED_MODE) {
        saveBestScoreToEEPROM();
    }
    score = 0;
    isGameActive = false;
    currentSpellIndex = 0;
}

void GameLogic::generateRandomSpell() {
    unsigned long now = millis();
    randomSeed(now);
    lastSpellTime = now;
    currentSpellIndex = random(0, MAX_SPELLS);
}

GameMode GameLogic::getCurrentMode() {
    return currentMode;
}

int GameLogic::getCurrentSpellIndex() {
    return currentSpellIndex;
} 

void GameLogic::saveAvgToEEPROM() {
    unsigned long best = getAvgFromEEPROM();
    if(best == 0 || best > getAvgSpellTime()) {
        EEPROMWritelong(AVG_ADDR, getAvgSpellTime());
    }

}

void GameLogic::saveBestScoreToEEPROM() {
    int best = getBestScoreFromEEPROM();
    if(best < score) {
        EEPROM.put(TIMED_BEST_SCORE_ADDR, score);
    }
}

long GameLogic::EEPROMReadlong(long address) {
    long four = EEPROM.read(address);
    long three = EEPROM.read(address + 1);
    long two = EEPROM.read(address + 2);
    long one = EEPROM.read(address + 3);

    return ((four << 0) & 0xFF) + ((three << 8) & 0xFFFF) + ((two << 16) & 0xFFFFFF) + ((one << 24) & 0xFFFFFFFF);
}

void GameLogic::EEPROMWritelong(int address, long value) {
    byte four = (value & 0xFF);
    byte three = ((value >> 8) & 0xFF);
    byte two = ((value >> 16) & 0xFF);
    byte one = ((value >> 24) & 0xFF);

    EEPROM.write(address, four);
    EEPROM.write(address + 1, three);
    EEPROM.write(address + 2, two);
    EEPROM.write(address + 3, one);
}

unsigned long GameLogic::getAvgFromEEPROM() {
    unsigned long bestAvg = EEPROMReadlong(AVG_ADDR);
    if(isnan(bestAvg) )
        return 0;
    return bestAvg;
}

int GameLogic::getBestScoreFromEEPROM() {
    int best = EEPROM.read(TIMED_BEST_SCORE_ADDR);
    if(isnan(best))
        return 0;
    return best;
}