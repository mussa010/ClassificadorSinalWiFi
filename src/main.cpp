#include <Arduino.h>
#include<WiFi.h>
#include<locale.h>

void setup() {
  Serial.begin(115200);
  WiFi.setHostname("Verificador de sinal");

  int16_t numRedes = WiFi.scanNetworks();
  String rede = "", senha = "";
  Serial.print("Numero de redes: ");
  Serial.println(numRedes);
  for(int i = 0; i < numRedes; i++) {
    String rede = WiFi.SSID(i);
    int32_t sinal = WiFi.RSSI(i);
    Serial.print("Rede ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(rede);
    Serial.print("Sinal: ");
    Serial.print(sinal);
    Serial.println(" dBm");
    if(sinal > -50) {
      Serial.println("Sinal excelente!");
    } else if(sinal < -50 && sinal > -60) {
      Serial.println("Sinal bom!");
    } else if(sinal < -60 && sinal > -70) {
      Serial.println("Sinal razoavel!");
    } else if(sinal < -70 && sinal > -80) {
      Serial.println("Sinal ruim!");
    } else {
      Serial.println("Sinal horrivel!");
    }
  }
  Serial.println("*******************************\n");
  Serial.print("Insira o numero da rede que deseja conectar: ");
  while(Serial.available() == 0) {
    delay(100);
  }
  rede = Serial.readStringUntil('\n');
  Serial.flush();
  Serial.print("\nInsira a senha da rede: ");
  while(Serial.available() == 0) {
    delay(100);
  }
  senha = Serial.readStringUntil('\n');
  Serial.flush();

  
}

void loop() {


}
