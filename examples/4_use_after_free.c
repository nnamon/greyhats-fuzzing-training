#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define items 12

void vuln() {
    uint64_t * canary = malloc(sizeof(uint64_t) * items);
    memset(canary , 'A', sizeof(uint64_t) * items);
    for (int i = 0; i < items; i++) {
        printf("canary = 0x%lx\n", canary[i]);
    }

    free(canary);

    char * buffer = malloc(sizeof(uint64_t) * items);
    memset(buffer, 'B', sizeof(uint64_t) * items);
    for (int i = 0; i < items; i++) {
        printf("canary = 0x%lx\n", canary[i]);
    }
}

int main() {
    vuln();
}
