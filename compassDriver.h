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
        MicroBitCompassDriver(CoordinateSpace &coordinateSpace, uint16_t id = MICROBIT_ID_COMPASS);


        void assumeCalibrated();

};