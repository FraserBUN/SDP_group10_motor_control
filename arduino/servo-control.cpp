#include <servo.h>

Servo south;
Servo east;
Servo west;
Servo north;
Servo centre;
Servo extraSouth;

void setup()
{
    Serial.begin(9600);//Set Baud Rate to 9600 bps
    south.attach(9);
    east.attach(10);
    west.attach(11);
    north.attach(12);
    centre.attach(13);
    extraSouth.attach(8);

}

void actuate(Servo servo, double pos)
{
    servo.write(pos);
    delay(750);
    servo.write(0);
}

void shirt_short()
{
    actuate(extraSouth, 110);
    actuate(south, 110);
    actuate(east, 110);
    actuate(west, 110);
    actuate(centre, 110);
    actuate(north, 150);
}

void shirt_long()
{
    actuate(extraSouth, 110);
    actuate(south, 110);
    actuate(east, 110);
    actuate(west, 110);
    actuate(east, 110);
    actuate(west, 110);
    actuate(centre, 110);
    actuate(north, 150);
}

void trousers()
{
    actuate(centre, 110);
    actuate(east, 110);
    actuate(west, 110);
    actuate(north, 150);
}

void loop()
{
    if (Serial.available() > 0)
    {
        char usb = Serial.read();
        if (usb == '1')
        {
            shirt_short();
        }
        else if (usb == '2')
        {
            shirt_long();
        }
        else if (usb == '3')
        {
            trousers();
        }
    }
}

