#include "pxt.h"
#include "compassDriver.h"
using namespace pxt;

/**
 * 
 */
namespace input {

    /**
     * 
     */
    //% help=input/calibrate-compass advanced=true
    //% blockId="input_compass_is_calibrated" block="is compass calibrated?"
    //% weight=45
    int isCalibratedCompass() {
        return uBit.compass.isCalibrated();
    }

    /**
     * 
     */
    //% help=input/calibrate-compass advanced=true
    //% blockId="input_compass_clear_calibration" block="clear compass calibration"
    //% weight=45
    void clearCalibrationCompass() {
        uBit.compass.clearCalibration();
    }

    /**
     * 
     */
    //% help=input/calibrate-compass advanced=true
    //% blockId="input_compass_assume_calibration" block="assume compass calibrated"
    //% weight=45
    void assumeCalibratedCompass() {
        uBit.compass.clearCalibration();
        MicroBitCompassDriver compass;
        // compass.assumeCalibrated();
    }

}