# easyRandom
### A small single-function UNIX/LINUX C library that can be used to generate random numbers without the need to work with the random(3) and srandom(3) function
___

## Impementation

1. Download the folder called easyRand
2. Paste it into your program's folder 
3. In your C file include the header file

```C
#include "./easyRand/easyRand.h"
```

## Contents

The library includes only a single function `easyrandom` with three arguments

```C
long int easyrandom(long int minimumnumber, long int maximumnumber, bool verbose);
```

1. minimumnumber is the minumum number in the range of possible number generated
2. maximumnumber is the maximum number in the range of possible number generated
3. verbose is a parameter that if set to `true` will let the function print it's results to the termiinal
4. The function reurn a `long int` whilch is the generated random number

## example

```C
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "./easyRand/easyRand.h" //inclusion of this library

int main() {

    long int randomnum = easyrandom(0, 100, true); //this line stores the function's return value to a variable and also prints the generated value and the cycles taken by it to calculate the number, by setting the verbose arg to true
    printf("\nStored variable value %ld", randomnum);

    return 0;
}
```

Output:
```
The generator returned 92 after 115563572 cycles
Stored variable value 92
```
