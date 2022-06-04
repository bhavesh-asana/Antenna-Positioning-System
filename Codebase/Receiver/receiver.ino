// Radio Frequency Receiver Module Code
// Micro-controller: Arduino UNO
// Author: Bhavesh Asanabada
// To download libraries visit: https://github.com/PaulStoffregen/RadioHead.git
// For more info about RadioHead visit: https://www.airspayce.com/mikem/arduino/RadioHead/


// <-------- Initialize required libraries (Begin) -------->
#include <LiquidCrystal.h> 
#include <RHGenericDriver.h>
// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h>
// <-------- Initialize required libraries (End) -------->

// Re-configure the LCD pins associated as below
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Receiver datapin config
const int datain = 12;

#define ledPin 7

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
 
void setup()
{
    // Initialize ASK Object
    rf_driver.init();
    
    // Setup Serial Monitor
    Serial.begin(9600);
    
    pinMode(ledPin, OUTPUT);
}
 
void loop()
{
    // Set buffer to size of expected message
    uint8_t buf[11];
    uint8_t buflen = sizeof(buf);
    
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen)){
        // Message received with valid checksum
        Serial.print("Message Received: ");
        digitalWrite(ledPin, HIGH);
        
        // set up the LCD's number of columns and rows:
        lcd.begin(16, 2);
        // Print a message to the LCD.
        lcd.print("Receiving");
        Serial.println((char*)buf);
         
        uint8_t lastRssi = rf_driver.lastRssi();
        // Serial.println(rf_driver.lastRssi(), DEC);
        int16_t iRssi = (rf_driver.lastRssi(), DEC);   
        // String sRssi = String((rf_driver.lastRssi(), DEC));

        Serial.println(iRssi);   // 10
        // Serial.println(sRssi); 
        delay(1000);        
      }
    
    else{
      Serial.println("Message not received");
      Serial.println(rf_driver.lastRssi(), DEC);
      lcd.begin(0, 1);
      lcd.print("Transmission Error");
    }

    digitalWrite(ledPin, LOW);
    delay(1000);
}
