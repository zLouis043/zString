


#include <stdio.h>

#define ZSTRING_IMPLEMENTATION
#include "../../src/zstring.h"

int main(int argc, char *argv[]){

    zstring str = newZString(" HELLOW, WORLD! ");
    zstring str2 = newZString(" HELLOW, WORLD! ");
    printf("%d",compareString(str,str2));    
    freeZString(str2);
    freeZString(str);

    return 0;
}