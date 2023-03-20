

import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)

def setup_gpio_pwm(pins,speed):
	servo = []
	for pin in pins:
		GPIO.setup(pin,GPIO.OUT)
		servo.append(GPIO.PWM(pin,100))
	return servo

class Servo:

	def __init__(self, pin, size):
		self.pin = pin
		GPIO.setup(pin, GPIO.OUT)

		if size == 'big':
			self.control = GPIO.PWM(pin,100)

	def clockwise(self):
		self.control.ChangeFrequency(46.95)
		self.control.ChangeDutyCycle(6.1)

	def stop(self):
		servo.ChangeFrequency(46.51)
		servo.ChangeDutyCycle(6.98)

	def anti_clockwise(self):
		servo.ChangeFrequency(46.1)
		servo.ChangeDutyCycle(7.83)
		time.sleep(inTime)
		fraserStop(servo)

	def actuate(self):
		print("Starting up servo")
		self.control.start(0)

		print("acutation will start in 1 second")
		time.sleep(1)

		print("actuating")
		self.clockwise
		time.sleep(waitTime)

		print("returning to rest")
		self.anti_clockwise
		time.sleep(waitTime)
		self.stop()

		self.control.stop()

def clockwise(servo,inTime):
	servo.ChangeFrequency(46.95)
	servo.ChangeDutyCycle(6.1)
	time.sleep(inTime)
	servo.ChangeFrequency(46.51)
	servo.ChangeDutyCycle(6.98)

def fraserStop(servo):
	servo.ChangeFrequency(46.51)
	servo.ChangeDutyCycle(6.98)

def antiClockwise(servo,inTime):
	servo.ChangeFrequency(46.1)
	servo.ChangeDutyCycle(7.83)
	time.sleep(inTime)
	fraserStop(servo)


servos = setup_gpio_pwm([11],50)

for servo in servos:
	servo.start(0)
	clockwise(servo,5)
	time.sleep(5)
	antiClockwise(servo,5)
	servo.stop()
GPIO.cleanup()

