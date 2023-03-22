import serial
import time

if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyACM0', 9600)
    ser.reset_input_buffer()

    while True:
        print("What would you like to fold?\n")
        print("1: Short Sleeve Shirt\n")
        print("2: Long Sleeve Shirt\n")
        print("3: Trousers\n")
        sel = input()
        match sel:
            case '1':
                ser.write('1'.encode())
                item = "short sleeve shirt"
            case '2':
                ser.write('2'.encode())
                item = "long sleeve shirt"
            case '3':
                ser.write('3'.encode())
                item = "trousers"
            case _:
                print("Invalid selection")
                continue
        print("Please wait while the shirt is folded...\n")
        time.sleep(5)
        print(f"your {item} is ready!\n")


