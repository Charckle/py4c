#include<Wire.h>    

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
  int myData[9]  //sends 7 pieces of data

  myData[0] = analogRead(X_ax_pin);     
  myData[1]= analogRead(Y_ax_pin);     

  myData[2]= digitalRead(X_pin);     
  myData[3]= digitalRead(A_pin);     
  myData[4]= digitalRead(B_pin);     
  myData[5]= digitalRead(Y_pin);     
  myData[6]= digitalRead(RB_pin);     
  myData[7]= digitalRead(LB_pin);     
  myData[8]= digitalRead(start_pin);     
  myData[9]= digitalRead(menu_pin);     

  byte SlaveSend = map(myData,0,1023,0,127);   
  Wire.write(SlaveSend);  
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

