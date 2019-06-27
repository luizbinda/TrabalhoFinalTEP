#ifndef Angulo_h
#define Angulo_h

#include <Arduino.h>
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include "Wire.h"

class Angulo : public MPU6050
{
private:
    float mpuPitch = 0;
    float mpuRoll = 0;
    float mpuYaw = 0;
    // MPU control/status vars
    uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
    uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
    uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
    uint16_t fifoCount;     // count of all bytes currently in FIFO
    uint8_t fifoBuffer[64]; // FIFO storage buffer

    // orientation/motion vars
    Quaternion q;           // [w, x, y, z]         quaternion container
    VectorInt16 aa;         // [x, y, z]            accel sensor measurements
    VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
    VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
    VectorFloat gravity;    // [x, y, z]            gravity vector
    float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

    // relative ypr[x] usage based on sensor orientation when mounted, e.g. ypr[PITCH]
    #define PITCH   1     // defines the position within ypr[x] variable for PITCH; may vary due to sensor orientation when mounted
    #define ROLL  2     // defines the position within ypr[x] variable for ROLL; may vary due to sensor orientation when mounted
    #define YAW   0     // defines the position within ypr[x] variable for YAW; may vary due to sensor orientation when mounted

    uint8_t pino_giroscopio_SLC;
    uint8_t pino_giroscopio_SDA;
    
public:
    Angulo();
    float retornarAngulo();
    void incializarAngulo();
};


Angulo::Angulo()
{
    pino_giroscopio_SLC = A4;
    pino_giroscopio_SDA = A5;
}

void Angulo::incializarAngulo()
{
    pino_giroscopio_SLC = A4;
    pino_giroscopio_SDA = A5;

    MPU6050 mpu;    
    mpu.initialize();

    devStatus = mpu.dmpInitialize();

    mpu.setXAccelOffset(-4043);
    mpu.setYAccelOffset(-1792);
    mpu.setZAccelOffset(3717);
    mpu.setXGyroOffset(68);
    mpu.setYGyroOffset(-25);
    mpu.setZGyroOffset(13);

    mpu.setDMPEnabled(true);

    mpuIntStatus = mpu.getIntStatus();

    packetSize = mpu.dmpGetFIFOPacketSize();
}

float Angulo::retornarAngulo()
{
    MPU6050 mpu;
    mpuIntStatus = mpu.getIntStatus();
    
    fifoCount = mpu.getFIFOCount();

    if ((mpuIntStatus & 0x10) || fifoCount == 1024)
    {
        mpu.resetFIFO();
        return 200;
    }

    if (mpuIntStatus & 0x02)  // otherwise continue processing
    {
        if (fifoCount < packetSize)
        return; 

        mpu.getFIFOBytes(fifoBuffer, packetSize);

        fifoCount -= packetSize;

        mpu.resetFIFO();

        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
        mpuPitch = ypr[PITCH] * 180 / M_PI;
        mpuRoll = ypr[ROLL] * 180 / M_PI;
        mpuYaw  = ypr[YAW] * 180 / M_PI;

        mpu.resetFIFO();
        mpu.resetFIFO();
        return mpuYaw;
        delay(100);

        mpu.resetFIFO();

  }
}

#endif