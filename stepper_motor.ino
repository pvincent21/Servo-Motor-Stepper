#include <Stepper.h>
#include <Servo.h>
#include <Wire.h>

#define STEPS 200

Stepper stepper(STEPS, 2, 3); // Pin 2 connected to DIRECTION & Pin 3 connected to STEP Pin of Driver
#define motorInterfaceType 1

const int LPE_2           = 9;       const int  RPE_2   = 10;
const int saos_Kiri_2     = 11;      const int saos_Kanan_2    = 12;
bool jalan = false;

Servo bumbu1;

void setup() {
  Serial.begin(115200);
  pinMode(9, OUTPUT);       //pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);      //pinMode(12, OUTPUT);
  digitalWrite(RPE_2, HIGH);
  digitalWrite(LPE_2, HIGH);
  bumbu1.attach(44);
  stepper.setSpeed(1000);
}

void loop() {
  String a = "";
  while (Serial.available()) {
    a = Serial.readStringUntil('\n');
    if (a == "a") {
      jalan = true;
    } else {
      jalan = false;
    }
  }
  if (jalan) {
    Serial.println("jalan");
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    delay(100);
    bumbu1.write(40);
    delay(1500);
  } else {
    Serial.println("mandek");
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    bumbu1.write(0);
    stepper.step(10);
  }
}
