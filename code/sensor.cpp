#include "Arduino.h"
#include "sensor.h"
Sensores::Sensores(int escala, int valorDeteccion, int pinIzq, int pinCentro, int pinDer){
  this->sensorFrente = 0;
  this->sensorDer = 0;
  this->sensorIzq = 0;
  this->valorDeteccion = valorDeteccion;
  this->escala = escala;
  this->pinIzq = pinIzq;
  this->pinCentro = pinCentro;
  this->pinDer = pinDer;
}
boolean Sensores::detectarIzq(){
  int datoRegistrado = map(analogRead(this->pinIzq), 0, 1007, 0, this->escala);
  if(datoRegistrado < this->valorDeteccion){
    return true;
  }
  return false;
}
boolean Sensores::detectarFrente(){
  int datoRegistrado = map(analogRead(this->pinCentro), 0, 1007, 0, this->escala);
  if(datoRegistrado < this->valorDeteccion){
    return true;
  }
  return false;
}
boolean Sensores::detectarDer(){
  int datoRegistrado = map(analogRead(this->pinDer), 0, 1007, 0, this->escala);
  if(datoRegistrado < this->valorDeteccion){
    return true;
  }
  return false;
}
