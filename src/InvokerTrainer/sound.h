#ifndef SOUND_H
#define SOUND_H

#include <Arduino.h>
#include <Esplora.h>
#include "constants.h"

class Sound {
public:
    Sound();
    
    // Initialize sound
    void init();
    
    // Play correct sound
    void playCorrect();
    
    // Play wrong sound
    void playWrong();
    
    // Play game start sound
    void playStart();
    
    // Play game end sound
    void playEnd();
    
private:
    void playTone(int frequency, int duration);
};

#endif 