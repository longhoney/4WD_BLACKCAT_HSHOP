//Define Pin
  // Motor A connections
  int enA = 9; //tháo Jumper sẵn
  int in1 = 8;
  int in2 = 7;
  // Motor B connections
  int enB = 3; //tháo Jumper sẵn
  int in3 = 5;
  int in4 = 4;

//Define speed
  /*
    0-255 ADC ~ 0-100%
    255 = 100% = 220RPM (Phai)
    173 =  68% = 150rpm (Trai)
  */

  int speed100 = 255; //220rPM  (phai 150rpm)
  int speed60 = 153; //190RPM
  int speed50 = 127; //175RPM  (phai 100rpm)
  int speed35 = 90;  //140RPM  (phai 60rpm)
  int speed25 = 64;   //90RPM  (125rpm tại 3VDC) (phai khong quay)
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
  
  forward();
  //backward();
  //speedForward();
  //fwd_acclerate();
  delay(5000);
  //delay(2000);
  //bwd_acclerate();
  stop();
}

void loop() {
  /*
  forward_backward();
  delay(2000); //khoảng nghỉ 1 giây = 1000ms
  speedControl();
  delay(2000);
  */
}

// This function lets you control spinning direction of motors
void forward() {
  // Turn on motor A & B and go forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  //0-255bit ADC
  analogWrite(enA, 173);
  analogWrite(enB, 255);
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
  delay(2000);

  stop();
}

void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

// This function lets you control speed of the motors
void speedForward() {
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

  delay(5000);
  stop();
  // Decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i) {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }

  // Now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

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