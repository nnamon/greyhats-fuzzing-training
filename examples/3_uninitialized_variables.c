#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

void vuln() {
    uint64_t uninit;
    printf("uninit = 0x%lx\n", uninit);
}

void set_vars() {
    uint64_t var;
    var = 0x4141414142424242;
    printf("var = 0x%lx\n", var);
}

int main() {
    vuln();
    set_vars();
    vuln();
}
