#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <Esplora.h>
#include "constants.h"
#include <SPI.h>
#include <TFT.h> 

class Display {
private:
    char currentSpellName[20];
    char currentInput[20];
    int currentScore;
    unsigned long currentTime;
    GameMode currentMode;
    bool isMenuShown;
    unsigned long lastDisplayedSeconds = 0;
    
public:
    Display();
    
    // Initialize display
    void init();
    
    // Clear display
    void clear();
    
    // Display current spell name
    void showSpellName(const char* spellName);
    
    // Display input combination
    void showInput(const char* input);
    
    // Display score
    void showScore(int score);
    
    // Display time remaining
    void showTime(unsigned long time);
    
    // Display game mode
    void showGameMode(GameMode mode);
    
    // Display success message
    void showSuccess(unsigned long spellCastTime);
    
    // Display error message
    void showError();
    
    // Display menu
    void showMenu();
    
    // Display game over
    void showGameOver(int finalScore);

    void clearArea(int y, int height);

    void clearAllArea();

    void showBestScore(unsigned long avg, int bestScore);
};

#endif 