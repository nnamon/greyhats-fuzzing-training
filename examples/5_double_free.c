#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

void vuln() {
    char * one = malloc(24);
    char * two = malloc(24);
    char * three = malloc(24);
    printf("one ptr = 0x%p\n", one);
    printf("two ptr = 0x%p\n", two);
    printf("three ptr = 0x%p\n", three);

    free(one);
    puts("free one");
    free(two);
    puts("free two");
    free(one);
    puts("free one");

    char * four = malloc(24);
    char * five = malloc(24);
    char * six = malloc(24);
    printf("four ptr = 0x%p\n", four);
    printf("five ptr = 0x%p\n", five);
    printf("six ptr = 0x%p\n", six);
}

int main() {
    vuln();
}
