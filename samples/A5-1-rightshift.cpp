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

int main(int argc, char **argv)
{
    
    LFSR register1(19);
    LFSR register2(22);
    LFSR register3(23);
    
    register1.setBit(0, true);
    register2.setBit(0, true);
    register3.setBit(0, true);
    
    uint32_t result = 0;
    int counter = 0;

    for (uint32_t i=0; i < 1024; i++)
    {
        bool bitRegister1 = register1.getBit(10);
        bool bitRegister2 = register2.getBit(11);
        bool bitRegister3 = register3.getBit(12);
        
        if (bitRegister1 == bitRegister2 || bitRegister1 == bitRegister3)
        {
            register1.rightShift(register1.getFirstBit() xor register1.getBit(1) xor register1.getBit(2) xor register1.getBit(5));
        }
        
        if (bitRegister2 == bitRegister1 || bitRegister2 == bitRegister3)
        {
            register2.rightShift(register2.getFirstBit() xor register2.getBit(1));
        }

        if (bitRegister3 == bitRegister1 || bitRegister3 == bitRegister2)
        {
            register3.rightShift(register3.getFirstBit() xor register3.getBit(1) xor register3.getBit(2) xor register3.getBit(15));
        }
        
        result <<= 1;
        if ((register1.getFirstBit() xor register2.getFirstBit() xor register3.getFirstBit()) == true)
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
