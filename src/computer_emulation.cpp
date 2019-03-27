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


	string line;
	unsigned int comment_startpos;
    int instr;

    fstream ml_file;
    ml_file.open("machinecode.txt", fstream::in);
    // ml_file >> hex;

	cout << hex;

	//iterator
	int it = 0;
	while(ml_file.eof() == false)
	{
		// ml_file >> instr;
		getline(ml_file, line);

		//get rid of 0x at the start
		// line.erase(0, 2);

		//filter out comments
		comment_startpos = line.find_first_of("#;", 0);
		if(comment_startpos != string::npos)
		{
			line.erase(comment_startpos, string::npos);
		}

		if(!line.empty())
		{
			instr = stoi(line, nullptr, 16);
			line.clear();

			COMP.instruction_write(it, instr);

		it++;
		}
		
		// cout << instr << "\n";
	}
	int instr_end = CPU_END << 24;
	COMP.instruction_write(it, instr_end);
	ml_file.close();

	COMP.run();

	


    return 0;
}