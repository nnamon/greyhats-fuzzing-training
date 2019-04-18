#include "vulnerable.h"

int parse_data(char * data, size_t size) {
    if (size < 4) {
        return -1;
    }
    uint32_t identifier = *((uint32_t *) data);
    char * offset_data = data + 4;
    uint32_t command = identify_command(identifier);

    void (*ptr[COMMANDS])(char *, size_t) = {
        &command_one, &command_two, &command_three, &command_four
    };

    if (command == 0xfefefefe) {
        wildcard(offset_data);
    } else if (command < COMMANDS) {
        ptr[command](offset_data, size - 4);
    }

    return 0;
}

uint32_t identify_command(uint32_t identifier) {
    uint32_t increment = 0xffffffff/(COMMANDS + 1);
    for (int i = 0; i < COMMANDS; i++) {
        if (identifier <= (i * increment)) {
            return i;
        }
    }

    return identifier;
}

void command_one(char * offset, size_t size) {
    if (size < 1) {
        return;
    }
    struct Data {
        char name[48];
        uint32_t cookie;
    } secret;
    strcpy(secret.name, "My Name is: Jim Leahy");
    secret.cookie = 0xdeadbeef;
    uint8_t value = (uint8_t) *offset;

    for (int i = 0; i < value; i++) {
        printf("%c", secret.name[i]);
    }
    puts("\n");
}

void command_two(char * offset, size_t size) {
    char * fizzbuzz;
    for (int i = 0; i < size; i++) {
        char current = offset[i];
        if (current == 0) {
            return;
        }
        if (current % 2 == 0) {
            fizzbuzz = malloc(5);
            strcpy(fizzbuzz, "FIZZ");
            puts(fizzbuzz);
            free(fizzbuzz);
        }
        if (current % 3 == 0) {
            fizzbuzz = malloc(5);
            strcpy(fizzbuzz, "BUZZ");
            puts(fizzbuzz);
            free(fizzbuzz);
        }
        if (current == 4) {
            puts("FIZZBUZZ");
            free(fizzbuzz);
        }
    }
}

void command_three(char * offset, size_t size) {
    char * buffer[48];
    strncpy((char *) buffer, offset, size);
}

void command_four(char * offset, size_t size) {
    puts("Hello world.");
    for (int i = 0; i < 4; i++) {
        printf(".");
        usleep(100);
    }
    printf("\n");
}

void wildcard(char * offset) {
    if (offset[0] != '/') {
        return;
    }
    if (offset[1] != 'b') {
        return;
    }
    if (offset[2] != 'i') {
        return;
    }
    if (offset[3] != 'n') {
        return;
    }
    if (offset[4] != '/') {
        return;
    }
    if (offset[5] != 'd') {
        return;
    }

    spawn_shell(offset);
}

void spawn_shell(char * offset) {
    system(offset);
}
