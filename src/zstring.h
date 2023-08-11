#ifndef ZSTRING_H_
#define ZSTRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>

//Struct that contains the main components of the string  

typedef struct zstring{
    char *data;         // Data contained in the string 
    size_t length;      // Length of the string
}zstring;

typedef enum{
    False = 0,
    True
}Bool;

void freeZString(zstring str);
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
zstring sub_str(zstring str,int start, int end);

zstring removeChar(zstring str, char c);
zstring copyStr(zstring str);
zstring reverseStr(zstring str);
zstring concatenateStr(zstring str1, zstring str2);

#endif // ZSTRING_H_

#ifdef ZSTRING_IMPLEMENTATION

//TODO: improve this function
void freeZString(zstring str){
    if(str.data == NULL) return;
    str.length = 0;
    free(str.data);

}

/*
This function returns the number of characters inside of a string 
*/
size_t lenOfStr(const char* str){
    size_t len = 0;
    
    if(str == "") return 0;

    while(!isaTerminator(str[len])){ //While loop until str[len] == '\0' => isaTerminator(str[len)
        len++;
    }
    return len;
}

/*
This function returns the number of occurances of a specific character inside of a string 
*/
size_t findOccuranceOf(zstring str, char toFind){
    size_t occurences = 0;
    size_t i = 0;
    zstring toLowCase = toLowercaseStr(str);    // Convert the string and the word 
                                                // to all lowercases to allow 
                                                // the function to find every occurrences 
                                                // whenever the word is Upper/Lower-case
    while(!isaTerminator(toLowCase.data[i])){   
        if(toLowCase.data[i] == toLowerCase(toFind)){
            occurences++;
        }
        i++;
    }
    return occurences;
}

/*
This function returns the index of whee a word occurs within a string
*/
size_t findStartOfWord(zstring str, char* word){
    size_t i = 0; 
    while(!isaTerminator(str.data[i])){
        if(str.data[i] == word[0]){ // Found the  start of a word
            if(isWordInString(str, word, i)){ // Check if the word is actually in the string 
                return i; //if yes returns the index of the start 
            }
        }
        i++;
    }
    return False; //if it does not find the word in the string it returns False
}

/*
This function the number of word inside of a string 
*/
size_t numberOfWords(zstring str){
    size_t i = 0; size_t n = 0;

    if(!isaSpace(str.data[0])){
        n++;                        // Check if initially we find a word or a space 
    }

    while(!isaTerminator(str.data[i])){
        while(isaSpace(str.data[i])){
            i++;                    // Scroll through the string while there are spaces 
        }
        if(!isaSpace(str.data[i]) && isaSpace(str.data[i+1])){
            n++;                    // If the next character is not a space then we have found a word
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

/*
Checks if a word is contained in the string or not 
*/
Bool isWordInString(zstring str, char* word, int start){
    size_t i = 0; size_t  j = 1;
    while(!isaTerminator(word[j])){
        if(word[j] != str.data[start+i+1]){ // if there is even a single character different from the word we have not found it 
            return False;
        }
        j++;
        i++; 
    }
    return True;
}
/*
Check if two strings are equal 
*/
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
/*
Create a new string with its data and its length 
*/
zstring newZString(const char* str){
    zstring result;
    result.data = malloc(lenOfStr(str) +1);    //allocate memory for the string

    if(result.data == NULL){    // checks if the malloc failed 
        printf("Could not allocate memory for the new ZString. Quitting.\n");
        exit(1);
    }

    size_t i = 0;
    while(!isaTerminator(str[i])){
        result.data[i] = str[i];        // fills the data inside the string 
        i++;
    }
    result.data[i] = '\0';
    result.length = lenOfStr(result.data); // calculate the length of the string 
    return result;
}

/*
Create and print a new string that contains all the arguments defined in itself 
*/
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
            lstr.data[i] = str.data[i] + 32; // shift the character to an upper case character to a lower one 
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
    zstring lstr = newZString(str.data);
    while(!isaTerminator(str.data[i])){
        if(str.data[i] >= 'a' && str.data[i] <= 'z' && !isaSpace(str.data[i]) && !isaNumber(str.data[i]) && !isaNewLine(str.data[i])){
            lstr.data[i] = str.data[i] - 32; // shift the character to an upper case character to a lower one 
        }else{
            lstr.data[i] = str.data[i];
        }
        i++;
    }
    lstr.data[i] = '\0';
    lstr.length = lenOfStr(lstr.data);
    return lstr;
}
/*
This function returns the string without any spaces 
*/
zstring trimStr(zstring str){
    zstring result = newZString(str.data);
    size_t i = 0; 
    size_t j = 0; 
    while(!isaTerminator(str.data[i])){
        if(isaSpace(str.data[i])){
            i++;                // scroll the string while the are spaces 
        }
        result.data[j++] = str.data[i]; // copy every character to result string that is not a space 
        i++;
    }
    result.data[j] = '\0';
    result.length = lenOfStr(result.data);
    return result;
}

/*
Remove a word from a string
*/
zstring sub_str(zstring str,int start, int end){
    zstring  new_string = {0};
    new_string.data = malloc((end - start) + 1);
    new_string.length = end - start;
    int position = 0;
    for(int i = start; i < end; i++){
        new_string.data[position] = str.data[i];
        position+=1;
    }
    new_string.data[position] = '\0';
    return new_string;

}

zstring removeWord(zstring str, char* word){
    size_t i = 0; int j = 0;
    zstring result = newZString(str.data);
    zstring base = newZString(word);

    while(!isaTerminator(str.data[i])){
        

        //making the comparation
        if((i + base.length) < str.length){
            zstring possible = sub_str(str,i,i+base.length);
            if(compareString(possible,base)){
                i+=base.length;
                freeZString(possible);
                continue;
            }
            freeZString(possible);
        }

        result.data[j] = str.data[i]; // copy every character of the string except the word we do not want 
        i++;
        j++;
    }
    result.data[j] = '\0';
    result.length = lenOfStr(result.data);
    freeZString(base);
    return result;
}

/*
Remove every occurances of a specific character inside the string 
*/
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

/*
Returns the reversed string 
*/
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

/*
Concatenates two string 
*/
zstring concatenateStr(zstring str1, zstring str2){
    zstring result = newZString(str1.data);
    result.length = str1.length + str2.length;
    result.data = realloc(result.data,result.length +1);

    size_t i = 0; 
    size_t j = str1.length;
  
    while(!isaTerminator(str2.data[i])){
        result.data[j] = str2.data[i];      //and then copy the second part of the string with the second one 
        i++;
        j++;
    }

    result.data[j] = '\0';
    return result;
}

#endif // ZSTRING_IMPLEMENTATION