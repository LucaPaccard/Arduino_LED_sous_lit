
#include <LowPower.h>

// Define pin constants
const int transistorLedPin = 5;     // Pin connected to the LED strip controlled by the transistor
const int transistorPirPin = 2;     // Pin to control the PIR sensor transistor
const int pirOutputPin = 3;        // Pin connected to the output of the PIR sensor
const int photoresistorPin = A1;    // Analog pin connected to the photoresistor

// Define operational parameters
const int increment = 1;            // Ligth increment value
const int delayTimeIncrement = 50;  // Delay time in milliseconds
const int lightBrightness = 3;      // Brightness level for the LED strip (range: 0 to 255)
const int lightThreshold = 800;     // Light level threshold for determining if it's dark enough
const unsigned long lightCheckInterval = SLEEP_8S;  // Time interval to check light level (1 second)
const unsigned long motionCheckInterval = 1000; // Time interval to check motion (1 second)
const unsigned long ledOnDuration = 10000;      // Duration to keep LED on when motion is detected (10 seconds)

void setup() {
    // Configure the clock prescaler for power optimization
    CLKPR = 0x01;

    // Initialize serial communication at 9600 baud rate
    Serial.begin(9600);
    
    // Set up pin modes
    pinMode(pirOutputPin, INPUT);       // PIR output pin as input
    pinMode(transistorLedPin, OUTPUT);  // LED strip pin as output
    pinMode(transistorPirPin, OUTPUT);  // Transistor control pin as output
}

void loop() {
    // Read the light level from the photoresistor
    int lightLevel = analogRead(photoresistorPin);
    // Serial.print("Light Level: ");
    // Serial.println(lightLevel);
    delay(10);
    // If the light level is below the threshold
    if (lightLevel < lightThreshold) {
        // Activate the PIR sensor by setting the transistor to HIGH
        digitalWrite(transistorPirPin, HIGH);
        
        // Read motion detection status from the PIR sensor
        int motionDetected = digitalRead(pirOutputPin);
        
        // If motion is detected
        if (motionDetected == HIGH) {
          
            // Gradually increase brightness
            for (int brightness = 0; brightness <= lightBrightness; brightness += increment) {
              analogWrite(transistorLedPin, brightness);
              delay(delayTimeIncrement);
            }
            
            // Keep the LED strip on for the specified duration
            delay(ledOnDuration);
            
            // Turn off the LED strip
            for (int brightness = lightBrightness; brightness >= 0; brightness -= increment) {
              analogWrite(transistorLedPin, brightness);
              delay(delayTimeIncrement);
            }
        }
        
        // Delay before checking motion again
        delay(motionCheckInterval);
        
    } else {
        // Deactivate the PIR sensor by setting the transistor to LOW
        digitalWrite(transistorPirPin, LOW);
        
        // Ensure the LED strip is turned off
        analogWrite(transistorLedPin, 0);
        
        // Delay before checking the light level again
        LowPower.powerDown(lightCheckInterval, ADC_OFF, BOD_OFF);
    }
}
