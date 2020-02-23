// Wire Slave Sender
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

// Created 29 March 2006

// This example code is in the public domain.

const int X_ax_pin = A0; // analog pin connected to X output
const int Y_ax_pin = A1; // analog pin connected to Y output


#include <Wire.h>

void setup() {
  Wire.begin(101);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
}

void loop() {
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  int n= analogRead(Y_ax_pin);   
  n=map(n, 0, 1023,0 , 255);
  n= lowByte(n);  
  
  Wire.write(n); // respond with message of 6 bytes
  // as expected by master
}
