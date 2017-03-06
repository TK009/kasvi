#ifndef STANDARDFIRMATA_H
#define STANDARDFIRMATA_H

#include "StreamConnector.h"

extern StreamConnector FirmataConnector;

void firmata_setup();
void firmata_loop();

#endif
