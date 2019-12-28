o#include <math.h>

const int motor1A = 6; 
const int motor1B = 7;

const int motor2A = 2; 
const int motor2B = 3;

const int motor3A = 4; 
const int motor3B = 5;
int power = 255;

float degToRad(float dir){
  return (dir) * M_PI / 180;
}

void motors(int dir){
  // set motors to move in direction dir degrees
  dir = 360 - dir;
  float m1 = cos(deg(150-dir));
  float m2 = cos(deg(30-dir));
  float m3 = cos(deg(270-dir));
  int speedA = int(m1*255);
  int speedB = int(m2*255);
  int speedC = int(m3*255);
  
  if (m1 >= 0){
    analogWrite(motor1A, speedA);
    analogWrite(motor1B, 0);
  }
  else {
    analogWrite(motor1A, 0);
    analogWrite(motor1B, abs(speedA));
  }
  if (m2 >= 0){
    analogWrite(motor2A, speedB);
    analogWrite(motor2B, 0);
  }
  else {
    analogWrite(motor2A, 0);
    analogWrite(motor2B, abs(speedB));
  }
  if (m3 >= 0){
    analogWrite(motor3A, speedC);
    analogWrite(motor3B, 0);
  }
  else {
    analogWrite(motor3A, 0);
    analogWrite(motor3B, abs(speedC));
  }
}

void turn(bool dir){
  /* true turns right
      false turns left */
  if (dir) {
    analogWrite(motor1A, 0);
    analogWrite(motor1B, 255);
    analogWrite(motor2A, 0);
    analogWrite(motor2B, 255);
    analogWrite(motor3A, 0);
    analogWrite(motor3B, 255);
  }
  if (!dir) {
    analogWrite(motor1A, 255);
    analogWrite(motor1B, 0);
    analogWrite(motor2A, 255);
    analogWrite(motor2B, 0);
    analogWrite(motor3A, 255);
    analogWrite(motor3B, 0);
  }
}

void motorOff(){
  // turn Off all motors
  analogWrite(motor1A, 0);
  analogWrite(motor1B, 0);
  analogWrite(motor2A, 0);
  analogWrite(motor2B, 0);
  analogWrite(motor3A, 0);
  analogWrite(motor3B, 0);
}

void star(){
  motors(0);
  delay(1000);
  motors(180);
  delay(1000);
  motors(45);
  delay(1000);
  motors(225);
  delay(1000);
  motors(90);
  delay(1000);
  motors(270);
  delay(1000);
  motors(135);
  delay(1000);
  motors(315);
  delay(1000);
  motors(180);
  delay(1000);
  motors(0);
  delay(1000);
  motors(225);
  delay(1000);
  motors(45);
  delay(1000);
  motors(270);
  delay(1000);
  motors(90);
  delay(1000);
  motors(315);
  delay(1000);
  motors(136);
  delay(1000);
  motors(360);
  delay(1000);
  motors(180);
  delay(1000);
}

void setup() {
  // Setup motors
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(motor3A, OUTPUT);   
  pinMode(motor3B, OUTPUT);

  // Set up Serial
  Serial.begin(9600);

  motors(-225);
  delay(800);
  motorsOff();

}

void loop() {
}
