#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

struct Object {
    char buffer[24];
    uint32_t canary;
};

void vuln(struct Object * object, char * input) {
    printf("object->canary = 0x%x\n", object->canary);
    strcpy(object->buffer, input);
    printf("object->canary = 0x%x\n", object->canary);
}

int main() {
    char input[512] = {0};
    memset(input, 'A', sizeof(input) - 1);
    struct Object * object = malloc(sizeof(struct Object));
    object->canary = 0x42424242;
    vuln(object, input);
}
