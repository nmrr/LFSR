# LFSR
An efficient linear feedback shift register (LFSR) class in C++

To build the sample : **g++ -std=c++11 LFSR.cpp main.cpp -o lfsr**

Output of the sample is : **counter = 16383**

----------------------------------------

LFSR can be used to generate pseudorandom numbers but it's possible to use it to play music. In a lot of case, the system will produce noise but, in some cases, the system will produce interesting tones. When the first bit and the last bit are xored, the length of the register is very short but the output doesn't look like pseudorandom numbers. You can listen the music by using this command : 

**./lfsr4096 | ffplay -f u8 -ar 44100 -ac 2 -i pipe:0**

This command is sending output data from the LFSR to the speakers. In the samples folder, lfsr4096.cpp and lfst128.cpp are using first and last bits to generate data. lfsr1024.cpp use a different equation so the music is different. You can adjuste the size of the register and the equation to create your own music. 
