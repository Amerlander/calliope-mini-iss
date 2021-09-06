#include "compassDriver.h"
#include "ErrorNo.h"
#include "MicroBitEvent.h"
#include "MicroBitCompat.h"
#include "MicroBitFiber.h"
#include "MicroBitDevice.h"

#include "MAG3110.h"
#include "LSM303Magnetometer.h"
#include "FXOS8700.h"
#include "BMX055Magnetometer.h"


/**
 * Constructor.
 * Create a software abstraction of an e-compass.
 *
 * @param id the unique EventModel id of this component. Defaults to: MICROBIT_ID_COMPASS
 * @param coordinateSpace the orientation of the sensor. Defaults to: SIMPLE_CARTESIAN
 *
 */
MicroBitCompassDriver::MicroBitCompassDriver(CoordinateSpace &cspace, uint16_t id) : MicroBitCompass(cspace, id)
{
}

/**
 * Constructor.
 * Create a software abstraction of an e-compass.
 *
 * @param id the unique EventModel id of this component. Defaults to: MICROBIT_ID_COMPASS
 * @param accel the accelerometer to use for tilt compensation
 * @param coordinateSpace the orientation of the sensor. Defaults to: SIMPLE_CARTESIAN
 *
 */
MicroBitCompassDriver::MicroBitCompassDriver(MicroBitAccelerometer &accel, CoordinateSpace &cspace, uint16_t id) : MicroBitCompass(accel, cspace, id)
{
}


/**
 * Internal helper used to de-duplicate code in the constructors
 * @param coordinateSpace the orientation of the sensor. Defaults to: SIMPLE_CARTESIAN
 * @param id the unique EventModel id of this component. Defaults to: MICROBIT_ID_COMPASS
 *
 */
void MicroBitCompassDriverDriver::init(uint16_t id)
{
    // Store our identifiers.
    this->id = id;
    this->status = 0;

    // Set a default rate of 10Hz.
    this->samplePeriod = 100;
    this->configure();

    // Assume that we have calibration information.
    status |= MICROBIT_COMPASS_STATUS_CALIBRATED;

    // Indicate that we're up and running.
    status |= MICROBIT_COMPONENT_RUNNING;
}



/**
 * Device autodetection. Scans the given I2C bus for supported accelerometer devices.
 * if found, constructs an appropriate driver and returns it.
 *
 * @param i2c the bus to scan. 
 * @param id the unique EventModel id of this component. Defaults to: MICROBIT_ID_ACCELEROMETER
 *
 */
MicroBitCompassDriver& MicroBitCompassDriver::autoDetect(MicroBitI2C &i2c)
{
    if (MicroBitCompassDriver::detectedCompass == NULL)
    {
#ifdef MICROBIT_DEVICE_ENABLED_MMA3110

        // Now, probe for connected peripherals, if none have already been found.
        if (MAG3110::isDetected(i2c))  {
            CoordinateSpace &coordinateSpace = *(new CoordinateSpace(SIMPLE_CARTESIAN, true, COORDINATE_SPACE_ROTATED_0));
            MicroBitPin int2(MICROBIT_ID_IO_INT2, P0_29, PIN_CAPABILITY_STANDARD);
            MicroBitCompassDriver::detectedCompass = new MAG3110(i2c, int2, coordinateSpace);
        } else
#endif
#ifdef MICROBIT_DEVICE_ENABLED_LSM303
        if (LSM303Magnetometer::isDetected(i2c)) {
            CoordinateSpace &coordinateSpace = *(new CoordinateSpace(SIMPLE_CARTESIAN, true, COORDINATE_SPACE_ROTATED_0));
            MicroBitPin int2(MICROBIT_ID_IO_INT2, P0_29, PIN_CAPABILITY_STANDARD);
            MicroBitCompassDriver::detectedCompass = new LSM303Magnetometer(i2c, int2, coordinateSpace);
        } else
#endif
#ifdef MICROBIT_DEVICE_ENABLED_FXOS8700
        if (FXOS8700::isDetected(i2c)) {
            CoordinateSpace &coordinateSpace = *(new CoordinateSpace(SIMPLE_CARTESIAN, true, COORDINATE_SPACE_ROTATED_0));
            MicroBitPin int3(MICROBIT_ID_IO_INT3, P0_27, PIN_CAPABILITY_STANDARD);
            FXOS8700 *fxos =  new FXOS8700(i2c, int3, coordinateSpace);
            MicroBitAccelerometer::detectedAccelerometer = fxos;
            MicroBitCompassDriver::detectedCompass = fxos;
        }

        // Insert this case to support FXOS on the microbit1.5-SN
        //else if (FXOS8700::isDetected(i2c, 0x3A))
        //{
        //    CoordinateSpace &coordinateSpace = *(new CoordinateSpace(SIMPLE_CARTESIAN, true, COORDINATE_SPACE_ROTATED_0));
        //    MicroBitPin int3(MICROBIT_ID_IO_INT3, P0_27, PIN_CAPABILITY_STANDARD);
        //    FXOS8700 *fxos =  new FXOS8700(i2c, int3, coordinateSpace, 0x3A);
        //    MicroBitAccelerometer::detectedAccelerometer = fxos;
        //    MicroBitCompassDriver::detectedCompass = fxos;
        //}

        else
#endif
#ifdef MICROBIT_DEVICE_ENABLED_BMX055
        if(BMX055Magnetometer::isDetected(i2c)) {
            // the Calliope mini coordinate space is rotated by 90 degrees and not upside down as micro:bit
            CoordinateSpace &coordinateSpace = *(new CoordinateSpace(SIMPLE_CARTESIAN, false, COORDINATE_SPACE_ROTATED_180));
            MicroBitPin int3(MICROBIT_ID_IO_INT3, p23, PIN_CAPABILITY_STANDARD);
            MicroBitCompassDriver::detectedCompass = new BMX055MagnetometerDriver(i2c, int3, coordinateSpace);
        } else
#endif
        {
            CoordinateSpace &coordinateSpace = *(new CoordinateSpace(SIMPLE_CARTESIAN, true, COORDINATE_SPACE_ROTATED_0));
            MicroBitCompassDriver *unavailable = new MicroBitCompassDriver(coordinateSpace, MICROBIT_ID_COMPASS);
            MicroBitCompassDriver::detectedCompass = unavailable;
        }
    }

    // If an accelerometer has been discovered, enable tilt compensation on the e-compass.
    if (MicroBitAccelerometer::detectedAccelerometer)
        MicroBitCompassDriver::detectedCompass->setAccelerometer(*MicroBitAccelerometer::detectedAccelerometer);

    return *MicroBitCompassDriver::detectedCompass;
}
