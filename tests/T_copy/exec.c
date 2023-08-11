


#include <stdio.h>

#define ZSTRING_IMPLEMENTATION
#include "../../src/zstring.h"

int main(int argc, char *argv[]){

    zstring str = newZString(" HELLOW, WORLD! ");
    zstring copied = copyStr(str);
    printf("%s",copied.data);    
    freeZString(copied);
    freeZString(str);

    return 0;
}