#include <stdio.h>
#include <stdlib.h>

/*
zString library made by zLouis043
Check out the documentation on https://github.com/zLouis043/zString
Use this main.c to test the functionalities of the zstring library.
*/

#define ZSTRING_IMPLEMENTATION
#include "src/zstring.h"

int main(int argc, char *argv[]){

    if(argc < 3){
        fprintf(stderr,"Error! Not Enough Arguments => Usage: %s <string> <function>", argv[0]);
        exit(1);
    }

    zstring str =  newZString(argv[1]);

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
                default:
                    fprintf(stderr,"Error! Incorrect Arguments => Usage: %s <string> <function>", argv[0]);
                    exit(1);
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

                    if(argc != 5) {
                        fprintf(stderr, "Error! Not enough arguments => Usage: %s <string> -rw -s or - i <wordToRemove> \n", argv[0]);
                        exit(1);
                    }

                    zstring removedWord = removeWord(str, argv[4]);

                    switch(argv[3][1]){
                        case 's':
                        removedWord = removeWord(str, argv[4]);
                        break;
                        case 'i':
                        removedWord = removeWordCI(str, argv[4]);
                        break;
                        default:
                        fprintf(stderr, "Error! Incorrect arguments => Usage: %s <string> -rw -s or - i <wordToRemove> \n", argv[0]);
                        exit(1);
                        break;
                    }

                    printf("String with removed word: '%s'\n", removedWord.data);
                    freeZString(removedWord);
                    break;
                case 'c':

                    if(argc != 5) {
                        fprintf(stderr, "Error! Not enough arguments => Usage: %s <string> -rc -s or -i <charToRemove> \n", argv[0]);
                        exit(1);
                    }

                    zstring removedChar;

                    switch(argv[3][1]){
                        case 's':
                            removedChar= removeChar(str, argv[4][0]);
                            printf("String with removed word: '%s'\n", removedChar.data);
                            break;
                        case 'i':
                            removedChar= removeCharCI(str, argv[4][0]);
                            printf("String with removed word: '%s'\n", removedChar.data);
                            break;
                        default:
                        fprintf(stderr, "Error! Incorrect arguments => Usage: %s <string> -rc -s or -i <charToRemove> \n", argv[0]);
                        exit(1);
                        break;
                    }

                    freeZString(removedChar);
                    break;
                case 'a':
                    if(argc != 3){
                        fprintf(stderr, "Error! Not enough arguments => Usage: %s <float> -ra\n", argv[0]);
                        exit(1);
                    }
                    double f = atof(argv[1]);
                    zstring rationalizedString = rationalizeFloatToStr(f, 3);
                    printf("Num: %f to Rational string => '%s'\n", f, rationalizedString.data);
                    freeZString(rationalizedString);
                    break;
                     
                default:
                fprintf(stderr, "Error! Incorrect arguments => Usage: %s <string> -re / -rw or -rc <ToRemove> \n", argv[0]);
                exit(1);
            break;               
            }
            break;
        case 'c':
            switch(argv[2][2]){
                case 'm':

                    if(argc != 5) {
                        fprintf(stderr, "Error! Not enough arguments => Usage: %s <string1> -cm -s or -i <string2> \n", argv[0]);
                        exit(1);
                    }

                    switch(argv[3][1]){
                        case 's':
                        printf("Are '%s' and '%s' equal? %s\n", str.data, argv[4], compareString(str, newZString(argv[4])) ? "True" : "False");
                        break;
                        case 'i':
                        printf("Are '%s' and '%s' equal? %s\n", str.data, argv[4], compareStringCI(str, newZString(argv[4])) ? "True" : "False");
                        break;
                        default:
                        fprintf(stderr, "Error! Incorrect arguments => Usage: %s <string1> -cm -s or -i <string2> \n", argv[0]);
                        exit(1);
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
                case 'p':
                    if(argc != 6) {
                        fprintf(stderr, "Error! Not enough arguments => Usage: %s <string1> -cp -l or - r -s or -w <size> or <numOfWords>\n", argv[0]);
                        exit(1);
                    }
                    zstring choppedStr;
                    switch(argv[3][1]){
                        case 'l':
                            switch (argv[4][1])
                            {
                            case 's':
                                choppedStr = chopLeftBySize(str, atoi(argv[5]));
                                printf("Chopped String From Left by Size[%zu]: '%s'\n", atoi(argv[5]), choppedStr.data);
                                freeZString(choppedStr);
                            break;
                            case 'w':
                                choppedStr = chopLeftByWordsNumb(str, atoi(argv[5]));
                                printf("Chopped String From Left by Words[%zu]: '%s'\n", atoi(argv[5]), choppedStr.data);
                                freeZString(choppedStr);
                            break;
                            default: 
                            fprintf(stderr, "Error! Incorrect Arguments => Usage: %s <string1> -cp -l or - r -s or -w <size> or <numOfWords>\n", argv[0]);
                            exit(1);
                            }
                        break;
                        case 'r':
                        switch (argv[4][1])
                            {
                            case 's':
                                choppedStr = chopRightBySize(str, atoi(argv[5]));
                                printf("Chopped String From Left by Size[%zu]: '%s'\n", atoi(argv[5]), choppedStr.data);
                                freeZString(choppedStr);
                            break;
                            case 'w':
                                choppedStr = chopRightByWordsNumb(str, atoi(argv[5]));
                                printf("Chopped String From Left by Words[%zu]: '%s'\n", atoi(argv[5]), choppedStr.data);
                                freeZString(choppedStr);
                            break;
                            default: 
                            fprintf(stderr, "Error! Incorrect Arguments => Usage: %s <string1> -cp -l or - r -s or -w <size> or <numOfWords>\n", argv[0]);
                            exit(1);
                            }
                        break;
                        default: 
                        fprintf(stderr, "Error! Incorrect Arguments => Usage: %s <string1> -cp -l or - r -s or -w <size> or <numOfWords>\n", argv[0]);
                        exit(1);
                    }
                    break;
                default:
                    fprintf(stderr,"Error! Incorrect Arguments => Usage: %s <string> <function>", argv[0]);
                    exit(1);
                    break;
            }
            break;
        case 'n':
            size_t numOfWords = numberOfWords(str);
            printf("Number of words in string : %d\n", numOfWords);
            break;
        case 'o':

            if(argc != 5) {
                fprintf(stderr, "Error! Not enough arguments => Usage: %s <string> -o -s or -i <charToFind>\n", argv[0]);
                exit(1);
            }

            size_t occurances = 0;

            switch(argv[3][1]){
                case 's':
                occurances = findOccuranceOf(str, argv[4][0]);
                break;
                case 'i':
                occurances = findOccuranceOfCI(str, argv[4][0]);
                break;
                default:
                fprintf(stderr, "Error! Incorrect arguments => Usage: %s <string> -o -s or -i <charToFind>\n", argv[0]);
                exit(1);
                break;
            }
            printf("In the string: '%s' the '%c' occures %zu times\n", str.data, argv[4][0], occurances);
            break;
        default:
            fprintf(stderr,"Error! Incorrect Arguments => Usage: %s <string> -o -s or -i <charToFind>\n", argv[0]);
            exit(1);
            break;
    }

    freeZString(str);

    return 0;
}