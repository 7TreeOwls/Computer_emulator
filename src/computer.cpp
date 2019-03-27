#include "computer.h"


Computer::Computer()
{
    //connection of RAM, IO and CPU via BUS
    BUS = Bus(&RAM, &IO);
    CPU = Cpu(&BUS);
}

//writes a passed set (as array) of instruciton to memory
void Computer::instruction_write(int *instruction_set, int length_set)
{
    int instr_address;
    for(int i=0; i<length_set; i++)
    {
        instr_address = i+FIRST_INSTR;
        BUS.write(instr_address, instruction_set[i]);
    }
}

void Computer::instruction_write(vector<int> &instruction_set)
{
	int instr_address;
    for(int i=0; i<(int)instruction_set.size(); i++)
    {
        instr_address = i+FIRST_INSTR;
        BUS.write(instr_address, instruction_set[i]);
    }
}


//clocks CPU once
void Computer::clockCPU()
{
    CPU.update();
}

void Computer::run()
{
    CPU.run();
}
