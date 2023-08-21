/*
MIT License

Copyright (c) 2023 zLouis043

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef ZSTRING_H_
#define ZSTRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

//Struct that contains the main components of the string  

typedef struct zstring{
    char *data;         // Data contained in the string 
    size_t length;      // Length of the string
}zstring;

/*  
    This function frees the zstring and sets its length to 0.
    @param str The string that need to be freed. 
*/
void freeZString(zstring str);

/* 
    This function copies the str1 to str2.
    @param str1 The source string.
    @param str2 The destination string. 
*/
void copyStr(zstring str1, zstring str2);

/* 
    This function returns the number of occurances of a specific character inside of a string (Case-Sensitive).
    @param str The string that will be searched into.
    @param toFind The character that will be searched into the string.
    @result The number of occurrences of the character.
*/
size_t findOccuranceOf(zstring str, char toFind);

/* 
    This function returns the number of occurances of a specific character inside of a string (Case-Insensitive).
    @param str The string that will be searched into.
    @param toFind The character that will be searched into the string.
    @result The number of occurrences of the character. 
*/
size_t findOccuranceOfCI(zstring str, char toFind);

/* 
    This function returns the index of where a word occurs within a string.
    @param str The string that will be searched into.
    @param word The word that will be searched.
    @result The index of where the word is in the string.  
*/
size_t findStartOfWord(zstring str, const char* word);

/* 
    This function the number of word inside of a string.
    @param str The string where the words will be counted.
    @result The number of words inside the string. 
*/
size_t numberOfWords(zstring str);

/*
    Convert the current character to a lowercase one. 
    @param c The character to be converted.
    @result The converted lowercase character.
*/
char toLowerCase(char c);

/*
    Convert the current character to a uppercase one. 
    @param c The character to be converted.
    @result The converted uppercase character.
*/
char toUpperCase(char c);

/* 
    Check if the current character is an uppercase one.
    @param c The character to be checked.
    @result True if the character is an uppercase one or False if it is not.
*/
bool isUppercase(char c);

/* 
    Check if the current character is an lowercase one.
    @param c The character to be checked.
    @result True if the character is an lowercase one or False if it is not.
*/
bool isLowercase(char c);

/* 
    Check if the current character is a letter.
    @param c The character to be checked.
    @result True if the character is a letter or False if it is not.
*/
bool isLetter(char c);

/*
    Check if the current character is a number.
    @param c The character to be checked.
    @result True if the character is a number or False if it is not. 
*/
bool isNumber(char c);

/* 
    Check if the current character is a space.
    @param c The character to be checked.
    @result True if the character is a space or False if it is not. 
*/
bool isSpace(char c);

/*
    Check if the current character is a Special Symbol.
    @param c The character to be checked.
    @result True if the character is a Special Symbol or False if it is not.
*/
bool isSymbol(char c);

/*
    Check if the current character is a Null Terminator char ('\0').
    @param c The character to be checked.
    @result True if the character is a Null Terminator or False if it is not. 
*/
bool isNullTerminator(char c);

/* 
    Check if the current character is a new line char ('\n').
    @param c The character to be checked.
    @result True if the character is a New Line or False if it is not. 
*/
bool isNewLine(char c);

/*
    Check if the current string is a null one.
    @param str The string to be checked.
    @result True if the string is null or False if it is not. 
*/
bool isStringNull(zstring str);

/*
    Checks if a word is contained in the string or not.
    @param str The string to be checked.
    @param word The word that will be searched in the string.
    @param start The index where the search will start.
    @result True if the word is contained in the string False if it is not.
*/
bool isWordInString(zstring str, const char* word, int start);

/*
    Check if two strings are equal (Note: this is a case-sensitive function).
    @param str1 The first string that will be compared with the other string. 
    @param str2 The second string that will be compared with the other string. 
    @result True if the strings are equal False if they are not. 
*/
bool compareString(zstring str1, zstring str2);

/* Check if two strings are equal (Note: this is a case-insensitive function) */
bool compareStringCI(zstring str1, zstring str2);

/* Create an empty zstring */
zstring newZNullString();

/* Create a new zstring with its data and its length */
zstring newZString(const char* str);

/* Create and print a new string that contains all the arguments defined in itself */
zstring printz(size_t addedSize, const char* str, ...);

/* Convert all the string to lowercases */
zstring toLowercaseStr(zstring str);

/* Convert all the string to uppercases */
zstring toUppercaseStr(zstring str);

/* This function returns the string without any spaces */
zstring trimStr(zstring str);

/* Remove a word from a string (Case-Sensitive) */
zstring removeWord(zstring str, const char* word);

/* Remove a word from a string (Case-Insensitive) */
zstring removeWordCI(zstring str, const char* word);

/* Remove every occurances of a specific character inside the string (Case-Sensitive) */
zstring removeChar(zstring str, char c);

/* Remove every occurances of a specific character inside the string (Case-Insensitive) */
zstring removeCharCI(zstring str, char c);

/* Gets a substring from a specific location in the string */
zstring subStr(zstring str,int start, int end);

/* Returns the reversed string */
zstring reverseStr(zstring str);

/* Concatenates two string */
zstring concatenateStr(zstring str1, zstring str2);

/* Chop the string from the left by a specified size */
zstring chopLeftBySize(zstring str, size_t size);

/* Chop the string from the left by a specified size */
zstring chopRightBySize(zstring str, size_t size);

/* Chop the string from the left by a specified number of words*/
zstring chopLeftByWordsNumb(zstring str, size_t numOfWords);

/* Chop the string from the right by a specified number of words*/
zstring chopRightByWordsNumb(zstring str, size_t numOfWords);

#endif // ZSTRING_H_

#ifdef ZSTRING_IMPLEMENTATION

/* Free the string and sets its length to 0 */
void freeZString(zstring str){
    if(isStringNull(str)) return;
    str.length = 0;
    free(str.data);
}

/* Copy a string to another */
void copyStr(zstring str1, zstring str2){
    if(isStringNull(str1)) return;
    strcpy(str2.data, str1.data);
    str2.length = str1.length;
}

/* This function returns the number of occurances of a specific character inside of a string (Case-sensitive) */
size_t findOccuranceOf(zstring str, char toFind){

    if(isStringNull(str)){
        fprintf(stderr, "Error! String is null\n");
        exit(1);
    }

    size_t occurences = 0;
    size_t i = 0;
    while(!isNullTerminator(str.data[i])){   
        if(str.data[i] == toFind){
            occurences++;
        }
        i++;
    }
    return occurences;
}

/* This function returns the number of occurances of a specific character inside of a string (Case-insensitive)*/
size_t findOccuranceOfCI(zstring str, char toFind){

    if(isStringNull(str)){
        fprintf(stderr, "Error! String is null\n");
        exit(1);
    }

    size_t occurences = 0;
    size_t i = 0;
    zstring toLowCase = toLowercaseStr(str);    // Convert the string and the word 
                                                // to all lowercases to allow 
                                                // the function to find every occurrences 
                                                // whenever the word is Upper/Lower-case
    while(!isNullTerminator(toLowCase.data[i])){   
        if(toLowCase.data[i] == toLowerCase(toFind)){
            occurences++; 
        }
        i++;
    }
    freeZString(toLowCase);
    return occurences;
}

/* This function returns the index of where a word occurs within a string */
size_t findStartOfWord(zstring str, const char* word){

    if(isStringNull(str)){
        fprintf(stderr, "Error! String is null\n");
        exit(1);
    }

    size_t i = 0; 
    while(!isNullTerminator(str.data[i])){
        if(str.data[i] == word[0]){ // Found the  start of a word
            if(isWordInString(str, word, i)){ // Check if the word is actually in the string 
                return i; //if yes returns the index of the start 
            }
        }
        i++;
    }
    return false; //if it does not find the word in the string it returns False
}

/* This function the number of word inside of a string */
size_t numberOfWords(zstring str){

    if(isStringNull(str)){
        fprintf(stderr, "Error! String is null\n");
        exit(1);
    }

    size_t i = 0; size_t n = 0;

    if(!isSpace(str.data[0])){
        n++;                        // Check if initially we find a word or a space 
    }

    while(!isNullTerminator(str.data[i])){
        while(isSpace(str.data[i])){
            i++;                    // Scroll through the string while there are spaces 
        }
        if(i > str.length -1){
            break;
        }
        if(!isSpace(str.data[i]) && isSpace(str.data[i+1])){
            n++;                    // If the next character is not a space then we have found a word
        }
        i++;
    }
    return n;
}

/* Convert the current character to a lowercase one */
char toLowerCase(char c){
    if(isUppercase(c)){
        c += 32;
    }
    return c;
}

/* Convert the current character to an uppercase one */
char toUpperCase(char c){
    if(isLowercase(c)){
        c -= 32;
    }
    return c;
}

/* Check if the current character is an uppercase one*/
bool isUppercase(char c){
    return (c >= 'A' && c <= 'Z');
}

/* Check if the current character is an lowercase one*/
bool isLowercase(char c){
    return (c >= 'a' && c <= 'z');
}

/* Check if the current character is a letter */
bool isLetter(char c){
    return (isLowercase(c) || isUppercase(c));
}

/* Check if the current character is a number */
bool isNumber(char c){
    return (c >= '1' && c <= '9');
}

/* Check if the current character is a space */
bool isSpace(char c){
    return (c == ' ');
}

/* Check if the current character is a Special Symbol */
bool isSymbol(char c){
    return (!isLetter(c) && !isNumber(c) && !isSpace(c));
}

/* Check if the current character is a Null Terminator char ('\0')*/
bool isNullTerminator(char c){
    return (c == '\0');
}

/* Check if the current character is a new line char ('\n') */
bool isNewLine(char c){
    return (c == '\n');
}

/* Check if the current string is a null one*/
bool isStringNull(zstring str){
    return (str.data == NULL || str.length == 0);
}

/* Checks if a word is contained in the string or not */
bool isWordInString(zstring str, const char* word, int start){

    if(isStringNull(str)){
        fprintf(stderr, "Error! String is null\n");
        exit(1);
    }

    size_t i = 0; size_t  j = 1;
    while(!isNullTerminator(word[j])){
        if(word[j] != str.data[start+i+1]){ // if there is even a single character different from the word we have not found it 
            return false;
        }
        j++;
        i++; 
    }
    return true;
}

/* Check if two strings are equal (Note: this is a case-sensitive function) */
bool compareString(zstring str1, zstring str2){

    if(isStringNull(str1) || isStringNull(str2)){
        fprintf(stderr, "Error! One of the strings is null\n");
        exit(1);
    }

    if(str1.length != str2.length){
        return false;
    }

    size_t i = 0; 
    while(!isNullTerminator(str1.data[i])){
        if(str1.data[i] != str2.data[i]){
            return false;
        }
        i++;
    }

    return true;
}

/* Check if two strings are equal (Note: this is a case-insensitive function) */
bool compareStringCI(zstring str1, zstring str2){

    if(isStringNull(str1) || isStringNull(str2)){
        fprintf(stderr, "Error! One of the strings is null\n");
        exit(1);
    }

    if(str1.length != str2.length){
        return false;
    }
    
    zstring l_str1 = toLowercaseStr(str1);
    zstring l_str2 = toLowercaseStr(str2);

    size_t i = 0; 
    while(!isNullTerminator(l_str1.data[i])){
        if(l_str1.data[i] != l_str2.data[i]){
            return false;
        }
        i++;
    }

    freeZString(l_str1);
    freeZString(l_str2);

    return true;
}

/* Create an empty zstring */
zstring newZNullString(){
    zstring result;
    result.data = '\0';
    result.length = 0;
    return result;
}

/* Create a new zstring with its data and its length */
zstring newZString(const char* str){
    zstring result;
    result.data = malloc(strlen(str) + 1);    //allocate memory for the string

    if(result.data == NULL){    // checks if the malloc failed 
        fprintf(stderr, "Could not allocate memory for the new ZString. Quitting.\n");
        exit(1);
    }

    strcpy(result.data, str);
    result.length = strlen(result.data); // calculate the length of the string 
    result.data[result.length] = '\0';
    return result;
}

/* Create and print a new string that contains all the arguments defined in itself */
zstring printz(size_t addedSize, const char* str, ...){
    zstring result = newZString(str);
    va_list args;
    va_start(args, str);
    result.data = realloc(result.data,result.length + addedSize);
    int n = vsnprintf(result.data, sizeof(char *) * result.length, str, args);
    va_end(args);
    result.length = strlen(result.data);
    printf("String: '%s' of len %zu\n\n" , result.data, result.length);
    return result;
}

/* Convert all the string to lowercases */
zstring toLowercaseStr(zstring str){

    if(isStringNull(str)){
        fprintf(stderr, "Error! String is null\n");
        exit(1);
    }

    size_t i = 0; 
    zstring lstr = newZString(str.data);
    while(!isNullTerminator(str.data[i])){
        if(isUppercase(str.data[i]) && !isSpace(str.data[i]) && !isNumber(str.data[i]) && !isNewLine(str.data[i])){
            lstr.data[i] = toLowerCase(str.data[i]); // shift the character to an upper case character to a lower one 
        }else{
            lstr.data[i] = str.data[i];
        }
        i++;
    }
    lstr.data[i] = '\0';
    lstr.length = strlen(lstr.data);
    return lstr;
}

/* Convert all the string to uppercases */
zstring toUppercaseStr(zstring str){

    if(isStringNull(str)){
        fprintf(stderr, "Error! String is null\n");
        exit(1);
    }

    size_t i = 0; 
    zstring ustr = newZString(str.data);
    while(!isNullTerminator(str.data[i])){
        if(isLowercase(str.data[i]) && !isSpace(str.data[i]) && !isNumber(str.data[i]) && !isNewLine(str.data[i])){
            ustr.data[i] = toUpperCase(str.data[i]); // shift the character to an lower case character to a upper one 
        }else {
            ustr.data[i] = str.data[i];
        }
        i++;
    }
    ustr.data[i] = '\0';
    ustr.length = strlen(ustr.data);
    return ustr;
}
/* This function returns the string without any spaces */
zstring trimStr(zstring str){

    if(isStringNull(str)){
        fprintf(stderr, "Error! String is null\n");
        exit(1);
    }

    zstring result = newZString(str.data);
    size_t i = 0; 
    size_t j = 0; 
    while(!isNullTerminator(str.data[i])){
        if(isSpace(str.data[i])){
            i++;                // scroll the string while the are spaces 
        }
        result.data[j++] = str.data[i]; // copy every character to result string that is not a space 
        i++;
    }
    result.data[j] = '\0';
    result.length = strlen(result.data);
    return result;
}

/* Remove a word from a string (Case-Sensitive) */
zstring removeWord(zstring str, const char* word){

    if(isStringNull(str)){
        fprintf(stderr, "Error! String is null\n");
        exit(1);
    }

    size_t i = 0; int j = 0;
    zstring result = newZString(str.data);
    while(!isNullTerminator(str.data[i])){
        if(str.data[i] == word[0]){ // find the beginning of the word 
            if(isWordInString(str, word, i)){   // check if it is actually the word that we are searching 
                i += strlen(word);    // shift the index of the string after the removed word 
            }
        }
        result.data[j] = str.data[i]; // copy every character of the string except the word we do not want 
        i++;
        j++;
    }
    result.data[j] = '\0';
    result.length = strlen(result.data);
    return result;
}

/* Remove a word from a string (Case-Insensitive) */
zstring removeWordCI(zstring str, const char* word){

    if(isStringNull(str)){
        fprintf(stderr, "Error! String is null\n");
        exit(1);
    }

    size_t i = 0; int j = 0;
    zstring result = newZString(str.data);
    zstring l_str = toLowercaseStr(str);
    zstring l_word = toLowercaseStr(newZString(word));
    while(!isNullTerminator(l_str.data[i])){
        if(l_str.data[i] == l_word.data[0]){ // find the beginning of the word 
            if(isWordInString(l_str, l_word.data, i)){   // check if it is actually the word that we are searching 
                i += strlen(l_word.data);    // shift the index of the string after the removed word 
            }
        }
        result.data[j] = str.data[i]; // copy every character of the string except the word we do not want 
        i++;
        j++;
    }
    result.data[j] = '\0';
    result.length = strlen(result.data);
    freeZString(l_word);
    return result;
}

/* Remove every occurances of a specific character inside the string (Case-Sensitive) */
zstring removeChar(zstring str, char c){

    if(isStringNull(str)){
        fprintf(stderr, "Error! String is null\n");
        exit(1);
    }

    zstring result = newZString(str.data);
    size_t i = 0; 
    size_t j = 0; 
    while(!isNullTerminator(str.data[i])){
        if(str.data[i] != c){
            result.data[j++] = str.data[i]; 
        }
        i++;
    }
    result.data[j] = '\0';
    result.length = strlen(result.data);
    return result;
}


/* Remove every occurances of a specific character inside the string (Case-Insensitive) */
zstring removeCharCI(zstring str, char c){

    if(isStringNull(str)){
        fprintf(stderr, "Error! String is null\n");
        exit(1);
    }

    zstring result = newZString(str.data);
    size_t i = 0; 
    size_t j = 0; 
    zstring l_str = toLowercaseStr(str);
    while(!isNullTerminator(l_str.data[i])){
        if(l_str.data[i] != toLowerCase(c)){
            result.data[j++] = str.data[i]; 
        }
        i++;
    }
    result.data[j] = '\0';
    result.length = strlen(result.data);
    freeZString(l_str);
    return result;
}

/* Gets a substring from a specific location in the string */
zstring subStr(zstring str,int start, int end){

    if(isStringNull(str)){
        fprintf(stderr, "Error! String is null\n");
        exit(1);
    }

    zstring result = newZString("");
    result.data = malloc((end - start) + 1);
    result.length = end - start;
    size_t j = 0;
    for(int i = start; i < end; i++){
        result.data[j] = str.data[i];
        j++;
    }
    result.data[j] = '\0';
    return result;

}

/* Returns the reversed string */
zstring reverseStr(zstring str){

    if(isStringNull(str)){
        fprintf(stderr, "Error! String is null\n");
        exit(1);
    }

    size_t i = 0;
    zstring result = newZString(str.data);
    while(!isNullTerminator(str.data[i])){
        result.data[i] = str.data[str.length - i - 1];
        i++;
    }
    result.data[i] = '\0';
    result.length = strlen(result.data);
    return result;
}

/* Concatenates two string */
zstring concatenateStr(zstring str1, zstring str2){

    if(isStringNull(str1) || isStringNull(str2)){
        fprintf(stderr, "Error! One of the strings is null\n");
        exit(1);
    }

    zstring result = newZString(str1.data); //copy the first part of the string with the first one
    result.length = str1.length + str2.length;
    result.data = realloc(result.data, result.length + 1);
    size_t i = 0; 
    size_t j = str1.length;

    while(!isNullTerminator(str2.data[i])){
        result.data[j] = str2.data[i];      //and then copy the second part of the string with the second one 
        i++;
        j++;
    }
    result.data[j] = '\0';
    return result;
}

/* Chop the string from the left by a specified size */
zstring chopLeftBySize(zstring str, size_t size){

    if(isStringNull(str)){
        fprintf(stderr, "Error! String is null\n");
        exit(1);
    }

    if(size > str.length){
        fprintf(stderr, "Error! Size requested is larger than string length\n");
        exit(1);
    }

    zstring result;
    result.data = malloc(str.length - size); 
    int i = size; int j = 0;
    while(!isNullTerminator(str.data[i])){
        result.data[j] = str.data[i];
        j++;
        i++;

    }
    result.data[j] = '\0';
    result.data = realloc(result.data, strlen(result.data));
    return result;
}

/* Chop the string from the right by a specified size */
zstring chopRightBySize(zstring str, size_t size){

    if(isStringNull(str)){
        fprintf(stderr, "Error! String is null\n");
        exit(1);
    }

    if(size > str.length){
        fprintf(stderr, "Error! Size requested is larger than string length\n");
        exit(1);
    }

    zstring result;
    result.data = malloc(str.length - size);
    int i = 0; 
    while(!isNullTerminator(str.data[i]) && i < str.length - size){ // copy the string until the requested size
        result.data[i] = str.data[i];
        i++;

    }
    result.data[i] = '\0';
    return result;
}

/* Chop the string from the left by a specified number of words*/
zstring chopLeftByWordsNumb(zstring str, size_t numOfWords){
    if(isStringNull(str)){
        fprintf(stderr, "Error! String is null\n");
        exit(1);
    }

    if(numOfWords > numberOfWords(str)){
        fprintf(stderr, "Error! Number of words requested is larger than the number of words contained in the string\n");
        exit(1);
    }

    zstring result;

    int i = 0; int j = 0; 

    while(numberOfWords(chopLeftBySize(str, i)) >= numberOfWords(str) - numOfWords) i++;    // Count the number of words contained 
                                                                                            // in the string and chops it fro the left
                                                                                            // until it removes the requested number
                                                                                            // of words

    result.data = malloc( str.length - i );

    while(!isNullTerminator(str.data[i])){
        result.data[j] = str.data[i];
        j++;
        i++;
    }

    result.data[j] = '\0';
    result.length = j;
    return result;
}

/* Chop the string from the right by a specified number of words*/
zstring chopRightByWordsNumb(zstring str, size_t numOfWords){
    if(isStringNull(str)){
        fprintf(stderr, "Error! String is null\n");
        exit(1);
    }

    if(numOfWords > numberOfWords(str)){
        fprintf(stderr, "Error! Number of words requested is larger than the number of words contained in the string\n");
        exit(1);
    }

    zstring result;

    int i = 0; int j = 0;            

    while(numberOfWords(chopRightBySize(str, i)) > numberOfWords(str) - numOfWords) i++;   // Count the number of words contained 
                                                                                            // in the string and chops it fro the left
                                                                                            // until it removes the requested number
                                                                                            // of words

    result.data = malloc( str.length - i );

    while(j < str.length - i){
        result.data[j] = str.data[j];
        j++;
    }

    result.data[j] = '\0';
    result.length = j;
    return result;
}

#endif // ZSTRING_IMPLEMENTATION