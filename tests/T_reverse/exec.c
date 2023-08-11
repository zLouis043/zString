


#include <stdio.h>

#define ZSTRING_IMPLEMENTATION
#include "../../src/zstring.h"

int main(int argc, char *argv[]){

    zstring str = newZString(" HELLOW, WORLD! ");
    zstring reversed = reverseStr(str);
    printf("%s",reversed.data);    
    freeZString(reversed);
    freeZString(str);

    return 0;
}