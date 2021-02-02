#include "Motor.h"

class Directions                //========================Directions CLASS STARTS
{
  private:
    byte p;
  public:
    Directions() {} 
    //=============================FORWARD===========================
      void frd(byte p1, byte p2, byte p3, byte p4) 
      {
        m1.clk(p1);
        m2.clk(p2);
        m3.aclk(p3);
        m4.aclk(p4); 
       }
    //=============================BACKWARD===========================
      void brd(byte p1, byte p2, byte p3, byte p4) 
      {
        m1.aclk(p1); 
        m2.aclk(p2);
        m3.clk(p3);
        m4.clk(p4); 
      }
    //=============================LEFT===========================
      void lft(byte p1, byte p2, byte p3, byte p4)
      {
        m1.clk(p1);
        m2.aclk(p2);
        m3.aclk(p3);
        m4.clk(p4); 
      }
    //=============================RIGHT===========================
      void rght(byte p1, byte p2, byte p3, byte p4) 
      {
        m1.aclk(p1);
        m2.clk(p2);
        m3.clk(p3);
        m4.aclk(p4);
      }
    //=============================UP-LEFT===========================
      void upleft(byte p1, byte p2, byte p3, byte p4) 
      {
        m1.clk(p1);
        m2.stp(p2);
        m3.aclk(p3);
        m4.stp(p4); 
      }
    //=============================UP-RIGHT===========================
      void upright(byte p1, byte p2, byte p3, byte p4) 
      {
        m1.stp(p1);
        m2.clk(p2);
        m3.stp(p3);
        m4.aclk(p4); 
      }
    //=============================DOWN-LEFT===========================
      void downleft(byte p1, byte p2, byte p3, byte p4) 
      {
        m1.stp(p1);
        m2.aclk(p2);
        m3.stp(p3);
        m4.clk(p4); 
      }
    //=============================DOWN_RIGHT===========================
      void downright(byte p1, byte p2, byte p3, byte p4) 
      {
        m1.aclk(p1);
        m2.stp(p2);
        m3.clk(p3);
        m4.stp(p4); 
      }
    //=============================CLOCKWISE===========================
      void clockwise(byte p1, byte p2, byte p3, byte p4) 
      {
        m1.aclk(p1);
        m2.aclk(p2);
        m3.aclk(p3);
        m4.aclk(p4);
      }
    //=============================ANTICLOCKWISE===========================
      void anticlockwise(byte p1, byte p2, byte p3, byte p4) 
      {
        m1.clk(p1);
        m2.clk(p2);
        m3.clk(p3);
        m4.clk(p4); 
      }
    //=============================BRAKE===========================
      void brake(byte p1, byte p2, byte p3, byte p4) 
      {
        m1.stp(0);
        m2.stp(0);
        m3.stp(0);
        m4.stp(0); 
      }
};                //========================Directions CLASS ENDS

//========================DECLARING bot AS Directions========================
 
Directions bot;
