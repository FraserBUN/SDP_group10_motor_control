
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

void actuate(Servo servo, double pos)
{
    servo.write(0);
    delay(up_time);
    servo.write(pos);
    delay(down_time);
}

void up(Servo servo){
    servo.write(0);
  }

void north_up(){
    north.write(80);
  }

void north_down(){
    north.write(0);
  }

void down(Servo servo) {
    servo.write(80);
  }

void shirt_short()
{
    actuate(south, 100);
    actuate(east, 100);
    actuate(west, 100);
    actuate(centre, 100);
    actuate(north, 150);
}

void shirt_long()
{
    actuate(south, 100);
    actuate(east, 100);
    actuate(west, 100);
    actuate(east, 100);
    actuate(west, 100);
    actuate(centre, 100);
    actuate(north, 150);
}

void trousers()
{
    actuate(centre, 100);
    actuate(east, 100);
    actuate(west, 100);
    actuate(north, 150);
}

void loop() {
  if (Serial.available() > 0) {
    char usb = Serial.read();
if (usb == '1'){
  north_down();
    down(east);
      down(south);
        down(west);
          up(centre);
  
  }
if (usb == '2'){
    north_down();
    down(east);
      down(south);
        up(west);
         down(centre);
  }
  if (usb == '3'){
    north_down();
    down(east);
      up(south);
        down(west);
         down(centre);
  }
    if (usb == '4'){
    north_down();
    up(east);
      down(south);
        down(west);
         down(centre);
  }
      if (usb == '5'){
    north_up();
    down(east);
      down(south);
        down(west);
         down(centre);
  }
      if (usb == '6'){
    north_down();
    down(east);
      down(south);
        down(west);
         down(centre);
  }
  }
}
