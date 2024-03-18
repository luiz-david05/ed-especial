## hello_world.h

```c
// garante que o cabeçalho só será incluído uma vez
#pragma once
#define HELLO_WORLD

/* declara a função "hello()", que não recebe argumentos e retorna um ponteiro para char ("const char*"). 
Um ponteiro para um char (nesse caso um ponteiro para o primeiro caractere de uma string) é comumente 
usado para representar strings em C. */

const char *hello(void); 
```

## hello_world.c

```c
#include "hello_world.h"

const char *hello(void) {
    return "Hello, World!";
}
```
