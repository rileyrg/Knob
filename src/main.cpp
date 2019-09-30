#include<Arduino.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

#define SERVO_PIN 9
#define POT_PIN  0   // analog pin used to connect the potentiometer

int pot,servoVal;    // variable to read the value from the analog pin
char buffer[1024];

void setup() {
     Serial.begin(9600);
     myservo.attach(SERVO_PIN);  // attaches the servo on pin 9 to the servo object
}

bool fFirstRun=true;

void loop() {
     pot = analogRead(POT_PIN);            // reads the value of the potentiometer (value between 0 and 1023)
     servoVal = map(pot, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
     myservo.write(servoVal);                  // sets the servo position according to the scaled value
     sprintf(buffer,"Potentiometer value (0-1023) is: %d. Servo value is %d.",pot,servoVal);
     Serial.println(buffer);
     delay(50);
}

