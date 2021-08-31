#include "compassDriver.h"



/**
 * Constructor.
 * Create a software abstraction of an e-compass.
 *
 * @param id the unique EventModel id of this component. Defaults to: MICROBIT_ID_COMPASS
 * @param coordinateSpace the orientation of the sensor. Defaults to: SIMPLE_CARTESIAN
 *
 */
MicroBitCompassDriver::MicroBitCompassDriver(CoordinateSpace &cspace, uint16_t id) : MicroBitCompass(id),  calibration(), sample(), sampleENU(), coordinateSpace(cspace)
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
MicroBitCompassDriver::MicroBitCompassDriver(MicroBitAccelerometer &accel, CoordinateSpace &cspace, uint16_t id) : MicroBitCompass(id),  calibration(), sample(), sampleENU(), coordinateSpace(cspace)
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