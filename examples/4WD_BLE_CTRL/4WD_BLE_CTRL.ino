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

//Define speed
  //0-255 ADC ~ 0-100%
  int speed100 = 255;
  int speed75 = 191;
  int speed60 = 153;
  int speed50 = 127;
  int speed35 = 90;
  int speed25 = 64;
  int speed15 = 38;
  int speed0 = 0;

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
    Cat_forward();
  }
  else //ngung nhan nut thi xe ngung chay
  {
    Cat_stop();
  }
  if (GamePad.isDownPressed())
  {
    //Serial.print("DOWN");
    //bwd_acclerate();
    Cat_backward();
  }

  if (GamePad.isLeftPressed())
  {
    //Serial.print("Left");
    tienTrai();
  }

  if (GamePad.isRightPressed())
  {
    //Serial.print("Right");
    tienPhai();
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
    //Cat_stop(); //Turn off all motors
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
void Cat_forward() {
  // Turn on motor A & B and go forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set motors to maximum speed
  analogWrite(enA, speed60);
  analogWrite(enB, speed60);
}

void Cat_backward(){ 
  // Now change motor directions - go backward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // Set motors to maximum speed
  analogWrite(enA, speed75);
  analogWrite(enB, speed75);
}

void tienPhai(){
  // Turn on motor A & B and go forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set motors to maximum speed
  analogWrite(enA, speed100);
  analogWrite(enB, speed25);
}

void tienTrai() //dang loi
{ 
  // Turn on motor A & B and go forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set motors to maximum speed //0 & 100 --> quay tai cho
  analogWrite(enA, speed25); //75 --> 50 
  analogWrite(enB, speed100);
}

void Cat_stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}