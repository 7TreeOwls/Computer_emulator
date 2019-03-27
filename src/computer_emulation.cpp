#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// #define DEBUG true

#include "opcodes.h"
#include "computer.h"


using namespace std;


int main()
{
    // cout << "Specify a path to machine code:\n";
    string ml_filename;
    // cin >> ml_filename;

	//Computer instantion
	Computer COMP;

	//set of instructions
	// vector<int> instr_set;
	int instruct_set[65];

    int instr;
    fstream ml_file;
    ml_file.open("machinecode.txt", fstream::in);
    ml_file >> hex;

	cout << hex;

	int it = 0;
	while(ml_file.eof() == false)
	{
		ml_file >> instr;
		// instr_set.push_back(instr);
		// instruct_set[it] = instr;

		COMP.instruction_write(it, instr);

		it++;
		cout << instr << "\n";
	}
	ml_file.close();
	instruct_set[64] = CPU_END << 24;
	// instr_set.push_back(CPU_END << 24);
	// cout << instr_set[instr_set.size()-1] << "\n";


	// cout << instr_set[instr_set.size()-1] << "\n";


	//works for C++11 since it is guaranteed that vectors are stored continously
	// COMP.instruction_write(instruct_set, it);

	cout << "started running" << "\n";
	//Run computer
	COMP.clockCPU();
	COMP.clockCPU();
	COMP.clockCPU();

	// COMP.run();



    return 0;
}