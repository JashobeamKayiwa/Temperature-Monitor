#include <avr/io.h>
#include <SoftwareSerial.h>

const int tempSensorPin = A0; // Connect the TMP36's output to A0
const int rxPin = 10;
const int txPin = 11;

SoftwareSerial mySerial(rxPin, txPin);

volatile unsigned long currentMillis = 0;

void setup() {
  // Configure ADC (assuming default settings)
  ADCSRA |= (1 << ADEN); // Enable ADC

  // Configure timer for delay function
  TCCR1A = 0; // Set timer mode to normal
  TCCR1B = (1 << CS10); // Set prescaler to 1
  TIMSK1 |= (1 << OCIE1A); // Enable timer interrupt on compare match A
  OCR1A = 15625; // Set compare register for 1 millisecond interrupt (assuming 16MHz clock)

  mySerial.begin(9600);
  sei(); // Enable global interrupts
}

void loop() {
  // Start ADC conversion
  ADCSRA |= (1 << ADSC);

  // Wait for conversion to complete
  while (!(ADCSRA & (1 << ADIF)));

  // Read ADC result
  int sensorValue = ADCH;

  // Calculate temperature using TMP36's voltage-to-temperature conversion
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100.0; // Adjust calibration factor as needed

  mySerial.print("T");
  mySerial.print(temperatureC);
  mySerial.println();

  // Call custom delay function for 1 second delay
  custom_delay(1000);

  // Check for reset command
  if (mySerial.available() > 0) {
    char data = mySerial.read();
    if (data == 'R') {
      // Reset sensor calibration or internal state (not applicable for TMP36)
    }
  }
}

// Custom delay function using timer interrupt
ISR(TIMER1_COMPA_vect) {
  currentMillis++;
}

void custom_delay(unsigned long ms) {
  unsigned long start = currentMillis;
  while (currentMillis - start < ms) {}
}
