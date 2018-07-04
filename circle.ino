#include <SoftwareSerial.h>
SoftwareSerial bluetooth (12,13);//Rx,Tx (ARDUINO)
char data ;
int AF=3;//in1 
int AB=4;//in2
int BF=5;//in3  =>of the motor driver
int BB=6;//in4
int state = LOW;
int lastState;
float counter = 0;
float sens = 75;
int slots = 10;
float dist=0;
float dest;
String str;
float curve;

void setup() {
  // put your setup code here, to run once:


 Serial.begin(9600);
 bluetooth.begin(9600);
 pinMode(AF,OUTPUT);
  pinMode(AB,OUTPUT);
  pinMode(BF,OUTPUT);
  pinMode(BB,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  
}
void loop() {                    // put your main code here, to run repeatedly:

  if(bluetooth.available()>0)
 {data=bluetooth.read();
 if (data=='m')
 {
    while(dist<590)        //go forward 1
      {
        
    digitalWrite(AF,LOW);
    digitalWrite(BF,LOW);
    digitalWrite(AB,HIGH);
    digitalWrite(BB,HIGH);
    analogWrite(10,200);
    analogWrite(11,145);
        if(analogRead(A0)  > sens)
 { lastState = HIGH;
 }
 else {lastState = LOW; }
 if(state != lastState)
 { counter++;
  state = lastState;}
  dist = counter/2 ;
  Serial.println(dist);  
      }
  digitalWrite(AF,LOW);
    digitalWrite(BF,LOW);
    digitalWrite(AB,LOW);
    digitalWrite(BB,LOW);
    
    counter=0;
    dist=0;
   
  }
  }
  }
