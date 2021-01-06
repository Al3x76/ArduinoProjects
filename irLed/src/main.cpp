#include <Arduino.h>
#include <IRremote.h>

/// Declaram pinul de intrare prin care primim informatiile citite de la senzor;

const int recPin = A0;

/// Declaram pinii de iesire;

const int redPin = 7;
const int greenPin = 8;
const int bluePin = 9;

/// Declaram un obiect myRec la clasa IRecv;

IRrecv myRec(recPin);

/// Declaram o instanta res la structura  decode_resut;

decode_results res;

void setup() {

  ///Pornim interfata virtuala-seriala;
  
  Serial.begin(9600);

  /// Pornim receptia;

  myRec.enableIRIn();

  /// Setam pinul A0 ca intrare;

  pinMode(recPin,INPUT);

  /// Setam pinii 7,8 si 9 ca iesiri;

  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);

}

void loop() {

  /// Activam ledul buildIn sa faca blink cand comunica cu telecomanda;

  myRec.blink13(true);
  ///res.value=0x0;

  if(myRec.decode(&res))
  {
      Serial.println(res.value,HEX);
      delay(100);
     
  }

  if(res.value==0xFF42BD)
  {
      digitalWrite(redPin,HIGH);
      delay(1000);
      digitalWrite(redPin,LOW);
      myRec.resume();

  }
  else if(res.value==0xFF4AB5)
  {
      digitalWrite(greenPin,HIGH);
      delay(1000);
      digitalWrite(greenPin,LOW);
      myRec.resume();

  }
  else if(res.value==0xFF52AD)
  {
      digitalWrite(bluePin,HIGH);
      delay(1000);
      digitalWrite(bluePin,LOW);
      myRec.resume();

  }
  else
  {
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,LOW);
    myRec.resume();

  }
  
  
  delay(1000);
  
}