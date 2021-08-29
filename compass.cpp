
#include "pxt.h"
using namespace pxt;

/**
 * 
 */
namespace input {

    /**
     * Obsolete, compass calibration is automatic.
     */
    //% help=input/calibrate-compass advanced=true
    //% blockId="input_compass_is_calibrated" block="is calibrated compass"
    //% weight=45
    int isCalibratedCompass() {
        return uBit.compass.isCalibrated();
    }

    /**
     * Obsolete, compass calibration is automatic.
     */
    //% help=input/calibrate-compass advanced=true
    //% blockId="input_compass_clear_calibration" block="clear calibration compass"
    //% weight=45
    void clearCalibrationCompass() {
        uBit.compass.clearCalibration();
    }

}