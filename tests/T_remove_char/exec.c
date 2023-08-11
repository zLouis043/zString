


#include <stdio.h>

#define ZSTRING_IMPLEMENTATION
#include "../../src/zstring.h"

int main(int argc, char *argv[]){

    zstring str = newZString(" hello world! ");
    zstring removed = removeChar(str,'c');
    printf("%s",removed.data);    
    freeZString(removed);
    freeZString(str);

    return 0;
}