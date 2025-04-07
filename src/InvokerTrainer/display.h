#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <Esplora.h>
#include "constants.h"

class Display {
private:
    char currentSpellName[20];
    char currentInput[20];
    int currentScore;
    unsigned long currentTime;
    GameMode currentMode;
    bool isMenuShown;
    
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
    void showSuccess();
    
    // Display error message
    void showError();
    
    // Display menu
    void showMenu();
    
    // Display game over
    void showGameOver(int finalScore);
};

#endif 