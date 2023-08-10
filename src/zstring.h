#ifndef ZSTRING_H_
#define ZSTRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>

typedef struct zstring{
    char *data;
    size_t length;
}zstring;

typedef enum{
    False = 0,
    True
}Bool;

size_t lenOfStr(const char* str);
size_t findOccuranceOf(zstring str, char toFind);
size_t findStartOfWord(zstring str, char* word);
size_t numberOfWords(zstring str);
char toLowerCase(char c);
char toupperCase(char c);
Bool isaDigit(char c);
Bool isaNumber(char c);
Bool isaSpace(char c);
Bool isaSymbol(char c);
Bool isaTerminator(char c);
Bool isaNewLine(char c);
Bool isWordInString(zstring str, char* word, int start);
Bool compareString(zstring str1, zstring str2);
zstring newZString(const char* str);
zstring printz(const char* str, ...);
zstring toLowercaseStr(zstring str);
zstring toUppercaseStr(zstring str);
zstring trimStr(zstring str);
zstring removeWord(zstring str, char* word);
zstring removeChar(zstring str, char c);
zstring copyStr(zstring str);
zstring reverseStr(zstring str);
zstring concatenateStr(zstring str1, zstring str2);

#endif // ZSTRING_H_

#ifndef ZSTRING_IMPLEMENTATION

size_t lenOfStr(const char* str){
    size_t len = 0;
    while(!isaTerminator(str[len])){
        len++;
    }
    return len;
}

size_t findOccuranceOf(zstring str, char toFind){
    size_t occurences = 0;
    size_t i = 0;
    zstring toLowCase = toLowercaseStr(str);
    printf("String to Lower : '%s' | char to find '%c'\n", toLowCase.data, toLowerCase(toFind));
    while(!isaTerminator(toLowCase.data[i])){
        if(toLowCase.data[i] == toLowerCase(toFind)){
            occurences++;
        }
        i++;
    }
    return occurences;
}

size_t findStartOfWord(zstring str, char* word){
    size_t i = 0; 
    while(!isaTerminator(str.data[i])){
        if(str.data[i] == word[0]){
            if(isWordInString(str, word, i)){
                return i;
            }
        }
        i++;
    }
    return False; //if it does not find the word in the string it returns False
}

size_t numberOfWords(zstring str){
    size_t i = 0; size_t n = 0;

    if(!isaSpace(str.data[0])){
        n++;
    }

    while(!isaTerminator(str.data[i])){
        while(isaSpace(str.data[i])){
            i++;
        }
        if(!isaSpace(str.data[i]) && isaSpace(str.data[i+1])){
            n++;
        }
        i++;
    }
    return n;
}

char toLowerCase(char c){
    if(c >= 'A' && c <= 'Z'){
        c += 32;
    }
    return c;
}
char toupperCase(char c){
    if(c >= 'a' && c <= 'z'){
        c -= 32;
    }
    return c;
}

Bool isaDigit(char c){
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

Bool isaNumber(char c){
    return (c >= '1' && c <= '9');
}

Bool isaSpace(char c){
    return (c == ' ');
}

Bool isaSymbol(char c){
    return (!isaDigit(c) && !isaNumber(c) && !isaSpace(c));
}

Bool isaTerminator(char c){
    return (c == '\0');
}

Bool isaNewLine(char c){
    return (c == '\n');
}

Bool isWordInString(zstring str, char* word, int start){
    size_t i = 0; size_t  j = 1;
    while(!isaTerminator(word[j])){
        if(word[j] != str.data[start+i+1]){
            return False;
        }
        j++;
        i++; 
    }
    return True;
}

Bool compareString(zstring str1, zstring str2){
    if(str1.length != str2.length){
        return False;
    }

    size_t i = 0; 
    while(!isaTerminator(str1.data[i])){
        if(str1.data[i] != str2.data[i]){
            return False;
        }
        i++;
    }

    return True;
}

zstring newZString(const char* str){
    zstring result;
    result.data = malloc(lenOfStr(str));

    if(result.data == NULL){
        printf("Could not allocate memory for the new ZString. Quitting.\n");
        exit(1);
    }

    size_t i = 0;
    while(!isaTerminator(str[i])){
        result.data[i] = str[i];
        i++;
    }
    result.data[i] = '\0';
    result.length = lenOfStr(result.data);
    return result;
}

zstring printz(const char* str, ...){
    zstring result = newZString(str);
    va_list args;
    va_start(args, str);
    int n = vsnprintf(result.data, sizeof(result.data) * result.length, str, args);
    va_end(args);
    result.length = lenOfStr(result.data);
    printf("String: '%s' of len %zu\n\n" , result.data, result.length);
    result.length = lenOfStr(result.data);
    return result;
}

zstring toLowercaseStr(zstring str){
    size_t i = 0; 
    zstring lstr = newZString(str.data);
    while(!isaTerminator(str.data[i])){
        if(str.data[i] >= 'A' && str.data[i] <= 'Z' && !isaSpace(str.data[i]) && !isaNumber(str.data[i]) && !isaNewLine(str.data[i])){
            lstr.data[i] = str.data[i] + 32;
        }else{
            lstr.data[i] = str.data[i];
        }
        i++;
    }
    lstr.data[i] = '\0';
    lstr.length = lenOfStr(lstr.data);
    return lstr;
}

zstring toUppercaseStr(zstring str){
    size_t i = 0; 
    zstring ustr = newZString(str.data);
    while(!isaTerminator(str.data[i])){
        if(str.data[i] >= 'A' && str.data[i] <= 'Z'){
            ustr.data[i] = str.data[i] + 32;
        }else {
            ustr.data[i] = str.data[i];
        }
        i++;
    }
    ustr.data[i] = '\0';
    return ustr;
}

zstring trimStr(zstring str){
    zstring result = newZString(str.data);
    size_t i = 0; 
    size_t j = 0; 
    while(!isaTerminator(str.data[i])){
        if(isaSpace(str.data[i])){
            i++;
        }
        result.data[j++] = str.data[i];
        i++;
    }
    result.data[j] = '\0';
    result.length = lenOfStr(result.data);
    return result;
}

zstring removeWord(zstring str, char* word){
    size_t i = 0; int j = 0;
    zstring result = newZString(str.data);
    while(!isaTerminator(str.data[i])){
        if(str.data[i] == word[0]){
            if(isWordInString(str, word, i)){
                i += lenOfStr(word);
            }
        }
        result.data[j] = str.data[i];
        i++;
        j++;
    }
    result.data[j] = '\0';
    result.length = lenOfStr(result.data);
    return result;
}

zstring removeChar(zstring str, char c){
    zstring result = newZString(str.data);
    size_t i = 0; 
    size_t j = 0; 
    while(!isaTerminator(str.data[i])){
        if(str.data[i] != c){
            result.data[j++] = str.data[i];
        }
        i++;
    }
    result.data[j] = '\0';
    result.length = lenOfStr(result.data);
    return result;
}

zstring copyStr(zstring str){
    zstring result = newZString(str.data);
    result.length = lenOfStr(result.data);
    return result;
}

zstring reverseStr(zstring str){
    size_t i = 0;
    zstring result = newZString(str.data);
    while(!isaTerminator(str.data[i])){
        result.data[i] = str.data[str.length - i - 1];
        i++;
    }
    result.data[i] = '\0';
    result.length = lenOfStr(result.data);
    return result;
}

zstring concatenateStr(zstring str1, zstring str2){
    zstring result = newZString(str1.data);
    result.length = str1.length + str2.length;
    size_t i = 0; 
    size_t j = 0;
    while(!isaTerminator(str1.data[i])){
        result.data[i] = str1.data[i];
        i++;
    }
    while(!isaTerminator(str2.data[j])){
        result.data[i] = str2.data[j];
        i++;
        j++;
    }
    result.data[i] = '\0';
    return result;
}

#endif // ZSTRING_IMPLEMENTATION