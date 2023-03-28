#include <Servo.h>

Servo south;
Servo east;
Servo west;
Servo north;
Servo centre;
Servo extraSouth;

void setup()
{
    Serial.begin(9600);//Set Baud Rate to 9600 bps
    south.attach(3);
    east.attach(5);
    west.attach(6);
    north.attach(9);
    centre.attach(10);

}

void actuate(Servo servo, double pos)
{
    servo.write(0);
    delay(750);
    servo.write(pos);
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

