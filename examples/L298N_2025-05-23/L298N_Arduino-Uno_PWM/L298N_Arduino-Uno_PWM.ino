//declaring pins that are connected to L298N's control pins.
//can chon chan co ho tro PWM ~ doi voi 2 chan enA va enB

// Motor A connections
int enA = 9; //ham tra ve gia tri int, gia tri cua bien enA la 9
//so 3 = chan digital so 3, co ho tro PWM
//neu muon dung chan Ax (analog), phai goi ro la Ax
int in1 = 8;  //int = integer = so nguyen
int in2 = 7;

// Motor B connections
int enB = 3;
//so 3 = chan digital so 3, co ho tro PWM
//neu muon dung chan A3 (analog), phai goi ro la A3
int in3 = 5;
int in4 = 4;

void setup() {
	// Set all the motor control pins to outputs (Digital)
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	
	// Turn off motors - Initial state = state that happens at the beginning;
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

void loop() 
{
  //call two user-defined functions = goi 2 chuc nang ma nguoi dung dat ten
  //ten chuc nang rat quen thuoc, khong phai thuat ngu cao sieu
	directionControl();
	delay(1000); //ms
	speedControl();
	delay(1000); //ms
}

// This function lets you control spinning direction of motors
void directionControl() {
	// Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255 --> check datasheet
	analogWrite(enA, 255); //chi la ten goi, khong truyen tin hieu analog
	analogWrite(enB, 255);  //truyen tin hieu PWM - Pulse Width Modulation
  //PWM la cach gia lap tin hieu analog bang cach bat/tat nhanh 1 chan digital o tan so cao
  //chinh la DutyCycles

	// Turn on motor A & B
    //set muc HIGH/ LOW cho cac chan INx de chon dieu quay cua dong co
	digitalWrite(in1, HIGH); //spin clockwise
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH); //spin clockwise
	digitalWrite(in4, LOW);
	delay(2000); //ms
	
	// Now change motor directions
	digitalWrite(in1, LOW); 
	digitalWrite(in2, HIGH); //spin counterclockwise
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH); //spin counterclockwise
	delay(2000); //ms
	
	// Turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

// This function lets you control speed of the motors
void speedControl() {
	// Turn on motors //truoc do da tat het motor trong function directionControl()
  //chon ngau nhien 1 doan code (counter)clockwise
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
	
	// Accelerate from zero to maximum speed
	for (int i = 0; i < 256; i++) //dung bien "i" de chua gia tri dem
  {
		analogWrite(enA, i);
		analogWrite(enB, i);
		delay(20); //ms
	}
	
	// Decelerate from maximum speed to zero
	for (int i = 255; i >= 0; --i) {
		analogWrite(enA, i);
		analogWrite(enB, i);
		delay(20); //ms
	}
	
	// Now turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}