#include "sound.h"

Sound::Sound() {
}

void Sound::init() {
    // No initialization needed for Esplora buzzer
}

void Sound::playCorrect() {
    playTone(CORRECT_TONE, TONE_DURATION);
}

void Sound::playWrong() {
    playTone(WRONG_TONE, TONE_DURATION);
}

void Sound::playStart() {
    // playTone(800, 200);
    // delay(100);
    // playTone(1000, 200);
    // delay(100);
    // playTone(1200, 200);
}

void Sound::playEnd() {
    // playTone(1200, 200);
    // delay(100);
    // playTone(1000, 200);
    // delay(100);
    // playTone(800, 200);
}

void Sound::playTone(int frequency, int duration) {
    // Esplora.tone(frequency, duration);
    // delay(duration);
    // Esplora.noTone();
} 