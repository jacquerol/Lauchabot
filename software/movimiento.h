#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H
#include <Arduino.h>
#include <MPU9250_WE.h>
#include <Wire.h>

#define MPU9250_ADDR 0x68
extern MPU9250_WE mpu;
extern int distanciaEntreCelda;
extern int AIN1; extern int AIN2;
extern int BIN1; extern int BIN2;
extern int PWMA; extern int PWMB;
extern int STBY;

extern int setpoint;
extern int leftSpeed; extern int rightSpeed;
extern int giro;
extern boolean paredEncontrada;

void avanzar(int cm = distanciaEntreCelda, float factor = 1);
void retroceder(int cm = distanciaEntreCelda, float factor = 1);
void girarDer(int veces = 1);
void girarIzq(int veces = 1);
void detener();
void avanzarDer(int velocidad);
void avanzarIzq(int velocidad);
void retrocederDer(int velocidad);
void retrocederIzq(int velocidad);
void alinearSetpoint(int valorIdeal);

#endif
