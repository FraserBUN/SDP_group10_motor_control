#include <servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup()
{
    Serial.begin(9600);//Set Baud Rate to 9600 bps
    servo1.attach(9);
}
void loop()
{
    uint16_t val;
    double dat;
    val=analogRead(A0);//Connect Analog pin to A0
    dat = (double) val * 0.47-33.4;
    std::cout << "Position: " << dat << "degrees" << std::endl;
    double pos = dat;
    delay(100);
}

void control_motor()
{
    while (True) {
        int inPos = 0;
        std::cout << "Enter position: ";
        std::cin >> inPos;
        inP = map(inPos, 500, 1500, 0, 270);
        servo1.write(pos);
        delay(15);
        servo1.write(0);
        delay(15);
    }
}