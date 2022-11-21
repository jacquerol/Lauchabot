 #include <MPU9250_WE.h>
#include <Wire.h>
#include "movimiento.h"
#include "init.h"
#include "sensor.h"
int lectura = 0; int escala = 400;
void setup() {
  inicializar();
  /*
  for(int i=0;i<4;i++){
    avanzar();
    girarDer();
  }
  */
  
}

void loop() {
  /*
  if(Serial.available() > 0){
    escala = Serial.parseInt();
  }
  
  lectura = map(analogRead(A0), 0, 1007, 0, escala);
  Serial.println(lectura);
  //Serial.println(sensores.detectarIzq());
  if(lectura < 100){
    girarDer();
  }
  else if(lectura < 390 ){
    retroceder(5, 0.5);
    avanzar(5, 0.5);
  }
  */
  girarDer();  
  
}
