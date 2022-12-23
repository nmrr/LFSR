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

#include "LFSR.h"

uint32_t LFSR::getSize()
{
    return binarySize;
}

uint32_t LFSR::getArraySize()
{
    return arraySize;
}

void LFSR::rightShift(bool last)
{
    for (uint32_t j = 0; j < arraySize-1; j++)
    {
        array[j] >>= 1;
        setBit(array[j], 31, getBit(array[j+1], 0));
    }

    array[arraySize-1] >>= 1;
    setBit(array[arraySize-1], lastBitPosition, last);
}

void LFSR::leftShift(bool first)
{
    for (uint32_t j = arraySize-1; j >= 1; j--)
    {
        array[j] <<= 1;
        setBit(array[j], 0, getBit(array[j-1], 31));
    }

    array[0] <<= 1;
    setBit(array[0], 0, first);
}

uint8_t LFSR::get8bit()
{
    return (uint8_t) array[0];
}

uint16_t LFSR::get16bit()
{
    return (uint16_t) array[0];
}

uint32_t LFSR::get32bit()
{
    return array[0];
}

uint32_t LFSR::get32bitArray(uint32_t position)
{
    return array[position];
}

bool LFSR::getBit(uint32_t bitPosition)
{
    return getBit(array[address[bitPosition]], position[bitPosition]);
}

bool LFSR::getFirstBit()
{
    return getBit(array[0], 0);
}

bool LFSR::getLastBit()
{
    return getBit(array[arraySize-1], lastBitPosition);
}

void LFSR::setBit(uint32_t bitPosition, bool value)
{
    setBit(array[address[bitPosition]], position[bitPosition], value);
}

void LFSR::setFirstBit(bool value)
{
    setBit(array[0], 0, value);
}

void LFSR::setLastBit(bool value)
{
    setBit(array[arraySize-1], lastBitPosition, value);
}

void LFSR::save(uint32_t * &output)
{
    output = new uint32_t[arraySize];
    for (uint32_t i = 0; i < arraySize; i++)
    {
        output[i] = array[i];
    }
}

bool LFSR::compare(uint32_t * &output)
{
    for (uint32_t i = 0; i < arraySize; i++)
    {
        if (output[i] != array[i]) return false;
    }

    return true;
}

void LFSR::set(uint32_t * &output)
{
    for (uint32_t i = 0; i < arraySize; i++)
    {
        array[i] = output[i];
    }
}

///// PRIVATE /////

bool LFSR::getBit(uint32_t &array, uint32_t bitPosition)
{
    return (array >> bitPosition) & 0b1;
}

void LFSR::setBit(uint32_t &array, uint32_t bitPosition, bool data)
{
    if (data == true) setBitTo1(array, bitPosition);
    else setBitTo0(array, bitPosition);
}

void LFSR::setBitTo1(uint32_t &array, uint32_t bitPosition)
{
    array |= (1u << bitPosition);
}

void LFSR::setBitTo0(uint32_t &array, uint32_t bitPosition)
{
    array &= ~(1u << bitPosition);
}
