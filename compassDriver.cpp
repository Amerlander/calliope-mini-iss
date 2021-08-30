#include "MicroBitCompassDriver.h"

/**
 * Assume the Compass has callibration data and set it as callibrated
 *
 */
void MicroBitCompassDriver::assumeCalibrated()
{
    // status |= MICROBIT_COMPASS_STATUS_CALIBRATED;
    status |= 0x02;
}