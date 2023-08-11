

#include <stdio.h>

#define ZSTRING_IMPLEMENTATION
#include "src/zstring.h"

int main(int argc, char *argv[]){

    zstring str = newZString(" HELLOW, WORLD! ");
    zstring lower = toLowercaseStr(str);
    printf("%s",lower.data);    
    freeZString(lower);
    freeZString(str);

    return 0;
}