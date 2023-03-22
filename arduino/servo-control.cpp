#include <servo.h>

class ServoWrapper
{
    public:
        void attach(int pin)
        {
            servo.attach(pin);
        }

        ServoWrapper(Servo servo, double pos)
        {
            this->servo = servo;
            this->pos = pos;
        }


        void lift()
        {
            servo.write(pos);
            delay(750);
        }

        void lower()
        {
            servo.write(0);
            delay(750);
        }

        void actuate()
        {
            lift();
            lower();
        }

    private:
        Servo servo;
        double pos;
};

Servo southKernel;
Servo eastKernel;
Servo westKernel;
Servo northKernel;
Servo centreKernel;
Servo extraSouthKernel;

ServoWrapper south(southKernel, 110);
ServoWrapper east(eastKernel, 110);
ServoWrapper west(westKernel, 110);
ServoWrapper north(northKernel, 150);
ServoWrapper centre(centreKernel, 110);
ServoWrapper extraSouth(extraSouthKernel, 110);


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

void actuate(Servo servo)
{
    servo.write(pos);
    delay(750);
    servo.write(0);
}

void shirt_short()
{
    extraSouth.actuate();
    south.actuate();
    east.actuate();
    west.actuate();
    centre.actuate();
    north.actuate();
}

void shirt_long()
{
    extraSouth.actuate();
    south.actuate();
    east.actuate();
    west.actuate();
    east.actuate();
    west.actuate();
    centre.actuate();
    north.actuate();
}

void trousers()
{
    south.actuate();
    east.actuate();
    west.actuate();
    centre.actuate();
    north.actuate();
}

void loop()
{
    if (Serial.available() > 0)
    {
        string usb = Serial.read();
        if (usb == '1')
        {
            shirt_short();
        }
        else if (usb == '2')
        {
            shirt_long();
        }
        else if (usb == '3') {
            trousers();
        }
    }
}

