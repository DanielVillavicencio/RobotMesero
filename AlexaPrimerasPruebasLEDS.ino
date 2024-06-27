#include <Espalexa.h>
#include <WiFi.h>
//Objeto Alexa
Espalexa Control;
//Variables
const int PWMDerecha = 19;
const int PWMIzquierda = 18;
// Motor Izquierdo
const int ENA = 16;
const int IN1 = 17;
const int IN2 = 5;
// Motor Derecho
const int ENB = 16;
const int IN3 = 12;
const int IN4 = 14;
//PWM Configuracion
const int frecuencia = 100;
const int canalDerecha = 0;
const int canalIzquierda = 1;
const int resolucion = 8; //Resolucion de 8 bits 0-255

//Prototipo de funciones
void izquierda(uint8_t brillo);
void derecha(uint8_t brillo);
void avanza(uint8_t brillo);
void reversa(uint8_t brillo);
void daVueltas(uint8_t brillo);
void detente(uint8_t brillo);
void cuadrado(uint8_t brillo);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //Conexion WiFi
  Serial.println("Starting WiFi conecction...");
  WiFi.begin("Lab","B0980z2(");
  Serial.print("Conectando WiFi...");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("CONNECTED");
//  Dispositivos Alexa
  Control.addDevice("Avanza",avanza);
  Control.addDevice("Reversa",reversa);
  Serial.println("Starting Alexa...");
  Control.begin();
  Serial.println("Alexa is Ready!");

  //Configuracion PWM
  ledcSetup(canalDerecha, frecuencia, resolucion);
  ledcSetup(canalIzquierda, frecuencia, resolucion);
  ledcAttachPin(PWMDerecha, canalDerecha);
  ledcAttachPin(PWMIzquierda, canalIzquierda);
//  ledcWrite(canal, ciclo_de_trabajo);

  //Variables Puente H:
   pinMode(ENA, OUTPUT);
   pinMode(ENB, OUTPUT);
   pinMode(IN1, OUTPUT);
   pinMode(IN2, OUTPUT);
   pinMode(IN3, OUTPUT);
   pinMode(IN4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Control.loop();
  delay(1);
}

//Funciones para Carrito
void izquierda(uint8_t brillo){
  Serial.print("Girando a la izquierda");
  if(brillo){
    //Habilitacion motor derecha en giro positivo
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    //Habilitacion motor izquierda en giro positivo
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    ledcWrite(canalDerecha, 255);
  }else{
    ledcWrite(canalDerecha, 0);
  }
}

void derecha(uint8_t brillo){
  Serial.print("Girando a la derecha");
  if(brillo){
    //Habilitacion motor derecha en giro positivo
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    //Habilitacion motor izquierda en giro positivo
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    ledcWrite(canalIzquierda, 255);
  }else{
    ledcWrite(canalIzquierda, 0);
  }
}

void avanza(uint8_t brillo){
  Serial.print("Avanzando");
  if(brillo){
    //Habilitacion motor derecha en giro positivo
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    //Habilitacion motor izquierda en giro positivo
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    ledcWrite(canalIzquierda, 50);
    ledcWrite(canalDerecha, 50);
  }else{
    ledcWrite(canalIzquierda, 0);
    ledcWrite(canalDerecha, 0);
  }
}

void reversa(uint8_t brillo){
  Serial.print("De reversa mami...");
  if(brillo){
    //Habilitacion motor derecha en giro positivo
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    //Habilitacion motor izquierda en giro positivo
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    ledcWrite(canalIzquierda, 255);
    ledcWrite(canalDerecha, 255);
  }else{
    ledcWrite(canalIzquierda, 0);
    ledcWrite(canalDerecha, 0);
  }
}


void daVueltas(uint8_t brillo){
  
}

void detente(uint8_t brillo){
  
}

void cuadrado(uint8_t brillo){
  
}
