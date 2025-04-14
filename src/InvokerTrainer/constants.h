#ifndef CONSTANTS_H
#define CONSTANTS_H

// Button mappings for Arduino Esplora
#define BUTTON_QUAS 2    // Button 1
#define BUTTON_WEX  3    // Button 2
#define BUTTON_EXORT 4   // Button 3
#define BUTTON_INVOKE 1  // Button 4

// Spell combinations
#define MAX_SPELLS 10
#define SPELL_LENGTH 3

// Spell names
extern const char* SPELL_NAMES[MAX_SPELLS];

// Spell combinations (Q=1, W=2, E=3)
extern const int SPELL_COMBINATIONS[MAX_SPELLS][SPELL_LENGTH];

// Pre-calculated element counts for each spell (Q, W, E counts)
extern const int SPELL_ELEMENT_COUNTS[MAX_SPELLS][3];

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