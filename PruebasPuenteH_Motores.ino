//Variables
const int PWMDerecha = 19;
//const int PWMIzquierda = 18;
// Motor Izquierdo
const int ENA = 16;
const int IN1 = 17;
const int IN2 = 5;
// Motor Derecho
//const int ENB = 16;
//const int IN3 = 12;
//const int IN4 = 14;
//PWM Configuracion
const int frecuencia = 50000;
const int canalDerecha = 0;
const int canalIzquierda = 1;
const int resolucion = 8; //Resolucion de 8 bits 0-255

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ledcSetup(canalDerecha, frecuencia, resolucion);
//  ledcSetup(canalIzquierda, frecuencia, resolucion);
  ledcAttachPin(PWMDerecha, canalDerecha);
//  ledcAttachPin(PWMIzquierda, canalIzquierda);
//  ledcWrite(canal, ciclo_de_trabajo);

  //Variables Puente H:
   pinMode(ENA, OUTPUT);
//   pinMode(ENB, OUTPUT);
   pinMode(IN1, OUTPUT);
   pinMode(IN2, OUTPUT);
   avanza();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void avanza(){
  Serial.print("Avanzando");
    //Habilitacion motor derecha en giro positivo
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    ledcWrite(canalDerecha, 220);
  
}
