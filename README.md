# zString

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
![GitHub last commit (branch)](https://img.shields.io/github/last-commit/zLouis043/zString/main)
![GitHub top language](https://img.shields.io/github/languages/top/zLouis043/zString)

Simple and beginner-friendly header-only string library useful for the ones who have just started learning C language or for those that want to use an essential string library for their projects.

## How-To
Just add the zstring.h file to your project's headers and the include and define its IMPLEMENTATION 

```c

#define ZSTRING_IMPLEMENTATION
#include "zstring.h"

```

## Test and functionalities 

### How to setup the test file

```c

cd bin
make 
./zstring <string> <function to test>

```

### Functionalities 

* Trim a string

```c

./zstring <string> -tr 

```

* Convert all characters to all lowercases

```c

./zstring <string> -tl 

```

* Convert all characters to all uppercases

```c

./zstring <string> -tu 

```

* Reverse a string

```c

./zstring <string> -re 

```

* Remove a word from another string

```c

./zstring <string> -rw -s <wordToRemove> // Case-Sensitive
./zstring <string> -rw -i <wordToRemove> // Case-Insensitive

```

* Remove every occurences of a character inside of a string

```c

./zstring <string> -rc -s <charToRemove> // Case-Sensitive
./zstring <string> -rc -i <charToRemove> // Case-Insensitive

```

* Compare two strings (Case-Sensitive and Case-Insensitive)

```c

./zstring <string1> -cm -s <string2> // Case-Sensitive
./zstring <string1> -cm -i <string2> // Case-Insensitive

```

* Concatenate two strings

```c

./zstring <string1> -cc <string2> 

```

* Find the number of words in a string

```c

./zstring <string> -n

```

* Find the number of occurances of a characted in a string (Case-Sensitive and Case-Insensitive)

```c

./zstring <string> -o -s <charToFind> // Case-Sensitive
./zstring <string> -o -i <charToFind> // Case-Insensitive

```
* Chop a string from left or right and even by a specific size or a specific number of words

```c

./zstring <string> -cp -l -s <sizeToChop> // the flag -l indicates from left and the flag -s indicates by size 
./zstring <string> -cp -l -w <numOfWordsToChop> // the flag -l indicates from left and the flag -w by number of words

./zstring <string> -cp -r -s <sizeToChop> // the flag -l indicates from right and the flag -s indicates by size 
./zstring <string> -cp -r -w <numOfWordsToChop> // the flag -l indicates from right and the flag -w by number of words

```

* Convert a float to a rationalized String

```c

./zstring <float> -ra

``` 

### Note: It only works with ASCII characters right now. 


 
