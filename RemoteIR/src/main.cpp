
#include <IRremote.h>

const int recPin = A0;
const int ledPin = 7;

IRrecv obj(recPin);

decode_results res;

void setup()
{
  Serial.begin(9600);
  obj.enableIRIn(); // Start the receiver
  
  pinMode(recPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
}

void loop() {
  obj.blink13(true);
  if(obj.isIdle())
  {
    //Serial.println("IDLE");
  }
  if (obj.decode(&res)) {
    Serial.println("RES VAL:");
    Serial.println(res.value, DEC);
    
    //Serial.println(res.decode_type);
    
    for(uint16_t i = 0; i< res.rawlen; ++i)
    {
      //Serial.println(res.rawbuf[i]);
    }
    if(res.decode_type == 9)
      Serial.println("NEC");
    if(res.value == 0x20DF28D7 && obj.available())
    {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ON");
      delay(500);
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
      delay(100);
    }
    
    obj.resume(); // Receive the next value
  }
  delay(100);
  
}
