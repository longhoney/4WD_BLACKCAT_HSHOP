/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

//Define Pin
  // Motor A connections
  int enA = 9; //tháo Jumper sẵn
  int in1 = 8;
  int in2 = 7;
  // Motor B connections
  int enB = 3; //tháo Jumper sẵn
  int in3 = 5;
  int in4 = 4;
  //UART for MKE-M15
  int RxUno = 13;
  int TxUno = 12;

void setup() {
  // Setup Bluetooth
  Serial.begin(9600);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600, RxUno, TxUno);      //Enter baudrate of your bluetooth.Connect bluetooth on Bluetooth port present on evive.

  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Cat_stop(); //Turn off all motors
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  //Serial.print("KeyPressed: ");
  if (GamePad.isUpPressed())
  {
    //Serial.print("UP");
    //fwd_acclerate();
    forward();
  }

  if (GamePad.isDownPressed())
  {
    //Serial.print("DOWN");
    //bwd_acclerate();
    backward();
  }

  if (GamePad.isLeftPressed())
  {
    //Serial.print("Left");
  }

  if (GamePad.isRightPressed())
  {
    //Serial.print("Right");
  }

  if (GamePad.isSquarePressed())
  {
    Serial.print("Square");
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("Circle");
  }

  if (GamePad.isCrossPressed())
  {
    //Serial.print("Cross");
    Cat_stop(); //Turn off all motors
  }

  if (GamePad.isTrianglePressed())
  {
    Serial.print("Triangle");
  }

  if (GamePad.isStartPressed())
  {
    Serial.print("Start");
  }

  if (GamePad.isSelectPressed())
  {
    Serial.print("Select");
  }
  //Serial.print('\n'); //tao khoang cach 1 dong
    //Serial.print('\t');
  //Serial.println(); //tu dong xuong dong
}

//========Cac ham dieu khien xe========//
void fwd_acclerate(){
  // Turn on motor A & B and go forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++) {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }
}

void bwd_acclerate(){
  // Turn on motor A & B and go forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++) {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }
}

void forward() {
  // Set motors to maximum speed
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);

  // Turn on motor A & B and go forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void backward(){
  // Set motors to maximum speed
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);

  // Now change motor directions - go backward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void Cat_stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}