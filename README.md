# zString 
Simple and beginner-friendly header-only string library useful for the ones who have just started learning C language or for those that want to use an essential string library for their projects.

## How-To
Just add the zstring.h file to your project's headers and the include and define its IMPLEMENTATION 

```c

#define ZSTRING_IMPLEMENTATION
#include "zstring.h"

```

## Functionalities 

* Trim a string

```c

zstring str = newZString("Hello World");  // Create a base string 
trimmedString = trimStr(str);             // Trim the string 
printf("Trimmed: '%s' of len: %zu\n\n", trimmedString.data, trimmedString.length);

freeZString(trimmedString);               // Free the trimmed string
freeZString(str);                         // Free the base string 

Output > Trimmed: 'HelloWorld' of len: 10

```

* Compare two strings

```c

zstring str = newZString("Hello World");  // Create a base string 
bool areEqual = compareString(str, toLowercaseStr(str));  // Compare two strings 
printf("String 1 : '%s' and String 2: '%s' are equal? %s\n\n", str.data, toLowercaseStr(str).data, areEqual ? "True" : "False");

freeZString(str);                         // Free the base string 

Output > String 1 : 'Hello World' and String 2: 'hello world' are equal? False

```

* Remove a substring from another string

```c

zstring str = newZString("Hello World");  // Create a base string 
char toRemove[] = "Hello, World";

removedWordString  = removeWord(str, toRemove);
printf("Removed '%s' at index %zu to String: '%s' of len: %zu\n\n", toRemove, findStartOfWord(str, toRemove),removedWordString.data, removedWordString.length);

freeZString(removedWordString);           // Free the removed word string 
freeZString(str);                         // Free the base string 

Output > Removed 'Hello, World' at index 0 to String: 'Hello World' of len: 11

```

* Remove every occurences of a character inside of a string

```c

zstring str = newZString("Hello World");  // Create a base string 
char toFind = 'w';

removedCharString  = removeChar(str, toFind); // Created a removed Characters string 
printf("Removed '%c' to String: '%s' of len: %zu\n\n", toFind, removedCharString.data, removedCharString.length);
 
freeZString(removedCharString);           // Free the removed Characters string 
freeZString(str);                         // Free the base string 

Output > Removed 'w' to String: 'Hello World' of len: 11

```

* Reverse a string

```c

zstring str = newZString("Hello World");  // Create a base string 

reversedString = reverseStr(str);         // Create a reversed string 
printf("Reversed: '%s' of len %zu\n\n", reversedString.data, reversedString.length);

freeZString(reversedString);              // Free the reversed string 
freeZString(str);                         // Free the base string 

Output > Reversed: 'dlroW olleH' of len 11

```

* Concatenate two strings

```c

zstring str = newZString("Hello World");  // Create a base string 

concatenatedString = concatenateStr(str, reversedString);  // Concatenate two strings 
printf("Concatenated string: %s of len: %zu\n\n", concatenatedString.data, concatenatedString.length);

freeZString(reversedString);              // Free the reversed string 
freeZString(str);                         // Free the base string 
freeZString(concatenatedString);          // Free the concatenated string 

Output > Concatenated string: Hello WorlddlroW olleH of len: 22

```
 
