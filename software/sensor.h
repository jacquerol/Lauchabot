#ifndef SENSOR_H
#define SENSOR_H
#include "Arduino.h"
class Sensores {
  public:
    Sensores(int escala=200, int valorDeteccion=100, int pinIzq = A0, int pinCentro = A1, int pinDer = A2);
    boolean detectarIzq();
    boolean detectarDer();
    boolean detectarFrente();
  private:
    int sensorFrente; int sensorDer; int sensorIzq; 
    int escala; int valorDeteccion;
    int pinIzq; int pinCentro; int pinDer;
};
#endif
