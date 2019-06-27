# include "Angulo.h"

Angulo::Angulo()
{
    pino_giroscopio_SLC = A4;
    pino_giroscopio_SDA = A5;
}

void Angulo::incializarAngulo()
{
    
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin();
    TWBR = 24; // 400kHz I2C clock (200kHz if CPU is 8MHz)
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
    Fastwire::setup(400, true);
    #endif

    mpu.initialize();
    devStatus = mpu.dmpInitialize();
    mpu.setXAccelOffset(-4043);
    mpu.setYAccelOffset(-1792);
    mpu.setZAccelOffset(3717);
    mpu.setXGyroOffset(68);
    mpu.setYGyroOffset(-25);
    mpu.setZGyroOffset(13);
    
    // make sure it worked (returns 0 if so)
    if (devStatus == 0)
    {
        // turn on the DMP, now that it's ready
        Serial.println(F("Enabling DMP"));
        mpu.setDMPEnabled(true);

        // enable Arduino interrupt detection
        Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)"));
        mpuIntStatus = mpu.getIntStatus();

        // get expected DMP packet size for later comparison
        packetSize = mpu.dmpGetFIFOPacketSize();
    }
    else
    {
        // ERROR!
        // 1 = initial memory load failed, 2 = DMP configuration updates failed (if it's going to break, usually the code will be 1)
        Serial.print(F("DMP Initialization failed code = "));
        Serial.println(devStatus);
    }

}

float Angulo::retornarAngulo()
{
           
    // Get INT_STATUS byte
    mpuIntStatus = mpu.getIntStatus();

    // get current FIFO count
    fifoCount = mpu.getFIFOCount();

    // check for overflow (this should never happen unless our code is too inefficient)
    if ((mpuIntStatus & 0x10) || fifoCount == 1024)
    {
        // reset so we can continue cleanly
        mpu.resetFIFO();
        Serial.println(F("FIFO overflow!"));
        return;
    }

    if (mpuIntStatus & 0x02)  // otherwise continue processing
    {
        // check for correct available data length
        if (fifoCount < packetSize)
        return; //  fifoCount = mpu.getFIFOCount();

        // read a packet from FIFO
        mpu.getFIFOBytes(fifoBuffer, packetSize);

        // track FIFO count here in case there is > 1 packet available
        fifoCount -= packetSize;

        // flush buffer to prevent overflow
        mpu.resetFIFO();

        // display Euler angles in degrees
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
        mpuPitch = ypr[PITCH] * 180 / M_PI;
        mpuRoll = ypr[ROLL] * 180 / M_PI;
        mpuYaw  = ypr[YAW] * 180 / M_PI;

        // flush buffer to prevent overflow
        mpu.resetFIFO();

        // flush buffer to prevent overflow
        mpu.resetFIFO();
        Serial.print(mpuPitch);
        Serial.print(" ");
        Serial.print(mpuRoll);
        Serial.print(" ");
        Serial.println(mpuYaw);
        delay(100);
        // flush buffer to prevent overflow
        mpu.resetFIFO();

    }
}