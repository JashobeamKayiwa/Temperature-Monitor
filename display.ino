#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

// Adjust the I2C address if necessary
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the I2C address and LCD dimensions

const int rxPin = 10;
const int txPin = 11;

SoftwareSerial mySerial(rxPin, txPin);

void setup() {
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight

  mySerial.begin(9600);
}

void loop() {
  if (mySerial.available() > 0) {
    char data = mySerial.read();
    if (data == 'T') {
      float temperature = mySerial.parseFloat();
      lcd.setCursor(0, 0);
      lcd.print("Temp: ");
      lcd.print(temperature);
      lcd.print(" C");
    } else if (data == 'R') {
      lcd.clear();
      lcd.print("System Reset");
      // Reinitialize LCD settings if needed
      lcd.init();
      lcd.backlight();
    }
  }
}