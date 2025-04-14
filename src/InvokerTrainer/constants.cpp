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

// Pre-calculated element counts for each spell (Q, W, E counts)
const int SPELL_ELEMENT_COUNTS[MAX_SPELLS][3] = {
    {3, 0, 0},  // Cold Snap (QQQ)
    {2, 1, 0},  // Ghost Walk (QQW)
    {2, 0, 1},  // Ice Wall (QQE)
    {0, 3, 0},  // EMP (WWW)
    {1, 2, 0},  // Tornado (WWQ)
    {0, 2, 1},  // Alacrity (WWE)
    {0, 0, 3},  // Sun Strike (EEE)
    {1, 0, 2},  // Forge Spirit (EEQ)
    {0, 1, 2},  // Chaos Meteor (EEW)
    {1, 1, 1}   // Deafening Blast (QWE)
}; 