//==============================HEADER FILES==================================

#include "MPUClass.h"
#include <MPU6050_tockn.h>
#include<Wire.h>
#include<Encoder.h>

//==============================ENCODER PINOUTS===============================

Encoder myEnc1(2, 3);    //Vertical //Parallel to Tube/Cytron Axis
Encoder myEnc2(18, 19);  //Horizontal // Perpendicular to Tube/Cytron Axis
#define PWM 46
#define feed A3
#define DCV 44

//=================================VARIABLES==================================

long timer = 0;
float AngleZ;

//================================VOID SETUP()================================

void setup()
{
  pinMode(PWM, OUTPUT);
  pinMode(feed, INPUT);
  pinMode(DCV, OUTPUT);
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

long oldPosition1  = -999;
long oldPosition2  = -999;

//===============================VOID LOOP()==================================

void loop()
{
  //  long newPosition1 = abs(myEnc1.read());
  //  long newPosition2 = abs(myEnc2.read());

  AngleZ = mpu6050.getAngleZ();
  MPUClass robo(AngleZ);

  
  
  //==================================================================================================================================================
  while(1);
  //==================================================================================================================================================
  //    // =========Forward=========
  //    robo.forward();
  //    // =========

  //    while (1)
  //    { if (abs(myEnc1.read()) < 50000)
  //      {
  //        AngleZ = mpu6050.getAngleZ();
  //        MPUClass robo(AngleZ);
  //        robo.forward();
  //        Serial.println(abs(myEnc2.read()));
  //      }
  //      else
  //      {
  //        break;
  //      }
  //    }
  //    Serial.println("STOP>>>STOP>>>STOP");
  //    bot.brake(0, 0, 0, 0);
  //    while (1);

  //====================================================================

  analogWrite(PWM, 180);
  while (analogRead(feed) < 400);
  digitalWrite(DCV, HIGH);
  delay(500);
  digitalWrite(DCV, LOW);
  analogWrite(PWM, 0);
  delay(10000);

  //====================================================================

  analogWrite(PWM, 150);
  while (analogRead(feed) < 350);
  digitalWrite(DCV, HIGH);
  delay(500);
  digitalWrite(DCV, LOW);
  analogWrite(PWM, 0);
  delay(10000);

  //========================================================================

  //  analogWrite(PWM, 150);
  //  while (analogRead(feed) < 150);
  //  digitalWrite(DCV, HIGH);
  //  delay(500);
  //  digitalWrite(DCV, LOW);
  //  analogWrite(PWM, 0);
  //  delay(10000);

  //=========================================================================

  robo.ftbreak();
  bot.brake(0, 0, 0, 0);
  delay(1000);
  
  //=========================================================================

  analogWrite(PWM, 150);
  while (analogRead(feed) < 150);
  digitalWrite(DCV, HIGH);
  delay(500);
  digitalWrite(DCV, LOW);
  analogWrite(PWM, 0);
  delay(10000);

  //================================================================

  robo.Negftbreak();
  bot.brake(0, 0, 0, 0);
  delay(1000);

  //=================================================================

  analogWrite(PWM, 150);
  while (analogRead(feed) < 150);
  digitalWrite(DCV, HIGH);
  delay(500);
  digitalWrite(DCV, LOW);
  analogWrite(PWM, 0);
  delay(10000);
  
  //  ===============================================================
  
  while (1);

}
