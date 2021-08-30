#include "pxtcore.h"
// #include "MicroBitCompass.h"
using namespace MicroBit;

/**
 * Assume the Compass has callibration data and set it as callibrated
 *
 */
void assumeCalibrated()
{
    // status |= MICROBIT_COMPASS_STATUS_CALIBRATED;
    status |= 0x02;
}