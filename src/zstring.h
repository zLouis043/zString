#ifndef ZSTRING_H_
#define ZSTRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct zstring{
    char *data;
    size_t length;
}zstring;

typedef enum{
    False = 0,
    True
}Bool;


size_t  lenOfStr(const char* str);
size_t  findOccuranceOf(zstring str, char toFind);
size_t  findStartOfWord(zstring str, char* word);
char toLowerCase(char c);
char toupperCase(char c);
Bool isaDigit(char c);
Bool isaNumber(char c);
Bool isaSpace(char c);
Bool isaSymbol(char c);
Bool isWordInString(zstring str, char* word, int start);
Bool compareString(zstring str1, zstring str2);
zstring newZString(const char* str);
zstring toLowercaseStr(zstring str);
zstring toUppercaseStr(zstring str);
zstring trimStr(zstring str);
zstring removeWord(zstring str, char* word);
zstring removeChar(zstring str, char c);
zstring copyStr(zstring str);
zstring reverseStr(zstring str);

#endif // ZSTRING_H_

#ifndef ZSTRING_IMPLEMENTATION

size_t  lenOfStr(const char* str){
    size_t  len = 0;
    while(str[len] != '\0'){
        len++;
    }
    return len;
}

size_t  findOccuranceOf(zstring str, char toFind){
    size_t  occurences = 0;
    size_t  i = 0;
    printf("String to Lower : '%s'\n", toLowercaseStr(str).data);
    while(toLowercaseStr(str).data[i] != '\0'){
        if(toLowercaseStr(str).data[i] == toLowerCase(toFind)){
            occurences++;
        }
        i++;
    }
    return occurences;
}

size_t  findStartOfWord(zstring str, char* word){
    size_t  i = 0; 
    zstring result = newZString("");
    while(str.data[i] != '\0'){
        if(str.data[i] == word[0]){
            if(isWordInString(str, word, i)){
                return i;
            }
        }
        i++;
    }
    return False; //if it does not find the word in the string it returns False
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

Bool isWordInString(zstring str, char* word, int start){
    size_t  i = 0; size_t  j = 1;
    while(word[j] != '\0'){
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

    size_t  i = 0; 
    while(str1.data[i] != '\0'){
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
    size_t  i = 0;
    while(str[i]  != '\0'){
        result.data[i] = str[i];
        i++;
    }
    result.data[i] = '\0';
    return result;
}

zstring toLowercaseStr(zstring str){
    size_t  i = 0; 
    zstring lstr = newZString("");
    while(str.data[i] != '\0'){
        if(str.data[i] >= 'A' && str.data[i] <= 'Z'){
            lstr.data[i] = str.data[i] + 32;
        }else {
            lstr.data[i] = str.data[i];
        }
        i++;
    }
    lstr.data[i] = '\0';
    return lstr;
}

zstring toUppercaseStr(zstring str){
    size_t  i = 0; 
    zstring ustr = newZString("");
    while(str.data[i] != '\0'){
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
    zstring result = newZString("");
    size_t  i = 0; 
    size_t  j = 0; 
    while(str.data[i] != '\0'){
        if(!isaSpace(str.data[i])){
            result.data[j++] = str.data[i];
        }
        i++;
    }
    result.data[j] = '\0';
    result.length = lenOfStr(result.data);
    return result;
}

zstring removeWord(zstring str, char* word){
    size_t  i = 0; int j = 0;
    zstring result = newZString("");
    while(str.data[i] != '\0'){
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
    zstring result = newZString("");
    size_t  i = 0; 
    size_t  j = 0; 
    while(str.data[i] != '\0'){
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
    zstring result = newZString("");
    while(str.data[i] != '\0'){
        result.data[i] = str.data[str.length - i - 1];
        i++;
    }
    result.data[i] = '\0';
    result.length = lenOfStr(result.data);
    return result;
}

#endif // ZSTRING_IMPLEMENTATION