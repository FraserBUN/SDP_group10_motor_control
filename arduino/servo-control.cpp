
#include <Servo.h>

Servo south;
Servo east;
Servo west;
Servo north;
Servo centre;
int up_time = 400;
int down_time = 500;

void setup()
{
    Serial.begin(9600);//Set Baud Rate to 9600 bps
    south.attach(3);
    east.attach(5);
    west.attach(6);
    north.attach(10);
    centre.attach(9);

}


void up(Servo servo)
{
  servo.write(0);
}

void down (Servo servo)
{
  servo.write(75);  
}

void north_up(){
    north.write(80);
  }

void north_down(){
    north.write(0);
  }

void loop()
{
  down(south);
  down(centre);
  down(west);
  down(east);
      if (Serial.available() > 0)
    {
        char usb = Serial.read();
        if (usb == '1')
        {
  up(south);
  delay(up_time);
  down(south);
  delay(down_time);
  up(west);
  delay(up_time);
  down(west);
  delay(down_time);
  up(east);
  delay(up_time);
  down(east);
  delay(down_time);
  up(centre);
  delay(up_time);
  down(centre);
  delay(down_time);
  north_up();
  delay(500);
  north_down();
  delay(750);
  
        }
    }
}

