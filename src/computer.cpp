#include "computer.h"

#include <iostream>


Computer::Computer()
{
    //connection of RAM and CPU via BUS
	RAM = new Ram();
	IO = new InputOutput();
    BUS = new Bus(RAM, IO);
    CPU = new Cpu(BUS);
}

void Computer::instruction_write(int instr_number, int instruction)
{
	BUS->write(instr_number+FIRST_INSTR, instruction);
}

// //writes a passed set (as array) of instruciton to memory
// void Computer::instruction_write(int *instruction_set, int length_set)
// {
//     int instr_address;
// 	int instr;
//     for(int i=0; i<length_set; i++)
//     {
//         instr_address = i+FIRST_INSTR;
// 		instr = instruction_set[i];
//         BUS.write(instr_address, instr);
//     }
// 	cout << "wrote instructions.\n";
// }

// void Computer::instruction_write(vector<int> &instruction_set, int length_set)
// {
// 	int instr_address;
// 	int instr;
//     for(unsigned int i=0; i<instruction_set.size(); i++)
//     {
//         instr_address = i+FIRST_INSTR;
// 		instr = instruction_set[i];
//         BUS.write(instr_address, instr);
//     }
// }


//clocks CPU once
void Computer::clockCPU()
{
    CPU->update();
}

void Computer::run()
{
    CPU->run();
}
