#include "BMX055Magnetometer.h"

class BMX055MagnetometerDriver : public BMX055Magnetometer {

public:
    /**
     * Constructor.
     * Create a software abstraction of an compass.
     *
     * @param coordinateSpace The orientation of the sensor. Defaults to: SIMPLE_CARTESIAN
     * @param id The unique EventModel id of this component. Defaults to: MICROBIT_ID_ACCELEROMETER
     *
     */
    BMX055MagnetometerDriver(MicroBitI2C& _i2c, MicroBitPin _int1, CoordinateSpace &coordinateSpace, uint16_t address = BMX055_M_DEFAULT_ADDR, uint16_t id = MICROBIT_ID_COMPASS);

};