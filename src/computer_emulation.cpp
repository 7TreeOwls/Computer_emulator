#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define DEBUG true

#include "opcodes.h"
#include "computer.h"


using namespace std;


int main()
{
    // cout << "Specify a path to machine code:\n";
    // string ml_filename;
    // cin >> ml_filename;

	//Computer instantion
	Computer COMP;



    int instr;
    fstream ml_file;
    ml_file.open("machinecode.txt", fstream::in);
    ml_file >> hex;

	cout << hex;

	int it = 0;
	while(ml_file.eof() == false)
	{
		ml_file >> instr;

		COMP.instruction_write(it, instr);

		it++;
		cout << instr << "\n";
	}
	int instr_end = CPU_END << 24;
	COMP.instruction_write(it, instr_end);
	ml_file.close();

	COMP.run();

	


    return 0;
}