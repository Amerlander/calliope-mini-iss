#include "MicroBitCompass.h"

class MicroBitCompassLazy : public MicroBitCompass
{

    protected:

        uint16_t                samplePeriod;               // The time between samples, in milliseconds.
        CompassCalibration      calibration;                // The calibration data of this compass 
        Sample3D                sample;                     // The last sample read, in the coordinate system specified by the coordinateSpace variable.
        Sample3D                sampleENU;                  // The last sample read, in raw ENU format (stored in case requests are made for data in other coordinate spaces)
        CoordinateSpace         &coordinateSpace;           // The coordinate space transform (if any) to apply to the raw data from the hardware.
        MicroBitAccelerometer*  accelerometer;              // The accelerometer to use for tilt compensation.

    public:

       static MicroBitCompass   *detectedCompass;           // The autodetected instance of a MicroBitAcelerometer driver.

        /**
         * Constructor.
         * Create a software abstraction of an e-compass.
         *
         * @param id the unique EventModel id of this component. Defaults to: MICROBIT_ID_COMPASS
         * @param coordinateSpace the orientation of the sensor. Defaults to: SIMPLE_CARTESIAN
         *
         */
        MicroBitCompassLazy(CoordinateSpace &coordinateSpace, uint16_t id = MICROBIT_ID_COMPASS);

        /**
         * Constructor.
         * Create a software abstraction of an e-compass.
         *
         * @param id the unique EventModel id of this component. Defaults to: MICROBIT_ID_COMPASS
         * @param accel the accelerometer to use for tilt compensation
         * @param coordinateSpace the orientation of the sensor. Defaults to: SIMPLE_CARTESIAN
         *
         */
        MicroBitCompassLazy(MicroBitAccelerometer &accel, CoordinateSpace &coordinateSpace, uint16_t id = MICROBIT_ID_COMPASS);


        /**
         * Device autodetection. Scans the given I2C bus for supported compass devices.
         * if found, constructs an appropriate driver and returns it.
         *
         * @param i2c the bus to scan. 
         *
         */
        static MicroBitCompassLazy& autoDetect(MicroBitI2C &i2c); 


    private:

        /**
         * Internal helper used to de-duplicate code in the constructors
         *
         */
        void init(uint16_t id);

};