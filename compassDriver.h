#include "MicroBitCompass.h"

class MicroBitCompassDriver : public MicroBitCompass
{

    private:

        /**
         * Internal helper used to de-duplicate code in the constructors
         *
         */
        void init(uint16_t id);

};