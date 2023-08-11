


#include <stdio.h>

#define ZSTRING_IMPLEMENTATION
#include "../../src/zstring.h"

int main(int argc, char *argv[]){

    zstring str = newZString(" HELLO, WORLD! ");
    printf("%d",findOccuranceOf(str,'E'));    

    freeZString(str);

    return 0;
}