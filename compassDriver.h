#include "MicroBitCompass.h"

class MicroBitCompassLazy : public MicroBitCompass
{

    public:

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