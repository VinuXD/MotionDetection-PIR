#include <LiquidCrystal_I2C.h> // include the library

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

int pirPin = 2; // declare sensor pin
int buzzPin = 3; // declare buzzer pin
int val = 0; // variable for reading the pin status

void setup() {
    pinMode(pirPin, INPUT);
    pinMode(buzzPin, OUTPUT);
    lcd.init(); // initialize the lcd
    lcd.backlight(); // turn on the backlight
    lcd.clear(); // clear the lcd
}

void loop() {
    val = digitalRead(pirPin); // read input value
    switch (val) {
    case 0: // if the sensor is off
        lcd.setCursor(0, 0);
        lcd.print("No movement");
        digitalWrite(buzzPin, LOW);
        break;
    case 1: // if the sensor is on
        lcd.setCursor(0, 0);
        lcd.print("Movement detected");
        digitalWrite(buzzPin, HIGH);
        break;
    }
    delay(2000); // wait 2 seconds
    lcd.clear(); // clear the lcd
}
