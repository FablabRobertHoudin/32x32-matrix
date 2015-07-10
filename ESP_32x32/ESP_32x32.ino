#include "ESP8266WiFi.h"

#define r0 15
#define g0 2
#define b0 0
#define r1 4
#define g1 5
#define b1 3

#define STB 16
#define CLK 14
#define OE  12
#define ABCD 13

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(115200);
  pinMode(STB, OUTPUT); digitalWrite(STB, LOW);
  pinMode(CLK, OUTPUT); digitalWrite(CLK, LOW);
  pinMode(OE, OUTPUT); digitalWrite(OE, HIGH); // disable out
  pinMode(ABCD, OUTPUT); digitalWrite(ABCD, LOW);
  pinMode(r0, OUTPUT); digitalWrite(r0, LOW);
  pinMode(g0, OUTPUT); digitalWrite(g0, LOW);
  pinMode(b0, OUTPUT); digitalWrite(b0, LOW);
  pinMode(r1, OUTPUT); digitalWrite(r1, LOW);
  pinMode(g1, OUTPUT); digitalWrite(g1, LOW);
  pinMode(b1, OUTPUT); digitalWrite(b1, LOW);
}

boolean flip = 0;
boolean flipCLK = 0;

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("OK !");
  //delay(500);
  flip = ~flip;
  digitalWrite(ABCD, flip);
  //digitalWrite(ABCD, LOW);
  digitalWrite(OE, HIGH); // disable out
  digitalWrite(STB, HIGH);
  for(int i=0; i<32; i++) {

    digitalWrite(r0, i & 0x01 ? HIGH : LOW); 
    digitalWrite(g0, i & 0x02 ? HIGH : LOW); 
    digitalWrite(b0, i & 0x04 ? HIGH : LOW); 
    digitalWrite(r1, i & 0x04 ? HIGH : LOW); 
    digitalWrite(g1, i & 0x02 ? HIGH : LOW); 
    digitalWrite(b1, i & 0x01 ? HIGH : LOW); 
    digitalWrite(CLK, LOW);
    digitalWrite(CLK, HIGH);
    //digitalWrite(CLK, flipCLK = ~flipCLK);
    
  }
  digitalWrite(STB, LOW);
  digitalWrite(OE, LOW); // enable out
}
