#include <Keypad.h>

// 5 rows x 4 columns matrix
const byte ROWS = 5;  // Five rows
const byte COLS = 4;  // Four columns

// Based on your physical layout:
// Row 1 (top):    F1    F2    #     *
// Row 2:          1     2     3     UP
// Row 3:          4     5     6     DOWN
// Row 4:          7     8     9     ESC
// Row 5 (bottom): LEFT  0     RIGHT EXIT
//
// We need to map these to the actual matrix positions
// Press each button and note which letter appears,
// then replace the letters with the actual button names

char keys[ROWS][COLS] = {
  {'A', 'B', 'C', 'D'},     // Row 1 (pin 22) - F1, F2, #, *
  {'E', 'F', 'G', 'H'},     // Row 2 (pin 23) - 1, 2, 3, UP
  {'I', 'J', 'K', 'L'},     // Row 3 (pin 24) - 4, 5, 6, DOWN
  {'M', 'N', 'O', 'P'},     // Row 4 (pin 25) - 7, 8, 9, ESC
  {'Q', 'R', 'S', 'T'}      // Row 5 (pin 26) - LEFT, 0, RIGHT, EXIT
};

// Rows: pins 22-26 (these are the OUTPUT pins from diagnostic)
byte rowPins[ROWS] = {22, 23, 24, 25, 26};
// Columns: pins 27-30 (these are the INPUT pins from diagnostic)
byte colPins[COLS] = {27, 28, 29, 30};

Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  Serial.println("=== 5x4 Keypad Tester ===");
  Serial.println("Press each button to identify its matrix position");
  Serial.println("Write down the letter that appears for each physical button");
  Serial.println("");
  Serial.println("Create your mapping grid:");
  Serial.println("Row1 (top):    ___ ___ ___ ___");
  Serial.println("Row2:          ___ ___ ___ ___");
  Serial.println("Row3:          ___ ___ ___ ___");
  Serial.println("Row4:          ___ ___ ___ ___");
  Serial.println("Row5 (bottom): ___ ___ ___ ___");
  Serial.println("========================================");
}

void loop() {
  char key = customKeypad.getKey();
  
  if (key) {
    Serial.print("Button pressed - Matrix code: ");
    Serial.println(key);
    delay(300);
  }
}