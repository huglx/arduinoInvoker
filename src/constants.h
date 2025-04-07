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
const char* SPELL_NAMES[MAX_SPELLS] = {
    "Cold Snap",        // QQQ
    "Ghost Walk",       // QQW
    "Ice Wall",         // QQE
    "EMP",             // WWW
    "Tornado",         // WWQ
    "Alacrity",        // WWE
    "Sun Strike",      // EEE
    "Forge Spirit",    // EEQ
    "Chaos Meteor",    // EEW
    "Deafening Blast"  // QWE
};

// Spell combinations (Q=1, W=2, E=3)
const int SPELL_COMBINATIONS[MAX_SPELLS][SPELL_LENGTH] = {
    {1, 1, 1},  // Cold Snap
    {1, 1, 2},  // Ghost Walk
    {1, 1, 3},  // Ice Wall
    {2, 2, 2},  // EMP
    {2, 2, 1},  // Tornado
    {2, 2, 3},  // Alacrity
    {3, 3, 3},  // Sun Strike
    {3, 3, 1},  // Forge Spirit
    {3, 3, 2},  // Chaos Meteor
    {1, 2, 3}   // Deafening Blast
};

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