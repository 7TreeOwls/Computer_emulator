#pragma once

#include "ram.h"
#include "bus.h"
#include "cpu.h"

class Computer
{
private:
    Ram RAM;
    Bus BUS;
    Cpu CPU;
public:
    Computer(){};

    //instruction write to memory
    void instruction_write(int *instruction_set, int length_set);
    void clockCPU();
};