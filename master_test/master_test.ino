#include <Wire.h>

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  Wire.requestFrom(101, 1);    // request 6 bytes from slave device #101

  while (Wire.available()) { // slave may send less than requested
    int c = Wire.read(); // receive a byte as characterSerial.print(c);       // print the character
    Serial.print("X axis is: ");       // print the character
    Serial.print(c);       // print the character
    Serial.print("\n");
  }

  delay(500);
}
