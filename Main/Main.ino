
//    _____ ____  __  __  ____    _____ _____ __  __ _____ _   _ _    _ _____              ______ ____  _   _ _______ ______
//   / ____/ __ \|  \/  |/ __ \  |  __ \_   _|  \/  |_   _| \ | | |  | |_   _|     /\     |  ____/ __ \| \ | |__   __|  ____|
//  | |   | |  | | \  / | |  | | | |  | || | | \  / | | | |  \| | |  | | | |      /  \    | |__ | |  | |  \| |  | |  | |__
//  | |   | |  | | |\/| | |  | | | |  | || | | |\/| | | | | . ` | |  | | | |     / /\ \   |  __|| |  | | . ` |  | |  |  __|
//  | |___| |__| | |  | | |__| | | |__| || |_| |  | |_| |_| |\  | |__| |_| |_   / ____ \  | |   | |__| | |\  |  | |  | |____
//   \_____\____/|_|  |_|\____/  |_____/_____|_|  |_|_____|_| \_|\____/|_____| /_/    \_\ |_|    \____/|_| \_|  |_|  |______|


#include "Sensores.hpp"
#include "Operacional.hpp"
#include "Comunicacao.hpp"

Sensores sensor;
Operacional op;

int gas;
int humidade;
int calor;

void setup() {
  Serial.begin(9600);
  op.setup();
  sensor.setup();
}

void loop() {

  //Realiza leituras
  gas = sensor.ler_gas();
  delay(200);

  //Perigo
  if (gas > 450) {
    op.liga_led('R');
    op.desliga_led('G');
    op.desliga_led('Y');
    op.buzzer();       //Toca alarme
    delay(2000);
    op.tp_servo(90);  //Fecha Gas
    op.buzzer();       //Toca alarme
    delay(3000);
  }
  //Alerta
  else if (gas > 150) {
    op.liga_led('Y');
    op.desliga_led('G');
    op.desliga_led('R');
  }
  //Seguro
  else {
    op.tp_servo(0);  //Fecha Gas
    op.liga_led('G');
    op.desliga_led('R');
    op.desliga_led('Y');
  }
}
