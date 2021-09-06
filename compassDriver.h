#include "MicroBitConfig.h"
#include "MicroBitComponent.h"
#include "CoordinateSystem.h"
#include "MicroBitAccelerometer.h"


/**
 * Status flags
 */
// #define MICROBIT_COMPASS_STATUS_RUNNING                  0x01
// #define MICROBIT_COMPASS_STATUS_CALIBRATED               0x02
// #define MICROBIT_COMPASS_STATUS_CALIBRATING              0x04
// #define MICROBIT_COMPASS_STATUS_ADDED_TO_IDLE            0x08

/**
 * Accelerometer events
 */
// #define MICROBIT_COMPASS_EVT_DATA_UPDATE                 1
// #define MICROBIT_COMPASS_EVT_CONFIG_NEEDED               2
// #define MICROBIT_COMPASS_EVT_CALIBRATE                   3
// #define MICROBIT_COMPASS_EVT_CALIBRATION_NEEDED          4

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
        MicroBitCompassDriver(uint16_t id = MICROBIT_ID_COMPASS);

    private:

        /**
         * Internal helper used to de-duplicate code in the constructors
         *
         */
        void init(uint16_t id);

};