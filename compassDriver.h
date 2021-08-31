#include "MicroBitCompass.h"

class MicroBitCompassDriver : public MicroBitCompass
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
        MicroBitCompass(CoordinateSpace &coordinateSpace, uint16_t id = MICROBIT_ID_COMPASS);

        /**
         * Constructor.
         * Create a software abstraction of an e-compass.
         *
         * @param id the unique EventModel id of this component. Defaults to: MICROBIT_ID_COMPASS
         * @param accel the accelerometer to use for tilt compensation
         * @param coordinateSpace the orientation of the sensor. Defaults to: SIMPLE_CARTESIAN
         *
         */
        MicroBitCompass(MicroBitAccelerometer &accel, CoordinateSpace &coordinateSpace, uint16_t id = MICROBIT_ID_COMPASS);


    private:

        /**
         * Internal helper used to de-duplicate code in the constructors
         *
         */
        void init(uint16_t id);

};