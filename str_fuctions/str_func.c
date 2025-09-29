#include <stdio.h>

int strlength(char* string) {
    char* ptr = string;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - string;
}

void strcopy(char* to, char* from) {
    while (*from != '\0') {
        *to = *from;
        to++;
        from++;
    }
}

int main(int argc, char** argv) {
    // strlength test
    printf("Hello length is: %d\n", strlength("Hello"));

    // strcopy test
    char* origin = "Hello world";
    char destiny[4];

    strcopy(destiny, origin);

    printf(destiny);
    return 0;
}