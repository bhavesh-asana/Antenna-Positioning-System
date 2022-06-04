// Radio Frequency Transmitter Module Code
// Micro-controller: Arduino UNO
// Author: Bhavesh Asanabada
// To download libraries visit: https://github.com/PaulStoffregen/RadioHead.git
// For more info about RadioHead visit: https://www.airspayce.com/mikem/arduino/RadioHead/


// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>

// Include dependant SPI Library 
#include <SPI.h> 

// The data pin of transmitter is set as default, refer the library code.

// Set LED pin
#define ledPin 7
 
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
 
void setup()
  {
    // Initialize ASK Object
    rf_driver.init();

    // Begin the serial monitor at 9600 Baud rate.
    Serial.begin(9600);
    
    pinMode(ledPin, OUTPUT);
  }
 
void loop()
  {
    // Set a message to transmit
    const char *msg = "Hello World";
    
    if(rf_driver.send((uint8_t *)msg, strlen(msg)))
      {
        Serial.println("Message Transmitted");
        
        // To indicate the message is transmitted
        digitalWrite(ledPin, HIGH);
      }
      
    rf_driver.waitPacketSent();
    delay(2000);
    
    digitalWrite(ledPin, LOW);
    delay(2000);
    
  }
