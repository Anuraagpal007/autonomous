//=================================Header Files======================================
#include "Directions.h"
#include <MPU6050_tockn.h>
#include<Wire.h>
#include<Encoder.h>

MPU6050 mpu6050(Wire);

//============================Class Starts from here==================================
class MPUClass                //========================MPUClass CLASS STARTS
{
  private:
    float AngleZ;
  public:
    MPUClass(float AngleZ)
    {
      this -> AngleZ = AngleZ;
    }

    //  M4-----F-----M1
    //  |      |      |
    //  |      |      |
    //  L------+------R
    //  |      |      |
    //  |      |      |
    //  M3-----B-----M2

    //==================================FORWARD FUNCTION USING MPU6050====================

    void forward() {
      mpu6050.update();
      if (AngleZ < 5 && AngleZ > -5)
      {
        bot.frd(200, 200, 182, 182);
        Serial.println("Forward...");
      }
      if (AngleZ > 5 && AngleZ < 40) //WHEN GOING LEFT SIDE
      {
        bot.frd(130, 130, 182, 182);
        Serial.println("Going Left bt then managing the pwm goes Forward...");
      }
      if (AngleZ < -5 && AngleZ > -40) //WHEN GOING RIGHT
      {
        bot.frd(200, 200, 112, 112);
        Serial.println("Going Right bt then managing the pwm goes Forward...");
      }
    }

    //==================================BACKWARD FUNCTION USING MPU6050====================

    void backward() {
      mpu6050.update();
      if (AngleZ < 5 && AngleZ > -5)
      {
        bot.brd(200, 200, 182, 182);
        Serial.println("Backward...");
      }
      else if (AngleZ > 5 && AngleZ < 40)
      {
        bot.brd(200, 200, 112, 112);
        Serial.println("Goes Right bt then goes backward...");
      }
      else if (AngleZ < -5 && AngleZ > -40)
      {
        bot.brd(130, 130, 182, 182);
        Serial.println("Goes Left bt then goes Backward");
      }
    }

    //==================================LEFT FUNCTION USING MPU6050====================

    void left() {
      mpu6050.update();
      if (AngleZ < 5 && AngleZ > -5)
      {
        bot.lft(200, 200, 182, 182);
        Serial.println("Left...");
      }
      else if (AngleZ > 5 && AngleZ < 40)
      {
        bot.lft(130, 200, 182, 112);
        Serial.println("Goes Backward bt then goes Leftward");
      }
      else if (AngleZ < -5 && AngleZ > -40)
      {
        bot.lft(200, 130, 112, 182);
        Serial.println("Goes Forward bt then goes Leftward");
      }
    }

    //==================================RIGHT FUNCTION USING MPU6050====================

    void right() {
      mpu6050.update();

      if (AngleZ < 5 && AngleZ > -5)
      {
        bot.rght(200, 200, 182, 182);
        Serial.println("Right...");
      }
      else if (AngleZ > 5 && AngleZ < 40)
      {
        bot.rght(200, 130, 112, 182);
        Serial.println("Goes Forward bt then goes Rightward");
      }
      else if (AngleZ < -5 && AngleZ > -40)
      {
        bot.rght(130, 200, 182, 112);
        Serial.println("Goes Backward bt then goes Rightward");
      }
    }

    //===================================AntiClockwise 15 degree break======================

    void ftbreak()
    {
      while (AngleZ <= 1)
      {

        mpu6050.update();
        AngleZ = mpu6050.getAngleZ();
        bot.anticlockwise(40, 40, 20, 20);
        Serial.println("Anticlockwise for 15 degrees only...");
        //          Serial.println(mpu6050.getAngleZ());
      }
    }

    //===================================Clockwise 15 degree break======================

    void Negftbreak()
    {
      while (AngleZ >= -75)
      {
        mpu6050.update();
        AngleZ = mpu6050.getAngleZ();
        bot.clockwise(40, 40, 20, 20);
        Serial.println("Clockwise for 15 degrees only...");
        //          Serial.println(mpu6050.getAngleZ());
      }
    }

    //==================================================================================
};     //=============================================================MPUClass CLASS ENDS
