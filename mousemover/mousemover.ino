// Include the servo library:
#include <Servo.h>

// Create the servo objects:
Servo myservoLeft;
Servo myservoRight;

// Define the servo pins, digital
#define servoPinLeft 9
#define servoPinRight 10
// Arduino pin for the potentiometer - analog
#define potPin A0

// variable to store the reading from the analog input
int reading = 0;

// delay time in millisecods
inte delayTime = 10000

// Create a variable to store the servo position:
int angle = 0;

void setup() {
  // Attach the Servo variables to the pins:
  myservoLeft.attach(servoPinLeft);
  myservoRight.attach(servoPinRight);
}

void loop() {
  // read the analog input
  reading = analogRead(potPin);

  // map the input to a value between 5000 (5 sec.) and 60000 ( 1 min)
  delayTime = map(reading, 0, 1023, 5000, 50000);
  
  // Tell the servo to go to a particular angle:
  myservoLeft.write(90);
  delay(1000);
  myservoLeft.write(180);
  delay(1000);
  myservoLeft.write(0);
  delay(1000);
  // Sweep from 0 to 180 degrees:
  for (angle = 0; angle <= 180; angle += 1) {
    myservoLeft.write(angle);
    delay(15);
  }
  // And back from 180 to 0 degrees:
  for (angle = 180; angle >= 0; angle -= 1) {
    myservoLeft.write(angle);
    delay(30);
  }
  delay(delayTime);
}
