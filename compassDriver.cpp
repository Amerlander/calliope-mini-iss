#include "MicroBitCompass.h"

using namespace  MicroBitCompass;

/**
 * Assume the Compass has callibration data and set it to callibrated
 *
 */
void assumeCalibration()
{
    status |= MICROBIT_COMPASS_STATUS_CALIBRATED;
}