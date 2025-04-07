#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <Arduino.h>
#include "constants.h"

class GameLogic {
private:
    int currentSpell[MAX_SPELLS];
    int currentSpellIndex;
    GameMode currentMode;
    unsigned long startTime;
    int score;
    bool isGameActive;

public:
    GameLogic();
    
    // Initialize game with specific mode
    void initGame(GameMode mode);
    
    // Check if current input matches the spell
    bool checkSpell(int spellIndex);
    
    // Get current spell combination
    void getCurrentSpell(int* spell);
    
    // Update game state
    void updateGame();
    
    // Get current score
    int getScore();
    
    // Get remaining time (for timed mode)
    unsigned long getRemainingTime();
    
    // Check if game is active
    bool isActive();
    
    // Reset game state
    void resetGame();
    
    // Generate random spell
    void generateRandomSpell();
    
    // Get current game mode
    GameMode getCurrentMode();
    
    // Get current spell index
    int getCurrentSpellIndex();
};

#endif 