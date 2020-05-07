#include <Servo.h>

Servo serv1, serv2;
const int trigPin = 1;
const int echoPin = 2;
long duration;
int CM;
int pos = 0;

int forward = 0;
int backward = 0;
int right = 0;
int left = 0;
void setup()
{
  pinMode(echoPin, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(12, INPUT);
  pinMode(11, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(7, HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  serv1.write(0);
  serv2.write(0);
  serv1.attach(11);
  serv2.attach(7);
  

}

void loop()
{
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  
  duration = pulseIn(echoPin, HIGH);
  CM = duration*0.034/2;
  
  forward = digitalRead(12);
  backward = digitalRead(8);
  right = digitalRead(7);
  left = digitalRead(11);
  

  
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);

  if(backward == 0)
  {
  if(CM <= 50){
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  }
    else{
    digitalWrite(6,HIGH);
    digitalWrite(9,HIGH);
    }
  }

  if(forward == 0)
  {
  if(CM <= 50){
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  }
    else{
    digitalWrite(3,HIGH);
    digitalWrite(5,HIGH);
    }
  }
  
  if(right == HIGH){
  for (pos = 0; pos <= 150; pos += 1) { 
    serv1, serv2.write(pos); 
    
    

  }
  }
 
  if(left == HIGH){
  for (pos = 150; pos >= 0; pos -= 1) { 
   serv1, serv2.write(pos); 
                       
  }
  }


}



