/*
MIT License

Copyright (c) 2017 

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

#include <iostream>
#include "LFSR.h"

using namespace std;

// This example is going to calculate the length of a register

int main(int argc, char **argv)
{
    // Create a 24 bits register, by default all bits are set to 0
    LFSR lfsr(24);
    
    // Set the first bit to 1
    lfsr.setBit(0, true);

    // Save the register
    uint32_t * output;
    lfsr.save(output);

    // Counter to count the size of the register
    uint64_t counter = 0;
    
    // Iterate while the output's value is different from the initial state
    do
    {
        lfsr.rightShift(lfsr.getFirstBit() xor lfsr.getBit(1) xor lfsr.getBit(4));
        counter++;
    }
    while(!lfsr.compare(output));

    cout << "counter = " << counter << endl;

    delete [] output;
    
    return (0);
}
