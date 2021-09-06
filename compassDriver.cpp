#include "compassDriver.h"

#include "MicroBitCompass.h"
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
MicroBitCompassDriver::MicroBitCompassDriver(uint16_t id)
{
    init(id);
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
