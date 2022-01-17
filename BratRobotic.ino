
#define REMOTEXY_MODE__HARDSERIAL

#include <RemoteXY.h>
#include <Servo.h>
// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,4,0,0,0,125,0,13,13,1,
  4,128,16,34,33,6,2,26,4,0,
  16,43,6,33,2,26,4,128,16,86,
  33,6,2,26,2,0,3,14,16,6,
  2,26,31,31,79,78,0,79,70,70,
  0,129,0,10,4,47,6,17,66,82,
  65,200,154,32,82,79,66,79,84,73,
  67,0,129,0,24,57,28,4,17,84,
  114,97,110,115,108,97,200,155,105,101,
  32,40,79,121,41,0,129,0,25,25,
  14,4,17,71,114,105,112,112,101,114,
  0,129,0,21,79,23,4,17,82,111,
  116,97,200,155,105,101,32,40,79,120,
  41,0 };
  
struct {

  
  int8_t griper; 
  int8_t translation; 
  int8_t rotation; 

    // other variable
  uint8_t connect_flag;  
   uint8_t switch_1;

} RemoteXY;
#pragma pack(pop)

  Servo rotation_servo;
  Servo translation_servo;
  Servo griper1_servo;
  Servo griper2_servo;

void setup() 
{
  RemoteXY_Init (); 
  rotation_servo.attach(7);
  translation_servo.attach(5);
  griper1_servo.attach(6);
  griper2_servo.attach(4);
  rotation_servo.write(0);
  translation_servo.write(0);
  griper1_servo.write(0);
  griper2_servo.write(0);

  
}

void loop() 
{ 
  RemoteXY_Handler ();
if (RemoteXY.switch_1 == HIGH){
  rotation_servo.write(RemoteXY.rotation);
  translation_servo.write(RemoteXY.translation);

  
int j=RemoteXY.griper;
    griper1_servo.write(100-j);
    griper2_servo.write(j);

}
else 
{
 rotation_servo.write(0);
 translation_servo.write(0);
 griper1_servo.write(0);
 griper2_servo.write(0);
}
}
