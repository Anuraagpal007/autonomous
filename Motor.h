//=============================#DEFINE==================================

#define fr_pwm 9
#define fr_dir 11
#define br_pwm 10
#define br_dir 8
#define fl_pwm 6
#define fl_dir1 22
#define fl_dir2 24
#define bl_pwm 5
#define bl_dir1 7
#define bl_dir2 4

//===========================CLASS OF MOTOR==============================

class Motor               //================================Motor CLASS STARTS
{
  private:
    byte pwm , dir1, dir2;
  public:
    Motor(byte pwm , byte dir1, byte dir2 = 100) {
      this -> pwm = pwm;
      this -> dir1 = dir1;
      this -> dir2 = dir2;
      this -> dir2 = dir2;
      pinMode(pwm, OUTPUT);
      pinMode(dir1, OUTPUT);
      pinMode(dir2, OUTPUT);
    }
    //========================CLOCKWISE OF A MOTOR======================
    void clk (byte p) {
      analogWrite(pwm, p);
      digitalWrite(dir1, 0);
      digitalWrite(dir2, 1);
    }
    //========================ANTICLOCKWISE OF A MOTOR======================
    void aclk (byte p) {
      analogWrite(pwm, p);
      digitalWrite(dir1, 1);
      digitalWrite(dir2, 0);
    }
    //========================STOPPING/BRAKING OF A MOTOR======================
    void stp (byte p) {
      analogWrite(pwm, 0);
      digitalWrite(dir1, 1);
      digitalWrite(dir2, 1);
    }
    //========================RELEASE A MOTOR FREE=============================
    void Free (byte p) {
      analogWrite(pwm, 0);
      digitalWrite(dir1, 0);
      digitalWrite(dir2, 0);
    }
};            //==============================Motor CLASS ENDS

//================================PINOUTS=====================================

//(pwm, dir1, dir2)

Motor m1(fr_pwm, fr_dir);                //  1 = Front-Right
Motor m2(br_pwm, br_dir);                //  2 = Back-Right
Motor m3(fl_pwm, fl_dir1, fl_dir2);      //  4 = Front-Left
Motor m4(bl_pwm, bl_dir1, bl_dir2);      //  3 = Back-Left
