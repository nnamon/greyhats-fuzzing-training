#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

struct TypeOne {
    char buffer[48];
    uint32_t canary;
};

struct TypeTwo {
    char buffer[24];
    uint32_t canary;
};

void right(void * object) {
    struct TypeOne * converted = (struct TypeOne *) object;
    printf("canary = 0x%x\n", converted->canary);
}

void vuln(void * object) {
    struct TypeTwo * converted = (struct TypeTwo *) object;
    printf("canary = 0x%x\n", converted->canary);
}

int main() {
    struct TypeOne object;
    memset(object.buffer, 'A', sizeof(struct TypeOne));
    object.canary = 0x42424242;
    right(&object);

    vuln(&object);
}
