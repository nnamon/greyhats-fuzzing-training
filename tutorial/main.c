#include "vulnerable.h"

int main() {
    char * ptr;

    // Print Date
    struct DateCommand {
        uint32_t id;
        char payload[24];
    } date_command;
    date_command.id = 0xfefefefe;
    strcpy(date_command.payload, "/bin/date");
    ptr = (char *) &date_command;
    parse_data(ptr, sizeof(date_command));

    // Command One
    struct OneCommand {
        uint32_t id;
        uint8_t size;
    } one_command;
    one_command.id = 0;
    one_command.size = 9 + 12;
    ptr = (char *) &one_command;
    parse_data(ptr, sizeof(one_command));

    // Command Two
    struct TwoCommand {
        uint32_t id;
        uint8_t payload[4];
    } two_command;
    two_command.id = 1;
    two_command.payload[0] = 2;
    two_command.payload[1] = 3;
    two_command.payload[2] = 2;
    two_command.payload[3] = 0;
    ptr = (char *) &two_command;
    parse_data(ptr, sizeof(two_command));

    return 0;
}
