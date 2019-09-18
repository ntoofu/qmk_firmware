#include "pfk.h"

void keyboard_pre_init_kb(void) {
    setPinOutput(_LED1);
    setPinOutput(_LED2);
    writePinHigh(_LED1);
    writePinHigh(_LED2);
    _delay_ms(100);
    writePinLow(_LED1);
    writePinLow(_LED2);
}
