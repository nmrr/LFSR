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

#ifndef LFSR_H
#define LFSR_H

#include <iostream>

class LFSR
{

private:

    uint32_t * array;
    uint32_t * address;
    uint32_t * position;

    uint32_t arraySize, binarySize;
    uint32_t lastBitPosition;

public:

    LFSR(uint32_t size)
    {
        if (size == 0) size = 1;

        binarySize = size;
        arraySize = 0;

        while(size > 0)
        {
            if (size > 32)
            {
                arraySize++;
                size -= 32;
                lastBitPosition = 31;
            }
            else
            {
                arraySize++;
                lastBitPosition = (size-1);
                size = 0;
            }
        }

        array = new uint32_t[arraySize];
        address = new uint32_t[binarySize];
        position = new uint32_t[binarySize];

        for (uint32_t i = 0; i < arraySize; i++)
        {
            array[i] = 0;
        }

        uint32_t arrayPosition = 0, bitPosition = 0;
        for (uint32_t i = 0; i < binarySize; i++)
        {
            address[i] = arrayPosition;
            position[i] = bitPosition;

            bitPosition++;
            if (bitPosition > 31)
            {
                bitPosition = 0;
                arrayPosition++;
            }
        }
    }

    ~LFSR()
    {
        delete [] array;
        delete [] address;
        delete [] position;
    }

    uint32_t getSize();
    uint32_t getArraySize();
    void rightShift(bool last);
    void leftShift(bool first);
    uint8_t get8bit();
    uint16_t get16bit();
    uint32_t get32bit();
    uint32_t get32bitArray(uint32_t position);
    bool getBit(uint32_t bitPosition);
    bool getFirstBit();
    bool getLastBit();
    void setBit(uint32_t bitPosition, bool value);
    void setFirstBit(bool value);
    void setLastBit(bool value);
    void save(uint32_t * &output);
    bool compare(uint32_t * &output);
    void set(uint32_t * &output);

private:
    
    bool getBit(uint32_t &array, uint32_t bitPosition);
    void setBit(uint32_t &array, uint32_t bitPosition, bool data);
    void setBitTo1(uint32_t &array, uint32_t bitPosition);
    void setBitTo0(uint32_t &array, uint32_t bitPosition);
};

#endif // LFSR_H
