#include "ram.h"

Ram::Ram()
{
    //Initialises empty memory
    memory[0] = 0x00000000;
    //at start program counter points to address of first instruction
    memory[1] = 0x00000004;
    for(int i=2; i<RAM_SIZE; i++)
    {
        memory[i] = 0x00000000;
    }
}

int Ram::read(int address)
{
    return memory[address];
}

void Ram::write(int address, int value)
{
    memory[address] = value;
}