#include <stdio.h>

#include "src/zstring.h"
#define ZSTRING_IMPLEMENTATION

int main(int argc, char *argv[]){

    zstring str = newZString("Hello, world!");
    zstring trimmedString = newZString("");
    zstring removedWordString = newZString("");
    zstring copiedString = newZString("");
    zstring removedCharString = newZString("");
    zstring reversedString = newZString("");
    
    int occurances = 0;
    char toFind = 'w';
    char toRemove[] = "world";
    Bool areEqual = False;

    str.length = lenOfStr(str.data);
    printf("String: '%s' of Len: %d\n", str.data, str.length);

    trimmedString = trimStr(str);
    printf("Trimmed: '%s' of len: %d\n", trimmedString.data, trimmedString.length);
    
    occurances = findOccuranceOf(str, toFind);
    printf("In the string: '%s' the '%c' occures %d times\n", str.data, toFind, occurances);

    removedWordString  = removeWord(str, toRemove);
    printf("Removed '%s' at index %d to String: '%s' of len: %d\n", toRemove, findStartOfWord(str, toRemove),removedWordString.data, removedWordString.length);
    
    copiedString = copyStr(str);
    printf("Copied: '%s' of len: %d\n", copiedString.data, copiedString.length);
    
    areEqual = compareString(str, toLowercaseStr(str));
    printf("String 1 : '%s' and String 2: '%s' are equal? %s\n", str.data, toLowercaseStr(str).data, areEqual ? "True" : "False");
    
    removedCharString  = removeChar(str, toFind);
    printf("Removed '%c' to String: '%s' of len: %d\n", toFind, removedCharString.data, removedCharString.length);

    reversedString = reverseStr(str);
    printf("Reversed: '%s' of len %d\n", reversedString.data, reversedString.length);

    return 0;
}