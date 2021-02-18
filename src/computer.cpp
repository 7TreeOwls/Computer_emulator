#include "computer.h"

#include <iostream>


Computer::Computer()
{
    //connection of RAM and CPU via BUS
	RAM = new Ram();
	IO = new InputOutput(RAM_SIZE);
    BUS = new Bus(RAM, IO);
    CPU = new Cpu(BUS);
}

void Computer::instruction_write(int instr_number, int instruction)
{
	BUS->write(instr_number+FIRST_INSTR, instruction);
}


//clocks CPU once
void Computer::clockCPU()
{
    CPU->update();
}

void Computer::run()
{
    CPU->run();
}
