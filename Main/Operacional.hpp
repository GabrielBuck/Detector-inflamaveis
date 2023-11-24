#ifndef Operacional_hpp
#define Operacional_hpp

#include <Servo.h>



Servo servo;  //Cria objeto "servo"

class Operacional {

private:

  const int buzzer_1 = 2;  // Pino digital do Buzzer 1
  // const int buzzer_2 = 2;  // Pino digital do Buzzer 2

  const int led_red = 12;     // Pino digital do Buzzer 1
  const int led_green = 9;    // Pino digital do Buzzer 2
  const int led_yellow = 10;  // Pino digital do Buzzer 1

public:

  /************************ SETUP ****************************/
  //Setup geral
  void setup() {
    //Servo
    servo.attach(8);
    servo.write(60);  //Posicao inicial
    //Vermelho
    pinMode(led_red, OUTPUT);
    //Amarelo
    pinMode(led_yellow, OUTPUT);
    //Verde
    pinMode(led_green, OUTPUT);
    //Buzzers
    pinMode(buzzer_1, OUTPUT);
    // pinMode(buzzer_2, OUTPUT);
  }

  /********************************** BUZZERS ***************************************/
  //Toca um alarme
  void buzzer(char musica = 'A') {

    //Alarme Padrao
    if (musica == 'A') {
      for (int i = 0; i < 10; i++) {
        tone(buzzer_1, 262, 200);  //Pino, frequencia, tempo
        // tone(buzzer_2, 262, 200);
        delay(500);
        tone(buzzer_1, 294, 200);
        // tone(buzzer_2, 294, 200);
      }
      //Para o som
      noTone(buzzer_1);
      // noTone(buzzer_2);
    }

    //Musica de Zelda
    if (musica == 'Z') {
      // Reproduza a música diretamente no loop
      tone(buzzer_1, 262, 200);
      delay(250);  // Adiciona um pequeno atraso entre as notas
      noTone(buzzer_1);

      tone(buzzer_1, 262, 200);
      delay(250);
      noTone(buzzer_1);

      tone(buzzer_1, 262, 200);
      delay(250);
      noTone(buzzer_1);

      delay(500);  // Adiciona um intervalo entre cada execução da música
    }
  }

  /************************** Servo ****************************/

  //Movimenta o servo no angulo ANG com DEL delay
  void move_servo(int ang, int del = 15) {
    for (int pos = 0; pos <= ang; pos += 1) {  
      servo.write(pos);                
      delay(del);                           
    }
  }
  void tp_servo(int ang) {
    servo.write(ang);
  }

  /********************************** LEDS ***************************************/
  // Liga os 3 Leds de alguma cor
  void liga_led(char c) {

    //Vermelho
    if (c == 'R') digitalWrite(led_red, HIGH);
    //Verde
    if (c == 'G') digitalWrite(led_green, HIGH);
    //Amarelo
    if (c == 'Y') digitalWrite(led_yellow, HIGH);
  }

  // Liga os 3 Leds de alguma cor
  void desliga_led(char c) {

    //Vermelho
    if (c == 'R') digitalWrite(led_red, LOW);
    //Verde
    if (c == 'G') digitalWrite(led_green, LOW);
    //Amarelo
    if (c == 'Y') digitalWrite(led_yellow, LOW);
  }
};
#endif