


#include <stdio.h>

#define ZSTRING_IMPLEMENTATION
#include "../../src/zstring.h"

int main(int argc, char *argv[]){

    zstring str = newZString(" HELLOW, WORLD! ");
    zstring trimed = trimStr(str);
    printf("%s",trimed.data);    
    freeZString(trimed);
    freeZString(str);

    return 0;
}