#ifndef CONSTANTS_H
#define CONSTANTS_H

// Button mappings for Arduino Esplora
#define BUTTON_QUAS 1    // Button 1
#define BUTTON_WEX  2    // Button 2
#define BUTTON_EXORT 3   // Button 3
#define BUTTON_INVOKE 4  // Button 4

// Spell combinations
#define MAX_SPELLS 10
#define SPELL_LENGTH 3

// Spell names
extern const char* SPELL_NAMES[MAX_SPELLS];

// Spell combinations (Q=1, W=2, E=3)
extern const int SPELL_COMBINATIONS[MAX_SPELLS][SPELL_LENGTH];

// Game modes
enum GameMode {
    FREE_TRAINING,
    TIMED_MODE
};

// Display settings
#define LCD_WIDTH 16
#define LCD_HEIGHT 2

// Sound settings
#define BUZZER_PIN 3
#define CORRECT_TONE 1000
#define WRONG_TONE 500
#define TONE_DURATION 200

#endif 