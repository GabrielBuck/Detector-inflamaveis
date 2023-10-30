#ifndef Operacional_hpp
#define Operacional_hpp

#include <Servo.h>

Servo servo;  //Cria objeto "servo"

class Operacional {

private:

  const int buzzer_1 = 2;  // Pino digital do Buzzer 1
  const int buzzer_2 = 2;  // Pino digital do Buzzer 2

  const int led_red = 2;    // Pino digital do Buzzer 1
  const int led_green = 2;  // Pino digital do Buzzer 2
  const int led_blue = 2;   // Pino digital do Buzzer 1

public:

  /************************ SETUP ****************************/
  //Setup geral
  void setup() {
    //Servo
    servo.attach(9);
    servo.write(0);  //Posicao inicial
    //Vermelho
    pinMode(led_red, OUTPUT);
    //Amarelo
    pinMode(12, OUTPUT);
    //Verde
    pinMode(13, OUTPUT);
    //Buzzers
    pinMode(buzzer_1, OUTPUT);
    pinMode(buzzer_1, OUTPUT);
  }

  /********************************** BUZZERS ***************************************/
  //Toca um alarme
  void alarme() {

    for (int i = 0; i < 10; i++) {
      tone(buzzer_1, 262, 200);  //Pino, frequencia, tempo
      tone(buzzer_2, 262, 200);
      delay(500);
      tone(buzzer_1, 294, 200);
      tone(buzzer_2, 294, 200);
    }
    //Para o som
    noTone(buzzer_1);
    noTone(buzzer_2);
  }

  /************************** Servo ****************************/
  //Movimenta o servo no angulo fornecido
  void move_servo(int ang) {
    for (int i = 0; i < ang; i++) {
      servo.write(i);
    }
  }

  /********************************** LEDS ***************************************/
  // Liga os 3 Leds de alguma cor
  void liga_led(char c) {

    //Vermelho
    if (c == 'R') digitalWrite(led_red, HIGH);
    //Verde
    if (c == 'G') digitalWrite(led_green, HIGH);
    //Amarelo
    if (c == 'Y') digitalWrite(led_blue, HIGH);
  }

  // Liga os 3 Leds de alguma cor
  void desliga_led(char c) {

    //Vermelho
    if (c == 'R') digitalWrite(led_red, LOW);
    //Verde
    if (c == 'G') digitalWrite(led_green, LOW);
    //Amarelo
    if (c == 'B') digitalWrite(led_blue, LOW);
  }
};
#endif