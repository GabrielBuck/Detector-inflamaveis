#ifndef Sensores_hpp
#define Sensores_hpp

//Biblitecas para o DHT-11 (Temperatura e Humidade)
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

const int pino_dht = 11;  //Pino Digital do sensor DHT-11
const int dhtType = 11;   //Modelo do Sensor DHT
const int pino_mq2 = A0;  //Pino Analogico do sensor MQ-2

DHT dht(dhtType, pino_dht);  //Construtor do DHT-11

class Sensores {

private:


public:

  /************************ SETUP ****************************/
  //Setup geral
  void setup() {
    dht.begin();
  }

  /************************* MQ-2 (Gas) *****************************/

  //Mede a concentracao de gas
  int ler_gas() {
    int leitura = analogRead(pino_mq2);
    Serial.print("Gas: ");
    Serial.println(leitura);
    return leitura;
  }

  /*************** DHT-11 (Humidade e Temperatura) ********************/

  //Mede a humidade do ambiente
  int ler_humidade() {
    int leitura = dht.readHumidity();
    Serial.print("Humidade: ");
    Serial.println(leitura);
    return leitura;
  }

  //Mede a temperatura do ambiente
  int ler_temperatura() {
    int leitura = dht.readTemperature();
    Serial.print("Temperatura: ");
    Serial.println(leitura);
    return leitura;
  }
};
#endif