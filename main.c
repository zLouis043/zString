#include <stdio.h>

#define ZSTRING_IMPLEMENTATION
#include "src/zstring.h"

int main(int argc, char *argv[]){


    zstring str = newZString("Hello, World! New String Library 2023");
    printf("String: '%s' of Len: %zu\n\n", str.data, str.length);

    
    zstring trimmedString = trimStr(str);
    printf("Trimmed: '%s' of len: %zu\n\n", trimmedString.data, trimmedString.length);
    
    char toFind = 'w';    
    size_t occurances = findOccuranceOf(str, toFind);
    printf("In the string: '%s' the '%c' occures %zu times\n\n", str.data, toFind, occurances);
    
    char toRemove[] = "Hello, World";
    zstring removedWordString  = removeWord(str, toRemove);
    printf("Removed '%s' at index %zu to String: '%s' of len: %zu\n\n", toRemove, findStartOfWord(str, toRemove),removedWordString.data, removedWordString.length);
    
    zstring copiedString = copyStr(str);
    printf("Copied: '%s' of len: %zu\n\n", copiedString.data, copiedString.length);
    
    zstring lower_case_str =  toLowercaseStr(str);
    Bool areEqual = compareString(str,lower_case_str);
    printf("String 1 : '%s' and String 2: '%s' are equal? %s\n\n", str.data, lower_case_str.data, areEqual ? "True" : "False");
    
    zstring removedCharString  = removeChar(str, toFind);
    printf("Removed '%c' to String: '%s' of len: %zu\n\n", toFind, removedCharString.data, removedCharString.length);
   
    zstring reversedString = reverseStr(str);
    printf("Reversed: '%s' of len %zu\n\n", reversedString.data, reversedString.length);

    size_t numOfWords = numberOfWords(str);
    printf("In this string there are %zu words\n\n", numOfWords);

    zstring printedString = printz(100, "Hello there %s!", toRemove);

    zstring concatenatedString = concatenateStr(str, printedString);
    printf("Concatenated string: %s of len: %zu\n\n", concatenatedString.data, concatenatedString.length); 


    freeZString(str);
    freeZString(trimmedString);
    freeZString(removedWordString);
    freeZString(copiedString);
    freeZString(lower_case_str);
    freeZString(removedCharString);
    freeZString(reversedString);
    freeZString(printedString);
    freeZString(concatenatedString);

    return 0;
}