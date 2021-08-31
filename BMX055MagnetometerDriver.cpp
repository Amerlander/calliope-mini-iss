#include "BMX055MagnetometerDriver.h"


/**
  * Constructor.
  * Create a software abstraction of an FXSO8700 combined magnetometer/magnetometer
  *
  * @param _i2c an instance of I2C used to communicate with the device.
  *
  * @param address the default I2C address of the magnetometer. Defaults to: FXS8700_DEFAULT_ADDR.
  *
 */
BMX055MagnetometerDriver::BMX055MagnetometerDriver(MicroBitI2C &_i2c, MicroBitPin _int1, CoordinateSpace &coordinateSpace,
                                       uint16_t address, uint16_t id) : BMX055Magnetometer(_i2c, _int1, coordinateSpace, address, id) {
}