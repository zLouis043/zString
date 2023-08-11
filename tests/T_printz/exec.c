


#include <stdio.h>

#define ZSTRING_IMPLEMENTATION
#include "../../src/zstring.h"

int main(int argc, char *argv[]){

    zstring str = printz(200,"hello %s","name");
    printf("%s",str.data);    
    freeZString(str);

    return 0;
}