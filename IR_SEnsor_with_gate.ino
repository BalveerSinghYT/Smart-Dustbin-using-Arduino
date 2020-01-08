#include <Servo.h>
Servo servo1;
int angle = 0; 
 int trigPin = 9;
int echoPin = 8;
int ir = 4; // IR sensor
int led = 5; // LED 
long distance;
long duration;
 
void setup() 
{
servo1.attach(7); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);// put your setup code here, to run once:
 pinMode(ir, INPUT);
 pinMode(led, OUTPUT);
 Serial.begin(9600); // Starts the serial communication

}
 
void loop() {
    light();
    //gate();
}
 
void ultra(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
}

void gate()
{
  
  ultra();
  servo1.write(0);
  
 while(distance <= 30)
  {
    ultra();
    servo1.write(90);
    delay(3000);
  }
  if(distance >30)
  {
    servo1.write(0);
    }
  else{
     for(angle = 90; angle>=0; angle-=1)     // command to move from 180 degrees to 0 degrees 
    {                                
    servo1.write(angle);              //command to rotate the servo to the specified angle
    delay(15);                       
    }
  }
  servo1.write(0);
}

void light()
{
  if(digitalRead(ir)== LOW)
  {
      digitalWrite(led, HIGH);  
  }
  else
  {
      digitalWrite(led, LOW); 
      gate();
  }
}
  
