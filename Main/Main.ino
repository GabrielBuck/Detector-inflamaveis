
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
  Serial.begin(250000);
  op.setup();
  sensor.setup();
}


void loop() {

  //Realiza leituras
  gas = sensor.ler_gas();
  calor = sensor.ler_temperatura();
  humidade = sensor.ler_humidade();

  //Perigo
  if (gas > 10) {
    op.move_servo(100);  //Fecha Gas
    op.alarme();         //Toca alarme
    op.liga_led('R');
    op.liga_led('Y');
    op.liga_led('G');

  }
  //Alerta
  else if (gas > 5) {
    op.desliga_led('R');
    op.liga_led('Y');
    op.liga_led('G');
  }
  //Seguro
  else {
    op.desliga_led('R');
    op.desliga_led('Y');
    op.liga_led('G');
  }
}
