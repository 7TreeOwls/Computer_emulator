#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "opcodes.h"
#include "computer.h"


using namespace std;

//you can specify debug mode in "debug.h"


int main(int argc,char *argv[])
{
    string ml_filename;
	if(argc == 1)
	{
		cout << "Specify a path to machine code:\n";
		cin >> ml_filename;
	}else
	{
		ml_filename = argv[1];
	}

	// cout << ml_filename << "\n";
	

	//Computer instantion
	Computer COMP;


	string line;
	unsigned int comment_startpos;
    int instr;

    fstream ml_file;
    // ml_file.open("machinecode.txt", fstream::in);
	ml_file.open(ml_filename, fstream::in);

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

		if(line.size() >= 8)
		{
			instr = stoi(line, nullptr, 16);

			COMP.instruction_write(it, instr);

			it++;
		}
		line.clear();
		
		// cout << instr << "\n";
	}
	int instr_end = CPU_END << 24;
	COMP.instruction_write(it, instr_end);
	ml_file.close();

	COMP.run();

	


    return 0;
}