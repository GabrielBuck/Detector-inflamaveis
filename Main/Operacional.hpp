#ifndef Operacional_hpp
#define Operacional_hpp

#define BUZZER_PIN_1 2  // Pino digital do Buzzer 1
#define BUZZER_PIN_2 2  // Pino digital do Buzzer 2


class Operacional {

private:


public:

/************************ SETUP ****************************/
  //Setup geral
  void setup() {

    //Vermelho
    pinMode(11, OUTPUT);
    //Amarelo
    pinMode(12, OUTPUT);
    //Verde
    pinMode(13, OUTPUT);
    //Buzzers
    pinMode(BUZZER_PIN_1, OUTPUT);
    pinMode(BUZZER_PIN_2, OUTPUT);
  }

/********************************** BUZZERS ***************************************/
  //Toca um alarme
  void alarme() {

    for (int i = 0; i < 10; i++) {
      tone(BUZZER_PIN_1, 262, 200);  //Pino, frequencia, tempo
      tone(BUZZER_PIN_2, 262, 200);
      delay(500);
      tone(BUZZER_PIN_1, 294, 200);
      tone(BUZZER_PIN_2, 294, 200);
    }
    //Para o som
    noTone(BUZZER_PIN_1);
    noTone(BUZZER_PIN_2);
  }
/********************************** LEDS ***************************************/
  // Liga os 3 Leds de alguma cor
  void liga_led(char c) {

    //Vermelho
    if (c == 'R') digitalWrite(11, HIGH);
    //Verde
    if (c == 'G') digitalWrite(12, HIGH);
    //Amarelo
    if (c == 'B') digitalWrite(13, HIGH);

  }

  // Liga os 3 Leds de alguma cor
  void desliga_led(char c) {

    //Vermelho
    if (c == 'R') digitalWrite(11, LOW);
    //Verde
    if (c == 'G') digitalWrite(12, LOW);
    //Amarelo
    if (c == 'B') digitalWrite(13, LOW);
      
  }
};
#endif