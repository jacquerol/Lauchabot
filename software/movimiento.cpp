#include "movimiento.h"
MPU9250_WE mpu = MPU9250_WE(MPU9250_ADDR);

int distanciaEntreCelda = 14.6;

int AIN1 = 8 ; int AIN2 = 7;
int BIN1 = 9; int BIN2 = 10;
int PWMA = 6; int PWMB = 11;
int STBY = 12;

int setpoint = 0;
int leftSpeed = 0; int rightSpeed = 0;
int giro = 0;
boolean paredEncontrada = false;

void avanzarIzq(int velocity){
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, velocity);
}
void retrocederIzq(int velocity){
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, velocity);
}
void avanzarDer(int velocity){
  digitalWrite(STBY, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, velocity);
}
void retrocederDer(int velocity){
  digitalWrite(STBY, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, velocity);
}
void detener(){
  digitalWrite(STBY, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
  delay(500);
}


void girar180(){
  xyzFloat gyr;
  float suma_giro = 0;
  while(abs(suma_giro) < 90){
    gyr = mpu.getGyrValues();
    avanzarIzq(30);
    retrocederDer(29.7);
    suma_giro += abs(gyr.x);
    Serial.println(suma_giro);
    delay(100);
  }
  detener();
}

void girarDer(int veces){
  float suma_giro = 0; uint32_t prev_ms;
  float gradosPorMilisegundo = 0; long dt;
  for(int i=0;i<veces;i++){
    prev_ms = millis();
    while(suma_giro < 90){
      dt = millis() - prev_ms;
      if(millis() > prev_ms + 25){
        dt = millis() - prev_ms;
        Serial.print(prev_ms - millis());
        Serial.print(" ");
        Serial.println(suma_giro);
        suma_giro += gradosPorMilisegundo;
        gradosPorMilisegundo = ((mpu.getGyrValues().x)*dt/1000);
        prev_ms = millis();
    }
    avanzarDer(30);
    retrocederIzq(30);
    
  }
  detener();
  }
}

void avanzar(int cm, float factor){
  int potenciaDer = 30; int potenciaIzq = 30;
  int desviacion = 0;
  for(int i=0;i<cm*10;i++){
    desviacion += mpu.getGyrValues().x;
    if(desviacion > 0 and potenciaIzq > 0 and potenciaDer < 30){
      potenciaIzq -= factor;
      potenciaDer += factor;
    }
    else if(desviacion < 0 and potenciaIzq < 30 and potenciaDer > 0){
      potenciaIzq += factor;
      potenciaDer -= factor;
    }
    avanzarIzq(potenciaIzq); avanzarDer(potenciaDer);
    
    delay(26);
  }
  detener();
}
void retroceder(int cm, float factor){
  int potenciaDer = 30; int potenciaIzq = 30;
  int desviacion = 0;
  for(int i=0;i<cm*10;i++){
    desviacion += mpu.getGyrValues().x;
    if(desviacion > 0 and potenciaIzq > 0 and potenciaDer < 30){
      potenciaIzq -= factor;
      potenciaDer += factor;
    }
    else if(desviacion < 0 and potenciaIzq < 30 and potenciaDer > 0){
      potenciaIzq += factor;
      potenciaDer -= factor;
    }
    retrocederIzq(potenciaIzq); retrocederDer(potenciaDer);
    delay(26);
  }
  detener();
}
/*
void girarDer(int veces){
  float suma_giro = 0;
  xyzFloat gyr;
  for(int i=0;i<veces;i++){
    while(suma_giro < 90){
    gyr = mpu.getGyrValues();
    avanzarDer(30);
    retrocederIzq(30);
    suma_giro += gyr.x;
    Serial.println(suma_giro);
    delay(27.5);
  }
  detener();
  }
}
*/

void girarIzq(int veces){
  float suma_giro = 0;
  xyzFloat gyr;
  for(int i=0;i<veces;i++){
    while(suma_giro > 90){
    gyr = mpu.getGyrValues();
    retrocederDer(30);
    avanzarIzq(30);
    suma_giro += gyr.x;
    Serial.println(suma_giro);
    delay(27.5);
  }
  detener();
  }
}


/*
void alinearSetpoint(float idealValue){
  float actualValue = myMPU9250.getMagValues().x;
  Serial.print(idealValue);
  Serial.print(" - ");
  Serial.println(actualValue);
  while(actualValue != idealValue){
    
    if(actualValue > idealValue+1){
      backwardsR(15);
      forwardL(15);
    }
    
    
    else if(actualValue < idealValue-1){
      forwardR(30);
      backwardsL(30);
    }
    actualValue = myMPU9250.getMagValues().x;
    delay(10);
  }
  detener();
  
}
*/
