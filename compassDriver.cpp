#include "compassDriver.h"

/**
 * Constructor.
 * Create a software abstraction of an e-compass.
 *
 * @param id the unique EventModel id of this component. Defaults to: MICROBIT_ID_COMPASS
 * @param accel the accelerometer to use for tilt compensation
 * @param coordinateSpace the orientation of the sensor. Defaults to: SIMPLE_CARTESIAN
 *
 */
MicroBitCompassDriver::MicroBitCompassDriver(MicroBitAccelerometer &accel, CoordinateSpace &cspace, uint16_t id) :  calibration(), sample(), sampleENU(), coordinateSpace(cspace)
{
    accelerometer = &accel;
    // Store our identifiers.
    this->id = id;
    this->status = 0;
}

/**
 * Assume the Compass has callibration data and set it as callibrated
 *
 */
void MicroBitCompassDriver::assumeCalibrated()
{
    // status |= MICROBIT_COMPASS_STATUS_CALIBRATED;
    status |= 0x02;
}