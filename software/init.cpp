#include "init.h"
#include "sensor.h"
void inicializar(){
  Serial.begin(115200);
  Wire.begin();
  Sensores sensores(400, 390, A0, A1, A2);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);
  if(!mpu.init()){
    Serial.println("MPU9250 does not respond");
  }
  else{
    Serial.println("MPU9250 is connected");
  }
  if(!mpu.initMagnetometer()){
    Serial.println("Magnetometer does not respond");
  }
  else{
    Serial.println("Magnetometer is connected");
  }
  mpu.setMagOpMode(AK8963_CONT_MODE_100HZ);
  delay(200);
  Serial.println("Position you MPU9250 flat and don't move it - calibrating...");
  delay(1000);
  mpu.autoOffsets();
  Serial.println("Done!");
  //mpu.setGyrOffsets(45.0, 145.0, -105.0);
  mpu.enableGyrDLPF();
  //mpu.disableGyrDLPF(MPU9250_BW_WO_DLPF_8800); // bandwidth without DLPF
  mpu.setGyrDLPF(MPU9250_DLPF_6);
  mpu.setSampleRateDivider(99);
  mpu.setGyrRange(MPU9250_GYRO_RANGE_250);
  //mpu.sleep(true);
  //mpu.enableGyrStandby(true);
  //mpu.enableGyrAxes(MPU9250_ENABLE_000);
  setpoint = mpu.getMagValues().x; //Guarda la direccion inicial a la cual el robot apunta
}
