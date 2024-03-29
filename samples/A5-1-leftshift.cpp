/*
MIT License

Copyright (c) 2017 https://github.com/nmrr

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

int main(int argc, char **argv)
{
    LFSR register1(19);
    LFSR register2(22);
    LFSR register3(23);
    
    register1.setBit(18, true);
    register2.setBit(21, true);
    register3.setBit(22, true);
    
    uint32_t result = 0;
    int counter = 0;

    for (uint32_t i=0; i < 1024; i++)
    {
        bool bitRegister1 = register1.getBit(8);
        bool bitRegister2 = register2.getBit(10);
        bool bitRegister3 = register3.getBit(10);
        
        if (bitRegister1 == bitRegister2 || bitRegister1 == bitRegister3)
        {
            register1.leftShift(register1.getBit(18) xor register1.getBit(17) xor register1.getBit(16) xor register1.getBit(13));
        }
        
        if (bitRegister2 == bitRegister1 || bitRegister2 == bitRegister3)
        {
            register2.leftShift(register2.getBit(21) xor register2.getBit(20));
        }

        if (bitRegister3 == bitRegister1 || bitRegister3 == bitRegister2)
        {
            register3.leftShift(register3.getBit(22) xor register3.getBit(21) xor register3.getBit(20) xor register3.getBit(7));
        }
        
        result <<= 1;
        if ((register1.getLastBit() xor register2.getLastBit() xor register3.getLastBit()) == true)
        {
            result |= 0b1;
        }
        
        counter++;
        if (counter == 8)
        {
            cout << result << " ";
            result = 0;
            counter = 0;
        }
    }
    
    cout << endl;
    
    return (0);
}
