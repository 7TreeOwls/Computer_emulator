#pragma once

#include <vector>

#include "ram.h"
#include "bus.h"
#include "cpu.h"

class Computer
{
private:
<<<<<<< HEAD
	Ram RAM;
    InputOutput IO;
=======
    Ram RAM;
>>>>>>> parent of 0c719c1... implemented InputOutput subsystem
    Bus BUS;
    Cpu CPU;
public:
    Computer();
    //instruction write to memory
	void instruction_write(int instr_number, int instruction);
    // void instruction_write(int *instruction_set, int length_set);
	// void instruction_write(vector<int> &instruction_set, int length_set);
    void clockCPU();
};