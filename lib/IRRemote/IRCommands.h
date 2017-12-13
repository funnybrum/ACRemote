#ifndef _IRCOMMANDS_H_
#define _IRCOMMANDS_H_

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include <stdint.h>

struct IRCommand {
    char* key;
    char* description;
    uint16_t* rawData;
    uint16_t rawDataSize;
    uint16_t frequency;
};

#endif