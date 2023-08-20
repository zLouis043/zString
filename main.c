#include <stdio.h>

#define ZSTRING_IMPLEMENTATION
#include "src/zstring.h"

int main(int argc, char *argv[]){

    if(argc < 3){
        fprintf(stderr,"Error! Not Enough Arguments => Usage: %s <string> <function>", argv[0]);
        exit(1);
    }

    zstring str = newZString(argv[1]);

    switch(argv[2][1]){
        case 'l': 
            printf("String Length: %d\n", str.length);
            break;
        case 't':

            switch(argv[2][2]){
                case 'r':
                   zstring trimmedString = trimStr(str); 
                   printf("Trimmed string: '%s'\n", trimmedString.data);
                   freeZString(trimmedString);
                   break;
                case 'l':
                    zstring toLowStr = toLowercaseStr(str);
                    printf("To LowerCase string: '%s'\n", toLowStr.data);
                    freeZString(toLowStr);
                    break;
                case 'u':
                    zstring toUpStr = toUppercaseStr(str);
                    printf("To UpperCase string: '%s'\n", toUpStr.data);
                    freeZString(toUpStr);
                    break;
            }

            break;
            
        case 'r':

            switch(argv[2][2]){
                case 'e':
                    zstring reversedStr = reverseStr(str);
                    printf("Reversed string: '%s'\n", reversedStr.data);
                    freeZString(reversedStr);
                    break;
                case 'w':

                    if(argc != 4) {
                        fprintf(stderr, "Error! Not enough arguments => Usage: %s <string> -rw <wordToRemove> \n", argv[0]);
                        exit(1);
                    }

                    zstring removedWord = removeWord(str, argv[3]);
                    printf("String with removed word: '%s'\n", removedWord.data);
                    freeZString(removedWord);
                    break;

                case 'c':

                    if(argc != 4) {
                        fprintf(stderr, "Error! Not enough arguments => Usage: %s <string> -rc <charToRemove> \n", argv[0]);
                        exit(1);
                    }

                    zstring removedChar;

                    switch(argv[2][3]){
                        case 's':
                            removedChar= removeChar(str, argv[3][0]);
                            printf("String with removed word: '%s'\n", removedChar.data);
                            break;
                        case 'i':
                            removedChar= removeCharCI(str, argv[3][0]);
                            printf("String with removed word: '%s'\n", removedChar.data);
                            break;
                    }

                    freeZString(removedChar);
                    break;                
            }
            break;
        case 'c':
            switch(argv[2][2]){
                case 'm':
                    if(argc != 4) {
                        fprintf(stderr, "Error! Not enough arguments => Usage: %s <string1> -cm <string2> \n", argv[0]);
                        exit(1);
                    }

                    switch(argv[2][3]){
                        case 's':
                        printf("Are '%s' and '%s' equal? %s\n", str.data, argv[3], compareString(str, newZString(argv[3])) ? "True" : "False");
                        break;
                        case 'i':
                        printf("Are '%s' and '%s' equal? %s\n", str.data, argv[3], compareStringCI(str, newZString(argv[3])) ? "True" : "False");
                        break;
                    }

                    break;
                case 'c':
                    if(argc != 4) {
                        fprintf(stderr, "Error! Not enough arguments => Usage: %s <string1> -cc <string2> \n", argv[0]);
                        exit(1);
                    }
                    zstring concatenatedStr = concatenateStr(str, newZString(argv[3]));
                    printf("Concatenated string: '%s'\n", concatenatedStr.data);
                    freeZString(concatenatedStr);
                    break;
            }
            break;
        case 'n':
            size_t numOfWords = numberOfWords(str);
            printf("Number of words in string : %d\n", numOfWords);
            break;
        case 'o':
            if(argc != 4) {
                fprintf(stderr, "Error! Not enough arguments => Usage: %s <string> -o <charToFind>\n", argv[0]);
                exit(1);
            }

            size_t occurances = 0;

            switch(argv[2][2]){
                case 's':
                occurances = findOccuranceOf(str, argv[3][0]);
                break;
                case 'i':
                occurances = findOccuranceOfCI(str, argv[3][0]);
                break;
            }
            printf("In the string: '%s' the '%c' occures %zu times\n", str.data, argv[3][0], occurances);
            break;
    }

    
    freeZString(str);


    return 0;
}