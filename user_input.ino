#include <avr/io.h>
#include <SoftwareSerial.h>

const uint8_t buttonPin = 2;
const unsigned long debounceDelay = 50; // milliseconds

volatile bool buttonPressed = false;
volatile unsigned long lastDebounceTime = 0;

const int rxPin = 10;
const int txPin = 11;

SoftwareSerial mySerial(rxPin, txPin);

ISR(TIMER1_COMPA_vect) {
  unsigned long now = millis();
  if (now - lastDebounceTime > debounceDelay) {
    buttonPressed = false;
  }
}

void setup() {
  // Set up timer 1 for debouncing
  TCCR1A = 0;
  TCCR1B = (1 << CS11) | (1 << CS10); // Set prescaler to 1024
  OCR1A = 15625; // Set compare register for 1 millisecond interrupt
  TIMSK1 |= (1 << OCIE1A);

  // Set the button pin as input with pull-up resistor
  DDRD &= ~(1 << buttonPin);
  PORTD |= (1 << buttonPin);

  mySerial.begin(9600);
}

void loop() {
  // Read the button state (inverted logic for tactile switch)
  bool buttonState = !(PIND & (1 << buttonPin));

  if (buttonState && !buttonPressed) {
    buttonPressed = true;
    mySerial.println("RESET");
  }
}
