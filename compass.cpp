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
    //% blockId="input_compass_is_calibrated" block="is compass calibrated?"
    //% weight=45
    int isCalibratedCompass() {
        return uBit.compass.isCalibrated();
    }

    /**
     * Obsolete, compass calibration is automatic.
     */
    //% help=input/calibrate-compass advanced=true
    //% blockId="input_compass_clear_calibration" block="clear compass calibration"
    //% weight=45
    void clearCalibrationCompass() {
        uBit.compass.clearCalibration();
    }

    /**
     * Obsolete, compass calibration is automatic.
     */
    //% help=input/calibrate-compass advanced=true
    //% blockId="input_compass_assume_calibration" block="assume compass calibrated"
    //% weight=45
    void assumeCalibratedCompass() {
        // uBit.compass.assumeCalibrated();
    }

}