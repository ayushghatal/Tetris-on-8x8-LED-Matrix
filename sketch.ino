#include <LedControl.h>

LedControl lc = LedControl(13, 12, 11, 1);

const int buttonLeft = 10;
const int buttonRotate = 9;
const int buttonRight = 8;

int piece[4][2][2] = {
    {
        {1,0},
        {1,0}
    },
    {
        {1,1},
        {1,1}
    },
    {
        {1,0},
        {1,1}
    },
    {
        {1,0},
        {0,1}
    }
};

void setup() {
    pinMode(buttonLeft, INPUT_PULLUP);    // Changed
    pinMode(buttonRotate, INPUT_PULLUP);  // Changed
    pinMode(buttonRight, INPUT_PULLUP);   // Changed

    lc.shutdown(0, false);
    lc.setIntensity(0, 8);
    lc.clearDisplay(0);
}

void loop() {
    lc.clearDisplay(0); // Clear previous LED
    
    int randomIndex = random(0, 4);
    for(int i = 0; i < 2;  i++){
        for(int j = 0; j < 2; j++){
            lc.setLed(0, i, j, piece[randomIndex][i][j]);
        }
    }
    delay(2000); // Shorter delay for responsiveness
}
