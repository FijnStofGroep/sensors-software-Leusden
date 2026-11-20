/*
 * @file Sensirion_Interface.h
 *
 * Written by R.Dieperink
 * 
 * Date: 2026-10-13
 *
 * Version: 1.0.1
 *
 * Copyright (C) 2026 ~ 2027, Fijnstofgroep, Leusden, The Netherlands
 * All rights reserved.
 *
 *
 */

#ifndef SENSIRION_INTERFACE_H
#define SENSIRION_INTERFACE_H

//------------------------------------------------------------------------------------------------------------------------------------------
#pragma region "Includes, Defines and Enums"

#include <SensirionI2CSen5x.h> // SEN5X sensor library for SEN5X sensor (PM, RH & T, VOC, NOx)
#include <SensirionI2cSen65.h> // SEN65 sensor library for SEN65 sensor (PM, RH & T, VOC, NOx), (new: 10-10-2026)

//"C++ extern "C" block for C compatibility"
#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char uchar;

#ifdef __cplusplus
}
#endif

namespace SENSIRION
{// to solve previous declaration enum of 'NONE' and 'Count' in the global namespace, we use a namespace SENSIRION.
    /// @brief Enum SensorType.
    enum sensirion_model
    {
        NONE = 0,
        SEN55 = 1,
        SEN65 = 2,

        Count               // always last => constant such as `sm_Count` the number of enum entries.
    };

    //  Get enum SENSIRION_NAME value name: sizeof(sensirion_model)
    String SENSIRION_NAME[sensirion_model::Count] = {"None", "SEN55", "SEN65"};
}

typedef SENSIRION::sensirion_model SENSIRION_MODEL;

#pragma endregion

//------------------------------------------------------------------------------------------------------------------------------------------
#pragma region "Base => Interface ISensirionSensor"

// ================= Interface Definition =================
// An interface in C++ is a class with only pure abstract/virtual functions.
class ISensirionSensor
{
public:
    /// @brief Virtual destructor for safe polymorphic deletion.
    ///        means “Use the compiler-generated destructor, but make it virtual so polymorphic deletion works safely.”
    virtual ~ISensirionSensor() = default;

    // Local Interface equivalent pure abstract class.
    virtual SENSIRION_MODEL getModelType() = 0;
    virtual String getModelName() = 0;

    /// @brief Initialize the sensor.
    /// @param wire The I2C bus instance.
    virtual void begin(TwoWire &) = 0;

    virtual int16_t getProductName(unsigned char *productName, uint16_t productNameSize) = 0;
    virtual int16_t getSerialNumber(uchar *serialNumber, uint16_t serialNumberSize) = 0;
    virtual uint16_t getVersion(uint8_t &firmwareMajor,
                                uint8_t &firmwareMinor,
                                bool &firmwareDebug,
                                uint8_t &hardwareMajor,
                                uint8_t &hardwareMinor,
                                uint8_t &protocolMajor,
                                uint8_t &protocolMinor) = 0;

    virtual uint16_t getTemperatureOffsetSimple(float &tempOffset) = 0;
    virtual uint16_t setTemperatureOffsetSimple(float tempOffset) = 0;
    virtual uint16_t setFanAutoCleaningInterval(uint32_t interval) = 0;
    virtual uint16_t startFanCleaning() = 0;
    virtual uint16_t setWarmStartParameter(uint16_t warmStart) = 0;

    virtual int16_t deviceReset(void) = 0;
    virtual int16_t startMeasurement(void) = 0;
    virtual int16_t stopMeasurement(void) = 0;

    virtual uint16_t readMeasuredPmValues(float &massConcentrationPm1p0, float &massConcentrationPm2p5,
                                          float &massConcentrationPm4p0, float &massConcentrationPm10p0,
                                          float &numberConcentrationPm0p5, float &numberConcentrationPm1p0,
                                          float &numberConcentrationPm2p5, float &numberConcentrationPm4p0,
                                          float &numberConcentrationPm10p0, float &typicalParticleSize) = 0;

    /// @brief Read measured values from the sensor.
    /// @param massConcentrationPm10p0
    /// @param humidity
    /// @param temperature
    /// @param vocIndex
    /// @param noxIndex
    /// @return
    virtual int16_t readMeasuredValues(float &massConcentrationPm1p0,
                                       float &massConcentrationPm2p5,
                                       float &massConcentrationPm4p0,
                                       float &massConcentrationPm10p0,
                                       float &humidity,
                                       float &temperature,
                                       float &vocIndex,
                                       float &noxIndex) = 0;
};
#pragma endregion

//------------------------------------------------------------------------------------------------------------------------------------------

#pragma region "SensirionI2cSen5xAdapter"
/// @brief Adapter class for handling Sensirion SEN5X I2C sensor.
//         SEN5X sensor library for SEN5X sensor (PM, RH & T, VOC, NOx)
class SensirionI2cSen5xAdapter : public SensirionI2CSen5x, public ISensirionSensor
{
private:
    // String Name;

public:
    /// @brief default Constructor:
    SensirionI2cSen5xAdapter() : SensirionI2CSen5x()
    {
    }

    /// @brief Destructor for the derived class.
    ///     by delete m_sensirionSensor;   --> First calls Derived's destructor, then Base's destructor.
    virtual ~SensirionI2cSen5xAdapter() = default; // Defaulted virtual destructor.

    // Implement interface methods:

    /// @brief 
    /// @return 
    SENSIRION_MODEL getModelType() override { return SENSIRION_MODEL::SEN55; }
    String getModelName() override { return SENSIRION::SENSIRION_NAME[SENSIRION_MODEL::SEN55]; }

    /// @brief
    /// @param wire
    void begin(TwoWire &wire) override
    {
        SensirionI2CSen5x::begin(wire);
    }

    /// @brief
    /// @param serialNumber
    /// @param serialNumberSize
    /// @return
    int16_t getSerialNumber(uchar serialNumber[], uint16_t serialNumberSize) override
    {
        return SensirionI2CSen5x::getSerialNumber(serialNumber, serialNumberSize);
    }

    /// @brief 
    /// @param tempOffset 
    /// @return 
    uint16_t getTemperatureOffsetSimple(float &tempOffset) override
    {
        return SensirionI2CSen5x::getTemperatureOffsetSimple(tempOffset);
    }

    /// @brief 
    /// @param tempOffset 
    /// @return 
    uint16_t setTemperatureOffsetSimple(float tempOffset) override
    {
        return SensirionI2CSen5x::setTemperatureOffsetSimple(tempOffset);
    }

    /// @brief 
    /// @param interval 
    /// @return 
    uint16_t setFanAutoCleaningInterval(uint32_t interval) override
    {
        return SensirionI2CSen5x::setFanAutoCleaningInterval(interval);
    }

    /// @brief 
    /// @return 
    uint16_t startFanCleaning() override
    {
        return SensirionI2CSen5x::startFanCleaning();
    }

    /// @brief 
    /// @param  
    /// @return 
    int16_t deviceReset(void) override
    {
        return SensirionI2CSen5x::deviceReset();
    }

    /// @brief  override function for getting product name.
    /// @param productName 
    /// @param productNameSize     
    /// @return 
    int16_t getProductName(uchar *productName, uint16_t productNameSize) override
    {
        return SensirionI2CSen5x::getProductName(productName, productNameSize);
    }

    /// @brief override function for starting measurement.
    /// @param  
    /// @return 
    int16_t startMeasurement(void) override
    {
        return SensirionI2CSen5x::startMeasurement();
    }

    /// @brief override function for stopping measurement.
    /// @param  
    /// @return 
    int16_t stopMeasurement(void) override
    {
        return SensirionI2CSen5x::stopMeasurement();
    }

    /// @brief override function for setting warm start parameter.
    /// @param warmStart 
    /// @return 
    uint16_t setWarmStartParameter(uint16_t warmStart) override
    {
        return SensirionI2CSen5x::setWarmStartParameter(warmStart);
    }

    /// @brief
    /// @param firmwareMajor
    /// @param firmwareMinor
    /// @param firmwareDebug
    /// @param hardwareMajor
    /// @param hardwareMinor
    /// @param protocolMajor
    /// @param protocolMinor
    /// @return
    uint16_t getVersion(uint8_t &firmwareMajor,
                        uint8_t &firmwareMinor,
                        bool &firmwareDebug,
                        uint8_t &hardwareMajor,
                        uint8_t &hardwareMinor,
                        uint8_t &protocolMajor,
                        uint8_t &protocolMinor) override
    {
        return SensirionI2CSen5x::getVersion(firmwareMajor,
                                             firmwareMinor,
                                             firmwareDebug,
                                             hardwareMajor,
                                             hardwareMinor,
                                             protocolMajor,
                                             protocolMinor);
    }

    /// @brief 
    /// @param massConcentrationPm1p0 
    /// @param massConcentrationPm2p5 
    /// @param massConcentrationPm4p0 
    /// @param massConcentrationPm10p0 
    /// @param numberConcentrationPm0p5 
    /// @param numberConcentrationPm1p0 
    /// @param numberConcentrationPm2p5 
    /// @param numberConcentrationPm4p0 
    /// @param numberConcentrationPm10p0 
    /// @param typicalParticleSize 
    /// @return 
    uint16_t readMeasuredPmValues(float &massConcentrationPm1p0, float &massConcentrationPm2p5,
                                  float &massConcentrationPm4p0, float &massConcentrationPm10p0,
                                  float &numberConcentrationPm0p5, float &numberConcentrationPm1p0,
                                  float &numberConcentrationPm2p5, float &numberConcentrationPm4p0,
                                  float &numberConcentrationPm10p0, float &typicalParticleSize) override
    {
        return SensirionI2CSen5x::readMeasuredPmValues(massConcentrationPm1p0,
                                                       massConcentrationPm2p5,
                                                       massConcentrationPm4p0,
                                                       massConcentrationPm10p0,
                                                       numberConcentrationPm0p5,
                                                       numberConcentrationPm1p0,
                                                       numberConcentrationPm2p5,
                                                       numberConcentrationPm4p0,
                                                       numberConcentrationPm10p0,
                                                       typicalParticleSize);
    }

    /// @brief Pure override function for reading measured values.
    /// @param massConcentrationPm1p0
    /// @param massConcentrationPm2p5
    /// @param massConcentrationPm4p0
    /// @param massConcentrationPm10p0
    /// @param humidity
    /// @param temperature
    /// @param vocIndex
    /// @param noxIndex
    /// @return
    int16_t readMeasuredValues(float &massConcentrationPm1p0,
                               float &massConcentrationPm2p5,
                               float &massConcentrationPm4p0,
                               float &massConcentrationPm10p0,
                               float &humidity,
                               float &temperature,
                               float &vocIndex,
                               float &noxIndex) override
    {
        return SensirionI2CSen5x::readMeasuredValues(massConcentrationPm1p0,
                                                     massConcentrationPm2p5,
                                                     massConcentrationPm4p0,
                                                     massConcentrationPm10p0,
                                                     humidity,
                                                     temperature,
                                                     vocIndex,
                                                     noxIndex);
    }
};
#pragma endregion

//------------------------------------------------------------------------------------------------------------------------------------------

#pragma region "SensirionI2cSen65Adapter"
/// @brief Derived class for handling Sensirion SEN65 I2C sensor.
//         SEN65 sensor library for SEN65 sensor (PM, RH & T, VOC, NOx), (new: 9-10-2026)
class SensirionI2cSen65Adapter : public SensirionI2cSen65, public ISensirionSensor
{
private:
    // String Name;
    float tempOffset = 0.0f; // Temperature offset for simple temperature compensation.

public:
    /// @brief constructor
    SensirionI2cSen65Adapter() : SensirionI2cSen65()
    {
    }

    /// @brief Destructor for the derived class.
    ///     by delete m_sensirionSensor;  --> First calls Derived's destructor, then Base's destructor.
    virtual ~SensirionI2cSen65Adapter() {}; // Defaulted virtual destructor

    // Implement interface methods:

    /// @brief Gets the model type of the sensor.
    /// @return The sensor model type.
    SENSIRION_MODEL getModelType() override
    { 
        //int8_t productType[33] = {0};
        //int16_t ret = getProductType(productType, 32);        // ex. product types: SEN65:  '00085200'
        return SENSIRION_MODEL::SEN65; 
    }

    /// @brief 
    /// @return 
    String getModelName() override
    { 
        return SENSIRION::SENSIRION_NAME[SENSIRION_MODEL::SEN65]; 
    }

    /// @brief Initializes the SEN65 class with the provided I2C bus.
    /// @param i2cBus Arduino stream object to be used for communication.
    /// @param i2cAddress I2C address of the SEN65 sensor.
    void begin(TwoWire &wire) override
    {
        SensirionI2cSen65::begin(wire, SEN65_I2C_ADDR_6B);
    }

    /// @brief 
    /// @param productName 
    /// @param productNameSize 
    /// @return 
    int16_t getProductName(unsigned char *productName, uint16_t productNameSize) override
    {
        return SensirionI2cSen65::getProductName((int8_t *)productName, productNameSize);
    }

    /// @brief 
    /// @param serialNumber 
    /// @param serialNumberSize 
    /// @return 
    int16_t getSerialNumber(uchar *serialNumber, uint16_t serialNumberSize) override
    {
        return SensirionI2cSen65::getSerialNumber((int8_t *)serialNumber, serialNumberSize);
    }

    /// @brief 
    /// @param firmwareMajor 
    /// @param firmwareMinor 
    /// @param firmwareDebug 
    /// @param hardwareMajor 
    /// @param hardwareMinor 
    /// @param protocolMajor 
    /// @param protocolMinor 
    /// @return 
    uint16_t getVersion(uint8_t &firmwareMajor,
                        uint8_t &firmwareMinor,
                        bool &firmwareDebug,
                        uint8_t &hardwareMajor,
                        uint8_t &hardwareMinor,
                        uint8_t &protocolMajor,
                        uint8_t &protocolMinor) override
    {
        hardwareMajor = 2;
        hardwareMinor = 13;
        protocolMajor = 1;
        protocolMinor = 02;
        return (uint16_t)SensirionI2cSen65::getVersion(firmwareMajor, firmwareMinor);
    }

    /// @brief Resets the sensor.
    /// @param  
    /// @return 
    int16_t deviceReset(void) override
    {
        return SensirionI2cSen65::deviceReset();
    }

    /// @brief This command triggers fan cleaning. The fan is set to the maximum speed
    ///        for 10 seconds and then automatically stopped. Wait at least 10s after
    ///        this command before starting a measurement.
    /// @return error_code 0 on success, an error code otherwise.
    uint16_t startFanCleaning() override
    {
        return (int16_t)SensirionI2cSen65::startFanCleaning();
    }

    /// @brief Starts a continuous measurement. After starting the measurement, it takes
    ///        some time (~1.1s) until the first measurement results are available.
    /// @param
    /// @return
    int16_t startMeasurement(void) override
    {
        return SensirionI2cSen65::startContinuousMeasurement();
    }

    /// @brief Stops the measurement and returns to idle mode. After sending this
    ///  command, wait at least 1000 ms before starting a new measurement.
    /// @param
    /// @return
    int16_t stopMeasurement(void) override
    {
        return SensirionI2cSen65::stopMeasurement();
    }

    /// @brief Sets the temperature offset for simple temperature compensation.
    /// @param _tempOffset The temperature offset to set.
    /// @return The error code.
    uint16_t setTemperatureOffsetSimple(float _tempOffset) override
    {
        tempOffset = _tempOffset; // Store the temperature offset for later use.
        return (int16_t)SensirionI2cSen65::setTemperatureOffsetParameters(1, 10, (uint16_t)tempOffset, 0);
    }

    /// @brief Reads the measured PM values from the sensor.
    /// @param massConcentrationPm1p0 
    /// @param massConcentrationPm2p5 
    /// @param massConcentrationPm4p0 
    /// @param massConcentrationPm10p0 
    /// @param numberConcentrationPm0p5 
    /// @param numberConcentrationPm1p0 
    /// @param numberConcentrationPm2p5 
    /// @param numberConcentrationPm4p0 
    /// @param numberConcentrationPm10p0 
    /// @param typicalParticleSize 
    /// @return 
    uint16_t readMeasuredPmValues(float &massConcentrationPm1p0, float &massConcentrationPm2p5,
                                  float &massConcentrationPm4p0, float &massConcentrationPm10p0,
                                  float &numberConcentrationPm0p5, float &numberConcentrationPm1p0,
                                  float &numberConcentrationPm2p5, float &numberConcentrationPm4p0,
                                  float &numberConcentrationPm10p0, float &typicalParticleSize) override
    {
        typicalParticleSize = 0;
        float humidity, temperature, vocIndex, noxIndex;
        int16_t ret = SensirionI2cSen65::readMeasuredValues(massConcentrationPm1p0, massConcentrationPm2p5,
                                                            massConcentrationPm4p0, massConcentrationPm10p0,
                                                            humidity, temperature, vocIndex, noxIndex);

        ret += SensirionI2cSen65::readNumberConcentrationValues(numberConcentrationPm0p5, numberConcentrationPm1p0,
                                                                numberConcentrationPm2p5, numberConcentrationPm4p0,
                                                                numberConcentrationPm10p0);

        return (uint16_t)ret;
    }

    /// @brief Reads the measured values from the sensor.
    /// @param massConcentrationPm1p0 `
    /// @param massConcentrationPm2p5
    /// @param massConcentrationPm4p0
    /// @param massConcentrationPm10p0
    /// @param humidity
    /// @param temperature
    /// @param vocIndex
    /// @param noxIndex
    /// @return
    int16_t readMeasuredValues(float &massConcentrationPm1p0,
                               float &massConcentrationPm2p5,
                               float &massConcentrationPm4p0,
                               float &massConcentrationPm10p0,
                               float &humidity,
                               float &temperature,
                               float &vocIndex,
                               float &noxIndex) override
    {
        return SensirionI2cSen65::readMeasuredValues(massConcentrationPm1p0,
                                                     massConcentrationPm2p5,
                                                     massConcentrationPm4p0,
                                                     massConcentrationPm10p0,
                                                     humidity,
                                                     temperature,
                                                     vocIndex,
                                                     noxIndex);
    }

    //-------------------------- NOT implemented functions for SEN65 sensor --------------------------

    /// @brief Sets the temperature offset parameters for the SEN65 sensor.
    /// @param offset The temperature offset value.
    uint16_t getTemperatureOffsetSimple(float &_tempOffset) override
    {
        return _tempOffset = tempOffset;
    }

    /// @brief Sets the auto cleaning interval for the fan.
    /// @param interval The interval in seconds.
    /// @return The result of the operation.
    uint16_t setFanAutoCleaningInterval(uint32_t interval) override
    {
        // uint16_t fret = SensirionI2CSen65::startFanCleaning()
        return 0;
    }

    /// @brief Sets the warm start parameter for the SEN65 sensor.
    /// @param warmStart
    /// @return
    uint16_t setWarmStartParameter(uint16_t warmStart) override
    {
        return 0;
    }
};
#pragma endregion

#endif // SENSIRION_INTERFACE_H