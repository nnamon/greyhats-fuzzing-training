#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

void vuln(char * input) {
    uint32_t canary = 0xdeadbeef;
    char buffer[24];
    printf("canary = 0x%x\n", canary);
    strcpy(buffer, input);
    printf("canary = 0x%x\n", canary);
}

int main() {
    char input[512] = {0};
    memset(input, 'A', sizeof(input) - 1);
    vuln(input);
}
