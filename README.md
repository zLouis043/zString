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

zstring str = newZString("Hello World");
trimmedString = trimStr(str);
printf("Trimmed: '%s' of len: %zu\n\n", trimmedString.data, trimmedString.length);

freeZString(trimmedString);

Output > Trimmed: 'HelloWorld' of len: 10

```

* Compare two strings

```c

zstring str = newZString("Hello World");
bool areEqual = compareString(str, toLowercaseStr(str));
printf("String 1 : '%s' and String 2: '%s' are equal? %s\n\n", str.data, toLowercaseStr(str).data, areEqual ? "True" : "False");

Output > String 1 : 'Hello World' and String 2: 'hello world' are equal? False

```

* Remove a substring from another string

```c

zstring str = newZString("Hello World");
char toRemove[] = "Hello, World";

removedWordString  = removeWord(str, toRemove);
printf("Removed '%s' at index %zu to String: '%s' of len: %zu\n\n", toRemove, findStartOfWord(str, toRemove),removedWordString.data, removedWordString.length);

freeZString(removedWordString);

Output > Removed 'Hello, World' at index 0 to String: 'Hello World' of len: 11

```

* Remove every occurences of a character inside of a string

```c

zstring str = newZString("Hello World");
char toFind = 'w';

removedCharString  = removeChar(str, toFind);
printf("Removed '%c' to String: '%s' of len: %zu\n\n", toFind, removedCharString.data, removedCharString.length);

freeZString(removedCharString);

Output > Removed 'w' to String: 'Hello World' of len: 11

```

* Reverse a string

```c

zstring str = newZString("Hello World");

reversedString = reverseStr(str);
printf("Reversed: '%s' of len %zu\n\n", reversedString.data, reversedString.length);

freeZString(reversedString);

Output > Reversed: 'dlroW olleH' of len 11

```

* Concatenate two strings

```c

zstring str = newZString("Hello World");

concatenatedString = concatenateStr(str, reversedString);
printf("Concatenated string: %s of len: %zu\n\n", concatenatedString.data, concatenatedString.length);

freeZString(reversedString);
freeZString(concatenatedString);

Output > Concatenated string: Hello WorlddlroW olleH of len: 22

```
 
