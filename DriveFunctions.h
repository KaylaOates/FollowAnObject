#include "wdt.h"
#include "DeviceDriverSet_xxx0.h"
#include "ApplicationFunctionSet_xxx0.cpp"

DeviceDriverSet_Motor AppMotor;
Application_xxx Application_ConquerorCarxxx0;

void BRAKES()
{
  ApplicationFunctionSet_ConquerorCarMotionControl(0, 0);
  delay(150);
}

double DriveSeconds(int programSpeed, int distCm)
{
  double cmPerSec = programSpeed*0.24375; 
  double seconds = distCm / cmPerSec;
  return seconds;
}

void DriveDistance(String dir, int programSpeed, int distCm) ////change dir to a string
{  
  if(dir == "Drive Forwards")
  {
    ApplicationFunctionSet_ConquerorCarMotionControl(0, programSpeed /*speed*/);
    delay(DriveSeconds(programSpeed, distCm)*1000);
    BRAKES();
  }
  if(dir == "Drive Backwards")
  {
    ApplicationFunctionSet_ConquerorCarMotionControl(1, programSpeed /*speed*/);
    delay(DriveSeconds(programSpeed, distCm)*1000);
    BRAKES();
  }
}

void Drive(String dir, int programSpeed) ////change dir to a string
{  
  if(dir == "Forwards")
  {
    ApplicationFunctionSet_ConquerorCarMotionControl(0, programSpeed /*speed*/);
  }
  if(dir == "Backwards")
  {
    ApplicationFunctionSet_ConquerorCarMotionControl(1, programSpeed /*speed*/);
  }
}

void DriveCurvedLeft(String dir, int programSpeed, int distCm)
{
  //4 forwards left
  if(dir == "Forwards Curved Left")
  {
      ApplicationFunctionSet_ConquerorCarMotionControl(4, programSpeed /*speed*/);
      delay(DriveSeconds(programSpeed, distCm)*1000);
      BRAKES();
  }
  else if(dir == "Backwards Curved Left")
  {
    ApplicationFunctionSet_ConquerorCarMotionControl(5, programSpeed /*speed*/);
    delay(DriveSeconds(programSpeed, distCm)*1000);
    BRAKES();
  } 
  else 
  {
    //Serial.println("ERROR IN FUNCTION DRIVE_CURVED_LEFT \n INVALID INPUT");
 }
}

void DriveCurvedRight(String dir, int programSpeed, int distCm)
{
  if(dir == "Forwards Curved Right")
  {
     ApplicationFunctionSet_ConquerorCarMotionControl(4, programSpeed /*speed*/);
     delay(DriveSeconds(programSpeed, distCm)*1000);
     BRAKES();
  }
  else 
  {
   //Serial.println("ERROR IN FUNCTION DRIVE_CURVED_RIGHT \n INVALID INPUT");
  }
}
// Spin(degree, speed);
/*void DriveSpin(int deg, int programSpeed)
{
  
  double circumference = 53.55263158;
  double number = 360/deg;
  double distCm = circumference/number;

  if(deg < 0)
  {
    ApplicationFunctionSet_ConquerorCarMotionControl(2, programSpeed);
    delay(DriveSeconds(programSpeed, distCm)*1000);
    BRAKES();
  }
  else if(deg > 0)
  {
    ApplicationFunctionSet_ConquerorCarMotionControl(3, programSpeed);
    delay(DriveSeconds(programSpeed, distCm)*1000);
    Serial.println(DriveSeconds(programSpeed, distCm)*1000);
    BRAKES();
  }
  else 
  {
    BRAKES();
  }
  
}
*/





void DriveSpin(int deg, int programSpeed)
{
  int dir;
  
  if(deg >= 0)
  {
    dir = 3;
  }
  else if(deg < 0)
  {
    deg = deg * -1;
    dir = 2;
  }

  if(deg == 0)
  {
    ApplicationFunctionSet_ConquerorCarMotionControl(dir, programSpeed);
  }
  
  if(programSpeed >= 75 && programSpeed <= 125)
  {
    ApplicationFunctionSet_ConquerorCarMotionControl(dir, programSpeed);
    double del = 1190.0 * (deg / 180.0);
    delay(del);
    BRAKES();
  }
  else if(programSpeed >= 126 && programSpeed <= 175)
  {
    //Serial.println("entered");
    ApplicationFunctionSet_ConquerorCarMotionControl(dir, programSpeed);
    double del = 738.0 * (deg / 180.0);
    //Serial.println(del);
    delay(del);
    BRAKES();
  }
  else if(programSpeed >= 176 && programSpeed <= 225)
  {
    ApplicationFunctionSet_ConquerorCarMotionControl(dir, programSpeed);
    double del = 533.33 * (deg / 180.0);
    delay(del);
    BRAKES();
  }
  else if(programSpeed >= 226 && programSpeed <= 255)
  {
    ApplicationFunctionSet_ConquerorCarMotionControl(dir, programSpeed);
    double del = 426.67 * (deg / 180.0);
    delay(del);
    BRAKES();
  }
  else if(programSpeed <= 74 || programSpeed >= 226)
  {
   //Serial.println("ERROR IN FUNCTION 'DRIVESPIN' \n INVALID SPEED INPUT");
  }
  else
  {
    //Serial.println("ERROR IN FUNCTION 'DRIVESPIN' \n INVALID INPUT: OTHER");
  }
  
 
}
