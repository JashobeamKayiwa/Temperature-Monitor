#include <EEPROM.h>
#include <SoftwareSerial.h>

const int rxPin = 10;
const int txPin = 11;

SoftwareSerial mySerial(rxPin, txPin);

const int bufferSize = 10; // Adjust buffer size as needed
int addressIndex = 0; // Current address index

const int temperatureAddress = 0; // Adjust the address as needed

void setup() {
  mySerial.begin(9600);
  EEPROM.begin(); // Adjust EEPROM size as needed
}

void loop() {
  if (mySerial.available() > 0) {
    char data = mySerial.read();
    if (data == 'T') {
      float temperature = mySerial.parseFloat();
      int intTemperature = (int)(temperature * 100); // Convert to integer for EEPROM storage

      // Handle address management using circular buffer
      addressIndex = (addressIndex + 1) % bufferSize;

      // Write the temperature to the current address
      EEPROM.write(temperatureAddress + addressIndex * sizeof(int), intTemperature);

      // Optional: Print confirmation message
      mySerial.println("Temperature stored in EEPROM!");
    } else if (data == 'R') {
      // Reset address index
      addressIndex = 0;
      // Optionally, erase specific portions of EEPROM
      // ... (EEPROM erase functions)
      mySerial.println("EEPROM reset");
    }
  }
}