# LFSR
An efficient linear feedback shift register (LFSR) class written in C++

# How to use this library ?

Copy **LFSR.c** and **LFSR.h** to your project and import the library on your code :
```cpp
#include "LFSR.h"
```

To create an LFSR : (by default all bits are set to 0. Here a 15 bits LFSR is created)
```cpp
LFSR lfsr(15);
```

To initialize the LFSR, the first bit is set to 1
```cpp
lfsr.setBit(0, true);
```

To perform a right shift with X0 xor X1 as feedback (X15 + X14 + 1 in polynomial notation)
```cpp
lfsr.rightShift(lfsr.getFirstBit() xor lfsr.getBit(1) xor lfsr.getBit(4));
```

Display first 8-bit of the LFSR :
```cpp
lfsr.get8bit()
```

# All functionalities explained :

Get the size in bit of the register :
```cpp
uint32_t getSize();
```

Get the raw value of the 
```cpp
uint32_t getArrayElement(uint32_t bitPosition);
```

Get the size of internal 32-bit array used for the register
```cpp
uint32_t getArraySize();
```

Perform a right shift
```cpp
void rightShift(bool last);
```

Perform a left shift
```cpp
void leftShift(bool first);
```

Get first 8-bit 
```cpp
uint8_t get8bit();
```

Get first 16-bit
```cpp
uint16_t get16bit();
```

Get first 32-bit
```cpp
uint32_t get32bit();
```

Get the value at a specific position in the internal 32-bit array used for the register
```cpp
uint32_t get32bitArray(uint32_t position);
```

Get a specific bit :
```cpp
bool getBit(uint32_t bitPosition);
```

Get the first bit (equivalent to getBit(0) :
```cpp
bool getFirstBit();
```

Get the last bit :
```cpp
bool getLastBit();
```

Set a specific bit
```cpp
void setBit(uint32_t bitPosition, bool value);
```

Set the first bit (equivalent to setBit(0, value))
```cpp
void setFirstBit(bool value);
```

Set the last bit
```cpp
void setLastBit(bool value);
```

Save the content of the register to a buffer
```cpp
void save(uint32_t * &output);
```

Compare the register to a saved register
```cpp
bool compare(uint32_t * &output);
```

Restaure the register with a saved register 
```cpp
void set(uint32_t * &output);
```

## Examples 

The example calculates the length cycle of a 15 bits register with X15 + X14 + 1 as feedback

To build the sample : 
```
g++ -std=c++11 LFSR.cpp main.cpp -o lfsr
```

Output of the sample is : 
```
counter = 32767
```
