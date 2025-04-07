# Invoker Trainer for Arduino Esplora

A training simulator for Dota 2 players to practice Invoker spell combinations using Arduino Esplora.

## Features

- Practice Invoker spell combinations (Q, W, E + Invoke)
- Two game modes:
  - Free Training: Practice without time pressure
  - Timed Mode: Complete as many combinations as possible within time limit
- Visual feedback on LCD display
- Audio feedback for correct/incorrect inputs
- Score tracking

## Hardware Requirements

- Arduino Esplora
- LCD Display (16x2)
- Buzzer

## Pin Connections

- LCD Display:
  - RS: Digital 8
  - Enable: Digital 9
  - D4: Digital 4
  - D5: Digital 5
  - D6: Digital 6
  - D7: Digital 7
- Buzzer: Digital 3

## Button Mapping

- Button 1: Quas (Q)
- Button 2: Wex (W)
- Button 3: Exort (E)
- Button 4: Invoke (R)

## Spell Combinations

1. Cold Snap (QQQ)
2. Ghost Walk (QQW)
3. Ice Wall (QQE)
4. EMP (WWW)
5. Tornado (WWQ)
6. Alacrity (WWE)
7. Sun Strike (EEE)
8. Forge Spirit (EEQ)
9. Chaos Meteor (EEW)
10. Deafening Blast (QWE)

## Installation

1. Clone this repository
2. Open the project in Arduino IDE
3. Install required libraries:
   - LiquidCrystal
4. Upload to Arduino Esplora

## Usage

1. Power on the device
2. Select game mode using the joystick
3. Practice spell combinations using the buttons
4. Press Invoke (R) to check your combination
5. View your score and progress on the LCD display

## Development

The project is organized into several components:

- `constants.h`: Defines spell combinations and hardware mappings
- `game_logic.h`: Implements game mechanics and spell checking
- `display.h`: Manages LCD output
- `sound.h`: Handles audio feedback
- `InvokerTrainer.ino`: Main program file

## License

This project is open source and available under the MIT License. 