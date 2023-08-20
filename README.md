# zString 
Simple and beginner-friendly header-only string library useful for the ones who have just started learning C language or for those that want to use an essential string library for their projects.

## How-To
Just add the zstring.h file to your project's headers and the include and define its IMPLEMENTATION 

```c

#define ZSTRING_IMPLEMENTATION
#include "zstring.h"

```

## Test and functionalities 

```c

cd bin
make 
./zstring <string> <function to test>

```

* Trim a string

```c

./zstring <string> -tr 

```

* Convert all characters to all lowecases

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

./zstring <string> -rws <wordToRemove> // Case-Sensitive
./zstring <string> -rwi <wordToRemove> // Case-Insensitive

```

* Remove every occurences of a character inside of a string

```c

./zstring <string> -rcs <charToRemove> // Case-Sensitive
./zstring <string> -rci <charToRemove> // Case-Insensitive

```

* Compare two strings (Case-Sensitive and Case-Insensitive)

```c

./zstring <string1> -cms <string2> // Case-Sensitive
./zstring <string1> -cmi <string2> // Case-Insensitive

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

./zstring <string> -os <charToFind> // Case-Sensitive
./zstring <string> -oi <charToFind> // Case-Insensitive

```


 
