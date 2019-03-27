#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define DEBUG 1

#include "opcodes.h"
#include "computer.h"


using namespace std;


int main()
{
    // cout << "Specify a path to machine code:\n";
    string ml_filename;
    // cin >> ml_filename;

	//set of instructions
	vector<int> instr_set;

    int instr;
    fstream ml_file;
    ml_file.open("machinecode.txt", fstream::in);
    ml_file >> hex;

	cout << hex;

	while(ml_file.eof() == false)
	{
		ml_file >> instr;
		instr_set.push_back(instr);

		cout << instr << "\n";
	}
	ml_file.close();
	
	instr_set.push_back(CPU_END << 24);
	cout << instr_set[instr_set.size()-1] << "\n";


	// cout << instr_set[instr_set.size()-1] << "\n";

	Computer COMP;

	//works for C++11 since it is guaranteed that vectors are stored continously
	COMP.instruction_write(instr_set);
	cout << "started running" << "\n";
	//Run computer
	COMP.run();



    return 0;
}