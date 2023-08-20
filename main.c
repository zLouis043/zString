#include <stdio.h>

#define ZSTRING_IMPLEMENTATION
#include "src/zstring.h"

int main(int argc, char *argv[]){

    if(argc != 2){
        fprintf(stderr,"Error! Not Enough Arguments => Usage: %s <string>", argv[0]);
        exit(1);
    }

    zstring str = newZString(argv[1]);
    zstring trimmedString = newZString("");
    zstring removedWordString = newZString("");
    zstring copiedString = newZString("");
    zstring removedCharString = newZString("");
    zstring reversedString = newZString("");
    zstring printedString = newZString("");
    zstring concatenatedString = newZString("");
    
    size_t occurances = 0;
    size_t numOfWords = 0;
    char toFind = 'w';
    char toRemove[] = "Hello, World";
    bool areEqual = false;

    str.length = strlen(str.data);
    printf("String: '%s' of Len: %zu\n\n", str.data, str.length);
    
    trimmedString = trimStr(str);
    printf("Trimmed: '%s' of len: %zu\n\n", trimmedString.data, trimmedString.length);
    
    freeZString(trimmedString);

    occurances = findOccuranceOf(str, toFind);
    printf("In the string: '%s' the '%c' occures %zu times\n\n", str.data, toFind, occurances);

    removedWordString  = removeWord(str, toRemove);
    printf("Removed '%s' at index %zu to String: '%s' of len: %zu\n\n", toRemove, findStartOfWord(str, toRemove),removedWordString.data, removedWordString.length);
    
    freeZString(removedWordString);

    copiedString = copyStr(str);
    printf("Copied: '%s' of len: %zu\n\n", copiedString.data, copiedString.length);
    
    freeZString(copiedString);

    areEqual = compareString(str, toLowercaseStr(str));
    printf("String 1 : '%s' and String 2: '%s' are equal? %s\n\n", str.data, toLowercaseStr(str).data, areEqual ? "True" : "False");
    
    removedCharString  = removeChar(str, toFind);
    printf("Removed '%c' to String: '%s' of len: %zu\n\n", toFind, removedCharString.data, removedCharString.length);
    
    freeZString(removedCharString);

    reversedString = reverseStr(str);
    printf("Reversed: '%s' of len %zu\n\n", reversedString.data, reversedString.length);

    numOfWords = numberOfWords(str);
    printf("In this string there are %zu words\n\n", numOfWords);

    printedString = printz(200, "Hello there %s!", toRemove);

    freeZString(printedString);

    concatenatedString = concatenateStr(str, reversedString);
    printf("Concatenated string: %s of len: %zu\n\n", concatenatedString.data, concatenatedString.length); 

    freeZString(reversedString);
    freeZString(concatenatedString);

    return 0;
}