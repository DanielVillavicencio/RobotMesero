#include <Espalexa.h>
#include <WiFi.h>

Espalexa ControlVoz;
int R = 13; // Pin del LED rojo
int G = 4;
int B = 16;

void LedRojo(uint8_t brillo);
void LedVerde(uint8_t brillo);
void LedAzul(uint8_t brillo);

void setup() {
  Serial.begin(115200);
  
  pinMode(R, OUTPUT); // Configura el pin del LED rojo como salida
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  Serial.println("Starting WiFi connection...");
  WiFi.begin("Lab", "B0980z2(");
  Serial.print("Connecting to WiFi");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println(" CONNECTED!");
  
  Serial.println("Adding device to Espalexa...");
  ControlVoz.addDevice("Led Rojo", LedRojo);
  ControlVoz.addDevice("Led Verde", LedVerde);
  ControlVoz.addDevice("Led Azul", LedAzul);
  Serial.println("Starting Espalexa...");
  ControlVoz.begin();
  Serial.println("Setup complete!");
}

void loop() {
  ControlVoz.loop();
  delay(1);
}

void LedRojo(uint8_t brillo){
  Serial.print("Setting LED brightness to ");
  Serial.println(brillo);
  if(brillo){
    digitalWrite(R, HIGH);
  }else{
    digitalWrite(R, LOW);
  }
}

void LedVerde(uint8_t brillo){
  Serial.print("Setting LED brightness to ");
  Serial.println(brillo);
  if(brillo){
    digitalWrite(G, HIGH);
  }else{
    digitalWrite(G, LOW);
  }
}

void LedAzul(uint8_t brillo){
  Serial.print("Setting LED brightness to ");
  Serial.println(brillo);
  if(brillo){
    digitalWrite(B, HIGH);
  }else{
    digitalWrite(B, LOW);
  }
}
