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
void MicroBitCompassDriver::init(uint16_t id)
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
MicroBitCompass& MicroBitCompass::autoDetect(MicroBitI2C &i2c)
{
    if (MicroBitCompass::detectedCompass == NULL)
    {
        if(BMX055Magnetometer::isDetected(i2c)) {
            // the Calliope mini coordinate space is rotated by 90 degrees and not upside down as micro:bit
            CoordinateSpace &coordinateSpace = *(new CoordinateSpace(SIMPLE_CARTESIAN, false, COORDINATE_SPACE_ROTATED_180));
            MicroBitPin int3(MICROBIT_ID_IO_INT3, p23, PIN_CAPABILITY_STANDARD);
            MicroBitCompass::detectedCompass = new BMX055MagnetometerDriver(i2c, int3, coordinateSpace);
        } else
        {
            CoordinateSpace &coordinateSpace = *(new CoordinateSpace(SIMPLE_CARTESIAN, true, COORDINATE_SPACE_ROTATED_0));
            MicroBitCompass *unavailable = new MicroBitCompass(coordinateSpace, MICROBIT_ID_COMPASS);
            MicroBitCompass::detectedCompass = unavailable;
        }
    }

    // If an accelerometer has been discovered, enable tilt compensation on the e-compass.
    if (MicroBitAccelerometer::detectedAccelerometer)
        MicroBitCompass::detectedCompass->setAccelerometer(*MicroBitAccelerometer::detectedAccelerometer);

    return *MicroBitCompass::detectedCompass;
}
