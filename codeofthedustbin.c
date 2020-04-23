#include <Servo.h>

Servo servo;

int irPin = 6;

int servoPin = 7;

int led= 10;

Int ho=LOW;

long duration, dist, average;

long aver[3]; //array for average

void setup() {

Serial.begin(9600);

servo.attach(servoPin);

pinMode(irPin, INPUT);

servo.write(0);

delay(100);

servo.detach();

}

void measure() {

pinMode(irPin, INPUT);

duration = pulseIn(irPin, HIGH);

dist = (duration/2) / 29.1; }

void loop() {

for (int i=0;i<=2;i++) {

measure();

aver[i]=dist;

delay(10);

}

dist=(aver[0]+aver[1]+aver[2])/3;

ho= digitalRead(irPin);

if ( ho==HIGH) {

//Change distance as per your need

servo.attach(servoPin);

delay(1);

servo.write(0);

delay(3000);

servo.write(150);

delay(1000);

servo.detach();

}

Serial.print(dist);

}
