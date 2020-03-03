/*
 *  Project     Arduino XInput Library
 *  @author     David Madison
 *  @link       github.com/dmadison/ArduinoXInput
 *  @license    MIT - Copyright (c) 2019 David Madison
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *  Example:      SimulateAll
 *  Description:  Automatically activate all possible XInput controls.
 *                Useful to test that everything is functioning properly.
 * 
 *  WARNING: This will spam inputs! Ground pin '0' (RX) to stop.
 *
 */

#include <XInput.h>

// Input Pins
const int SafetyPin = 0;  // Ground this pin to prevent inputs

const uint8_t Pin_Joystick_X = A0;  // X
const uint8_t Pin_Joystick_Y = A1;  // Y

const uint8_t Pin_Button_A = 2;   // 
const uint8_t Pin_Button_B = 4;   // 
const uint8_t Pin_Button_X = 5;   // 
const uint8_t Pin_Button_Y = 8;   // 
const uint8_t Pin_Left_Trigger = 9;   // 
const uint8_t Pin_Right_Trigger = 3;   // 
const uint8_t Pin_Button_BACK  = 6;
const uint8_t Pin_Button_START = 7;

// Analog Input Range
const int AnalogRead_Max = 1023;  // 10-bit ADC

void setup() {
  pinMode(SafetyPin, INPUT_PULLUP);
  
  // Set input pin modes
  pinMode(Pin_Button_A, INPUT_PULLUP);
  pinMode(Pin_Button_B, INPUT_PULLUP);
  pinMode(Pin_Button_X, INPUT_PULLUP);
  pinMode(Pin_Button_Y, INPUT_PULLUP);
  pinMode(Pin_Left_Trigger, INPUT_PULLUP);
  pinMode(Pin_Right_Trigger, INPUT_PULLUP);
  pinMode(Pin_Button_BACK, INPUT_PULLUP);
  pinMode(Pin_Button_START, INPUT_PULLUP);

  // Setup library
  XInput.setRange(JOY_LEFT, 0, AnalogRead_Max);
  XInput.setRange(JOY_RIGHT, 0, AnalogRead_Max);
  XInput.setAutoSend(false);  // Wait for all controls before sending
  XInput.begin();
}

void loop() {
// Read pin states
  boolean press_A = !digitalRead(Pin_Button_A);
  boolean press_B = !digitalRead(Pin_Button_B);
  boolean press_X = !digitalRead(Pin_Button_X);
  boolean press_Y = !digitalRead(Pin_Button_Y);
  boolean press_L_trigger = !digitalRead(Pin_Left_Trigger);
  boolean press_R_trigger = !digitalRead(Pin_Right_Trigger);
  boolean press_Back = !digitalRead(Pin_Button_BACK);
  boolean press_Start = !digitalRead(Pin_Button_START);
  
  int joystickValue_X = analogRead(Pin_Joystick_X);
  int joystickValue_Y = analogRead(Pin_Joystick_Y);
  
  // Set button and trigger states
  XInput.setButton(BUTTON_A, press_A);
  XInput.setButton(BUTTON_B, press_B);
  XInput.setButton(BUTTON_X, press_X);
  XInput.setButton(BUTTON_Y, press_Y);
  XInput.setButton(TRIGGER_RIGHT, press_L_trigger);
  XInput.setButton(TRIGGER_LEFT, press_R_trigger);
  XInput.setButton(BUTTON_BACK, press_Back);
  XInput.setButton(BUTTON_START, press_Start);
  
  XInput.setJoystick(JOY_LEFT, joystickValue_X, joystickValue_Y);

  // Send values to PC
  XInput.send();
}
