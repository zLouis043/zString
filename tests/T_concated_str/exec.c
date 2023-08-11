


#include <stdio.h>

#define ZSTRING_IMPLEMENTATION
#include "../../src/zstring.h"

int main(int argc, char *argv[]){

    zstring str = newZString(" HELLOW, WORLD! ");
    zstring str2 = newZString("my mensage");
    zstring concated = concatenateStr(str,str2);
    printf("%s",concated.data);    
    freeZString(str2);
    freeZString(concated);
    freeZString(str);

    return 0;
}