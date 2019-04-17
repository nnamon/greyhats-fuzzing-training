#include <stdint.h>
#include <stddef.h>
#include "vulnerable.h"

int LLVMFuzzerTestOneInput(const uint8_t * data, size_t size) {
    parse_data((char *) data, size);
    return 0;
}
