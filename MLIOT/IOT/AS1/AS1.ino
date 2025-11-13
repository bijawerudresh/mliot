#include <Servo.h>

#define TRIG_PIN 5
#define ECHO_PIN 18
#define SERVO_PIN 21

Servo myServo;

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  myServo.attach(SERVO_PIN);
}

void loop() {
 
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  
  long duration = pulseIn(ECHO_PIN, HIGH);

  int distance = duration * 0.034 / 2;

 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  
  if (distance < 10 && distance > 0) {
    myServo.write(90);  
  } else {
    myServo.write(0); 
  }

  delay(500);
}
