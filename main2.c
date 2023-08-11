#include <stdio.h>

#define ZSTRING_IMPLEMENTATION
#include "src/zstring.h"

int main(int argc, char *argv[]){


    char toRemove[] = "Hello, World";
    

    zstring printedString = printz("Hello there %s!" , toRemove);

    return 0;
}