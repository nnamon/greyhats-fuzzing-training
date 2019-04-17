#include <stdlib.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define COMMANDS 4

int parse_data(char * data, size_t size);

uint32_t identify_command(uint32_t identifier);

void command_one(char * offset, size_t size);

void command_two(char * offset, size_t size);

void command_three(char * offset, size_t size);

void command_four(char * offset, size_t size);

void spawn_shell(char * offset);

void wildcard(char * offset);
