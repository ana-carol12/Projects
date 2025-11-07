#include <Arduino.h>
 const unsigned char buttonPin = 19;  


 bool buttonState = false;
 bool lastButtonState = false;
 bool estadoLed = 0;




// void setup() {
//  Serial.begin(9600);


//  pinMode(15,OUTPUT);
//  pinMode (19, INPUT_PULLUP);


// }


// void loop() {
//  Serial.println(digitalRead(19));




//  digitalRead(19);


//  /*digitalWrite(15,HIGH);
//  delay (500);
//  digitalWrite(15,LOW);
//  delay (500);*/


//  buttonState = digitalRead(buttonPin);


//   if(estadoLed == 0 && lastButtonState == 1 && buttonState == 0) {
//     estadoLed = 1;
//   }
//   else if(estadoLed == 1 && lastButtonState == 0 && buttonState == 1){
//     estadoLed = 0;
//   }
 
//   /*if(estadoLed == 1) {
//     digitalWrite(15, HIGH);
//   } else {
//     digitalWrite(15, LOW);
//   }*/


// }
