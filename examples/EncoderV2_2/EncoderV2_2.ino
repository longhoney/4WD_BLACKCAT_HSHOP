/// Variables //////////////////////////////////////////////////////////////////////////////////////////////////////////////
int encoder_pin = 11;             //Pin 2, donde se conecta el encoder       
unsigned int rpm = 0;           // Revoluciones por minuto calculadas.
float velocity = 0;                  //Velocidad en [Km/h]
volatile byte pulses = 0;       // Número de pulsos leidos por el Arduino en un segundo
unsigned long timeold = 0;  // Tiempo 
unsigned int pulsesperturn = 20; // Número de muescas que tiene el disco del encoder.
const int wheel_diameter = 64;   // Diámetro de la rueda pequeña[mm]
static volatile unsigned long debounce = 0; // Tiempo del rebote.

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

////  Configuración del Arduino /////////////////////////////////////////////////////////
void setup(){
   Serial.begin(9600); // Configuración del puerto serie  
   pinMode(encoder_pin, INPUT); // Configuración del pin nº2
   attachInterrupt(0, counter, RISING); // Configuración de la interrupción 0, donde esta conectado. 
   pulses = 0;
   rpm = 0;
   timeold = 0;
  Serial.print("Seconds ");
  Serial.print("RPM ");
  Serial.print("Pulses ");
  Serial.println("Velocity[Km/h]");

  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Cat_stop(); //Turn off all motors
}
////  Programa principal ///////////////////////////////////////////////////////////////////////
 void loop(){
  Cat_forward();

  if (millis() - timeold >= 1000){  // Se actualiza cada segundo
      noInterrupts(); //Don't process interrupts during calculations // Desconectamos la interrupción para que no actué en esta parte del programa.
      rpm = (60 * 1000 / pulsesperturn )/ (millis() - timeold)* pulses; // Calculamos las revoluciones por minuto
      velocity = rpm * 3.1416 * wheel_diameter * 60 / 1000000; // Cálculo de la velocidad en [Km/h] 
      timeold = millis(); // Almacenamos el tiempo actual.
      Serial.print(millis()/1000); Serial.print("       ");// Se envia al puerto serie el valor de tiempo, de las rpm y los pulsos.
      Serial.print(rpm,DEC); Serial.print("   ");
      Serial.print(pulses,DEC); Serial.print("     ");
      Serial.println(velocity,2); 
      pulses = 0;  // Inicializamos los pulsos.
      interrupts(); // Restart the interrupt processing // Reiniciamos la interrupción
  }
}
////Fin de programa principal //////////////////////////////////////////////////////////////////////////////////
///////////////////////////Función que cuenta los pulsos buenos ///////////////////////////////////////////
void counter(){
  if(  digitalRead (encoder_pin) && (micros()-debounce > 500) && digitalRead (encoder_pin) ) { 
// Vuelve a comprobar que el encoder envia una señal buena y luego comprueba que el tiempo es superior a 1000 microsegundos y vuelve a comprobar que la señal es correcta.
        debounce = micros(); // Almacena el tiempo para comprobar que no contamos el rebote que hay en la señal.
        pulses++;}  // Suma el pulso bueno que entra.
        else ; 
}

void Cat_forward() {
  // Turn on motor A & B and go forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set motors to maximum speed
  analogWrite(enA, speed100);
  analogWrite(enB, speed100);
}

void Cat_stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}