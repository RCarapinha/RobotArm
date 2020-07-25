#include <SoftwareSerial.h> // TX RX software library for bluetooth

#include <Servo.h> // servo library 
Servo myservo1, myservo2, myservo3; // servo name

int bluetoothTx = 10; // bluetooth tx to 10 pin
int bluetoothRx = 11; // bluetooth rx to 11 pin

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup(){
  //Setup usb serial connection to computer
  Serial.begin(9600);
  
  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
}

void loop()
{
  //Read from bluetooth and write to usb serial
  if(bluetooth.available()>= 2 ){
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1 * 256) + servopos;
    Serial.println(realservo);

    if (realservo >= 1000 && realservo <1180) {
      myservo1.attach(5);
      myservo2.detach();
      myservo3.detach();
      int servo1 = realservo;
      servo1 = map(servo1, 1000, 1180, 0, 180);
      myservo1.write(servo1);
      delay(10);
    }
    if (realservo >= 2000 && realservo <2180) {
      myservo1.detach();
      myservo2.attach(6);
      myservo3.detach();
      int servo2 = realservo;
      servo2 = map(servo2, 2000, 2180, 0, 180);
      myservo2.write(servo2);
      delay(10);
    }
    if (realservo >= 3000 && realservo <3180) {
      myservo1.detach();
      myservo2.detach();
      myservo3.attach(7);
      int servo3 = realservo;
      servo3 = map(servo3, 3000, 3180, 0, 180);
      myservo3.write(servo3);
      delay(10);
    }
  }
}
