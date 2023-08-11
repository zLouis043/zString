

#include <stdio.h>

#define ZSTRING_IMPLEMENTATION
#include "src/zstring.h"

int main(int argc, char *argv[]){

    zstring str = newZString(" HELLOW, WORLD! ");
    zstring separated = sub_str(str,0,4);
    printf("%s\n",separated.data);

    return 0;
}