#include<Wire.h>    
// Arduino pin numbers
const int X_pin = 2; // digital pin connected to switch output
const int A_pin = 2; // digital pin connected to switch output
const int B_pin = 2; // digital pin connected to switch output
const int Y_pin = 2; // digital pin connected to switch output
const int RB_pin = 2; // digital pin connected to switch output
const int LB_pin = 2; // digital pin connected to switch output
const int start_pin = 2; // digital pin connected to switch output
const int menu_pin = 2; // digital pin connected to switch output

const int X_ax_pin = A0; // analog pin connected to X output
const int Y_ax_pin = A1; // analog pin connected to Y output

void setup() {
  pinMode(2,INPUT_PULLUP)
  pinMode(2,INPUT_PULLUP)
  pinMode(2,INPUT_PULLUP)
  pinMode(2,INPUT_PULLUP)
  pinMode(2,INPUT_PULLUP)
  pinMode(2,INPUT_PULLUP)
  pinMode(2,INPUT_PULLUP)
  pinMode(2,INPUT_PULLUP)

  Wire.begin(1);       //Begins I2C communication at pin (A4,A5). Each controller has to have a different number, as this is the address
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);

  //pinMode(SW_pin, INPUT);
  //digitalWrite(SW_pin, HIGH);
  //Serial.begin(9600);
 }

void requestEvent(){
  byte myData[4];  //sends 7 pieces of data

  int n= analogRead(X_ax_pin);   
  n=map(n,0,1023,0,255);
  myData[0] = (unsigned char) n;     

  n= analogRead(Y_ax_pin);   
  n=map(n, 0, 1023,0 , 255);
  myData[1]= lowByte(n);     

  unsigned char m;
  
  bitWrite(m, 0, digitalRead(X_pin));
  bitWrite(m, 0, digitalRead(A_pin));
  bitWrite(m, 0, digitalRead(B_pin));
  bitWrite(m, 0, digitalRead(Y_pin));
  bitWrite(m, 0, digitalRead(RB_pin));
  bitWrite(m, 0, digitalRead(LB_pin));
  bitWrite(m, 0, digitalRead(start_pin));
  bitWrite(m, 0, digitalRead(menu_pin));   

  myData[2]= m;     
  myData[3]= 0;   //one free byte for the future

  Wire.write(myData, 4); 
}

void receiveEvent(int infoGot){
  SlaveRecieved = Wire.read()     //used to read value received from master
}

void loop() {
 Serial.print("Switch:  ");
 Serial.print(digitalRead(SW_pin));
 Serial.print("\n");
 Serial.print("X-axis: ");
 Serial.print(analogRead(X_pin));
 Serial.print("\n");
 Serial.print("Y-axis: ");
 Serial.println(analogRead(Y_pin));
 Serial.print("\n\n");
 delay(500);
}

