#pragma once

#include <fstream>

#ifndef DEBUG
#define DEBUG true
#endif

#define RAM_SIZE 128

#define PC_ADDRESS 1
#define IR_ADDRESS 2 //instruction register address

#define FIRST_INSTR 4
#define LAST_INSTR 67

// //R type instruction has opcode in range 0x00 - 0x0F
// //L type instruction has opcode in range 0x1F - 0x00
// #define R_MASK 0x0F000000
// #define L_MASK 0xF0000000

using namespace std;

class Ram
{
private:
	//used for logging
    fstream logfile;
	int clock_cycle;

    //memory:
    int memory[RAM_SIZE] =
    {
        //Program counter, instruction register
        0x00000000, 0x00000004, 0x00000000, 0x00000000,
        //Program memory: - last instruction is constant,
        //do not ovewrite it unless you need more porgram memory
        //then write 0x0F000000 after your last instruction
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x0F000000,
        //General memory:
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
    };
public:
    Ram();
    //read from memory
    int read(int address);
    //write to memory
    void write(int address, int value);
};



