/*Follow an object...
`
   while(doesnn't see an object)
   {
    ultrasonic while rotating
   }
  
  while(sees an object)
  {
   |*maintain a distance >=9.5cm and <=10.5*|
    brakes
    If(object is >10.5 cm away < 30cm)
    {
    DRIVE until distance is <=10.5
    stop
    }
    If(object is <9.5cm away)
    {
      backup untill >9.5cm
    }  
  }
  
*/


#include <Servo.h>  //use the servo pre built library
#include "DriveFunctions.h"

#define echoPin 12
#define trigPin 13

Servo servo;  

int servoPin = 10;


void setup ()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);
  servo.attach(servoPin); 
  servo.write(115);
}



double ultrasonic()
{
   double duration, distance;  
  
  //turns off the ultrasonic sensor (like a reset)
  digitalWrite(trigPin, LOW);   
  delayMicroseconds(2);
  
  //telling the sensor to send out a soundwave
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);   
    
    
  duration = pulseIn(echoPin, HIGH);    
  distance = (duration / 2) * 0.0344;     

  /*
  if (distance >= 400 || distance <= 2)
  {       
    //Serial.print("Distance = ");   
    //Serial.println("Out of range");    
  }   
  else 
  {      
   // Serial.print("Distance = ");     
    //Serial.print(distance);      
    //Serial.println(" cm");   
  }
  */

  return distance;
}
void loop ()
{
  double distance = ultrasonic();
  
  while(distance >= 30)
  {
    distance = ultrasonic();
    Serial.println(distance);
    DriveSpin(0, 50);
  }
  
  BRAKES();

  while(distance <= 30)
  {
    while(distance >= 10.5 && distance <= 30)
    {
     distance = ultrasonic();
     Serial.println(distance);
     Drive("Forwards", 70);
    }

    while(distance < 10.5 && distance > 9.5)
    {
     distance = ultrasonic();
     Serial.println(distance);
     BRAKES();
    }
    
    while(distance <= 9.5)
    {
     distance = ultrasonic();
     Serial.println(distance);
     Drive("Backwards", 60);
    }

  }
}
