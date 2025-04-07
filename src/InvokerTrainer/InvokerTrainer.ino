#include <Arduino.h>
#include <LiquidCrystal.h>
#include "constants.h"
#include "game_logic.h"
#include "display.h"
#include "sound.h"

// Global objects
GameLogic game;
Display display;
Sound sound;

// Input buffer
char inputBuffer[SPELL_LENGTH + 1];
int inputIndex = 0;

// Menu state
bool inMenu = true;
GameMode selectedMode = FREE_TRAINING;

void setup() {
    // Initialize serial for debugging
    Serial.begin(9600);
    
    // Initialize components
    display.init();
    sound.init();
    
    // Show menu
    display.showMenu();
    sound.playStart();
}

void loop() {
    if (inMenu) {
        handleMenu();
    } else {
        handleGame();
    }
}

void handleMenu() {
    // Check joystick for mode selection
    int x = Esplora.readJoystickX();
    int y = Esplora.readJoystickY();
    
    // Left/Right to change mode
    if (x < 512 - 100) { // Left
        selectedMode = FREE_TRAINING;
        display.showGameMode(selectedMode);
        delay(200);
    } else if (x > 512 + 100) { // Right
        selectedMode = TIMED_MODE;
        display.showGameMode(selectedMode);
        delay(200);
    }
    
    // Press joystick button to start game
    if (Esplora.readJoystickButton() == LOW) {
        inMenu = false;
        game.initGame(selectedMode);
        display.showSpellName(SPELL_NAMES[game.getCurrentSpellIndex()]);
        sound.playStart();
        delay(500);
    }
}

void handleGame() {
    // Check for button presses
    if (Esplora.readButton(BUTTON_QUAS) == LOW) {
        handleInput('Q');
    }
    if (Esplora.readButton(BUTTON_WEX) == LOW) {
        handleInput('W');
    }
    if (Esplora.readButton(BUTTON_EXORT) == LOW) {
        handleInput('E');
    }
    if (Esplora.readButton(BUTTON_INVOKE) == LOW) {
        checkSpell();
    }
    
    // Check for game over
    if (!game.isActive()) {
        display.showGameOver(game.getScore());
        sound.playEnd();
        delay(3000);
        resetGame();
    }
    
    // Update game state
    game.updateGame();
    
    // Show current state on display
    updateDisplay();
    
    // Small delay to prevent button bounce
    delay(50);
}

void handleInput(char input) {
    if (inputIndex < SPELL_LENGTH) {
        inputBuffer[inputIndex++] = input;
        display.showInput(inputBuffer);
    }
}

void checkSpell() {
    if (inputIndex == SPELL_LENGTH) {
        bool correct = game.checkSpell(getSpellIndex(inputBuffer));
        if (correct) {
            sound.playCorrect();
            display.showSuccess();
            game.generateRandomSpell();
            display.showSpellName(SPELL_NAMES[game.getCurrentSpellIndex()]);
        } else {
            sound.playWrong();
            display.showError();
        }
        // Reset input buffer
        inputIndex = 0;
        memset(inputBuffer, 0, sizeof(inputBuffer));
    }
}

int getSpellIndex(const char* input) {
    // Convert input to spell index (Q=1, W=2, E=3)
    int spell[SPELL_LENGTH];
    for (int i = 0; i < SPELL_LENGTH; i++) {
        switch (input[i]) {
            case 'Q': spell[i] = 1; break;
            case 'W': spell[i] = 2; break;
            case 'E': spell[i] = 3; break;
            default: return -1;
        }
    }
    
    // Find matching spell
    for (int i = 0; i < MAX_SPELLS; i++) {
        bool match = true;
        for (int j = 0; j < SPELL_LENGTH; j++) {
            if (spell[j] != SPELL_COMBINATIONS[i][j]) {
                match = false;
                break;
            }
        }
        if (match) return i;
    }
    return -1;
}

void updateDisplay() {
    display.showScore(game.getScore());
    if (game.getCurrentMode() == TIMED_MODE) {
        display.showTime(game.getRemainingTime());
    }
}

void resetGame() {
    game.resetGame();
    inputIndex = 0;
    memset(inputBuffer, 0, sizeof(inputBuffer));
    inMenu = true;
    display.showMenu();
} 