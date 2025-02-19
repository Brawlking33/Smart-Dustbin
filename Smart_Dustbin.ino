// C++ code
//
#include <Servo.h>

int Distance = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_6;

void setup()
{
  Serial.begin(9600);
  servo_6.attach(6, 500, 2500);
}

void loop()
{
  Distance = 0.01723 * readUltrasonicDistance(3, 4);
  Serial.println(Distance);
  if (Distance < 30) {
    servo_6.write(180);
    delay(1000); // Wait for 1000 millisecond(s)
  } else {
    servo_6.write(0);
    delay(1000); // Wait for 1000 millisecond(s)
  }
}
