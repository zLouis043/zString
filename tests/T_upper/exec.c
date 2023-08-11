


#include <stdio.h>

#define ZSTRING_IMPLEMENTATION
#include "../../src/zstring.h"

int main(int argc, char *argv[]){

    zstring str = newZString(" hellow world! ");
    zstring upper = toUppercaseStr(str);
    printf("%s",upper.data);    
    freeZString(upper);
    freeZString(str);

    return 0;
}