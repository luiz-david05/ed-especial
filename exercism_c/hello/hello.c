#include "hello.h"
#include <stdio.h>

const char *hello() {
    return "Hello, World!";
}

int main() {
    printf("%s", hello());

    return 0;
}