# ASUMobiCarG27
#include <SoftwareSerial.h>
SoftwareSerial bluetooth (10,11);//Rx,Tx (ARDUINO)
char data ;
#define trigPin 9
#define echoPin 8
int AF=3;//in1 
int AB=4;//in2
int BF=5;//in3  =>of the motor driver
int BB=6;//in4
void setup() {
  // put your setup code here, to run once:
  bluetooth.begin(9600);
  pinMode(AF,OUTPUT);
  pinMode(AB,OUTPUT);
  pinMode(BF,OUTPUT);
  pinMode(BB,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  

}

void loop() {
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);   // Take reading on echo pin
  float  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  float   cm = duration / 29 / 2; 
  
  
  // put your main code here, to run repeatedly:
 if( case  == 'F' && cm > 5){
    if(bluetooth.available())
  {  
    data=bluetooth.read();
    switch(data){
    case'B'://go back
    digitalWrite(AF,HIGH);
    digitalWrite(BF,HIGH);
    digitalWrite(AB,LOW);
    digitalWrite(BB,LOW);
          break;
    case'F'://go forward
    digitalWrite(AF,LOW);
    digitalWrite(BF,LOW);
    digitalWrite(AB,HIGH);
    digitalWrite(BB,HIGH);
          break;
          case'R':// go right
    digitalWrite(AF,HIGH);
    digitalWrite(BF,LOW);
    digitalWrite(AB,LOW);
    digitalWrite(BB,HIGH);
          break;
          case'L':// go left
    digitalWrite(AF,LOW);
    digitalWrite(BF,HIGH);
    digitalWrite(AB,HIGH);
    digitalWrite(BB,LOW);
          break;
         default:
    digitalWrite(AF,LOW);
    digitalWrite(BF,LOW);
    digitalWrite(AB,LOW);
    digitalWrite(BB,LOW);      
         
         
    }
  }
   
   else if (case  == 'F' && cm <= 5 ) {
    digitalWrite(AF,HIGH);
    digitalWrite(BF,LOW);
    digitalWrite(AB,LOW);
    digitalWrite(BB,HIGH);
    digitalWrite(13,HIGH);
    }
   }
  }
