/*
 * LAB Name: Arduino Motor Optical Encoder RPM Measurement
 * Author: Khaled Magdy
 * For More Info Visit: www.DeepBlueMbedded.com
 * Preference: https://deepbluembedded.com/arduino-motor-encoder-optical-encoder-interfacing/
*/
#define ENCODER_PIN 2   //giu nguyen chan D2 thay vi D11
#define ENCODER_N   20

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
  /*
    0-255 ADC ~ 0-100%
    255 = 100% = 220RPM (Phai)
    173 =  68% = 150rpm (Trai)
  */

  int speed100 = 255; //220rPM  (phai 150rpm)
  int speed75 = 191;
  int speed60 = 153; //190RPM
  int speed50 = 127; //175RPM  (phai 100rpm)
  int speed35 = 90;  //140RPM  (phai 60rpm)
  int speed25 = 64;   //90RPM  (125rpm tại 3VDC) (phai khong quay)
  int speed15 = 38;
  int speed0 = 0;
 
unsigned long T1 = 0, T2 = 0, T;
bool MeasDone = 0;
int Motor_RPM = 0;
 
void INT0_ISR(void)
{
  if(MeasDone)
  {
    T2 = micros();
    T = T2 - T1;
    MeasDone = 0;
  }
  else
  {
    T1 = micros();
    MeasDone = 1;
  }
}

void Cat_forward() {
  // Turn on motor A & B and go forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set motors to maximum speed
  //analogWrite(enA, speed25);
  analogWrite(enB, speed100);
}

void Cat_stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

//================//
void setup()
{
  Serial.begin(9600);
  pinMode(ENCODER_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN), INT0_ISR, RISING);

  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Cat_stop(); //Turn off all motors
}
 
void loop()
{
  Cat_forward();

  Motor_RPM = (60000000) / (T * ENCODER_N);
  Serial.print("Motor RPM: ");
  Serial.println(Motor_RPM);
  delay(250);
}