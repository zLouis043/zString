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
    
    size_t  occurances = 0;
    char toFind = 'w';
    char toRemove[] = "world";
    Bool areEqual = False;

    str.length = lenOfStr(str.data);
    printf("String: '%s' of Len: %zu\n", str.data, str.length);

    trimmedString = trimStr(str);
    printf("Trimmed: '%s' of len: %zu\n", trimmedString.data, trimmedString.length);
    
    occurances = findOccuranceOf(str, toFind);
    printf("In the string: '%s' the '%c' occures %zu times\n", str.data, toFind, occurances);

    removedWordString  = removeWord(str, toRemove);
    printf("Removed '%s' at index %zu to String: '%s' of len: %zu\n", toRemove, findStartOfWord(str, toRemove),removedWordString.data, removedWordString.length);
    
    copiedString = copyStr(str);
    printf("Copied: '%s' of len: %zu\n", copiedString.data, copiedString.length);
    
    areEqual = compareString(str, toLowercaseStr(str));
    printf("String 1 : '%s' and String 2: '%s' are equal? %s\n", str.data, toLowercaseStr(str).data, areEqual ? "True" : "False");
    
    removedCharString  = removeChar(str, toFind);
    printf("Removed '%c' to String: '%s' of len: %zu\n", toFind, removedCharString.data, removedCharString.length);

    reversedString = reverseStr(str);
    printf("Reversed: '%s' of len %zu\n", reversedString.data, reversedString.length);

    return 0;
}