//Define Pin
  // Motor A connections = benTrai
  int enA = 9; //tháo Jumper sẵn
  int in1 = 8;
  int in2 = 7;
  // Motor B connections = benPhai
  int enB = 3; //tháo Jumper sẵn
  int in3 = 5;
  int in4 = 4;

//Define speed
  //0-255 ADC ~ 0-100%
  int speed100 = 255;
  int speed75 = 191;
  int speed50 = 127;
  int speed35 = 90;
  int speed25 = 64;
  int speed15 = 38;
  int speed0 = 0;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  stop(); 
  delay(2000);

  //tienPhai();
  //delay(2000);
  //stop(); delay(2000);

  tienTrai(); 
  //stop();
}

void loop(){}

void tienPhai(){
  // Turn on motor A & B and go forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set motors to maximum speed
  analogWrite(enA, speed100);
  analogWrite(enB, speed75);
}
void tienTrai() //dang loi
{ 
  // Turn on motor A & B and go forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set motors to maximum speed //0 & 100 --> quay tai cho
  analogWrite(enA, speed35); //75 --> 50 
  analogWrite(enB, speed100);
}

void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}