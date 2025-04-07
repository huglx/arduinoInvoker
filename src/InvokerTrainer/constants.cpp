#include "constants.h"

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