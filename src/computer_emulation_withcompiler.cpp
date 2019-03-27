#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "opcodes.h"
#include "ram.h"

using namespace std;




void compile(string assembly_file_name)
{
    fstream afile;

    //single instruction line
    string instr;
    //machine code instruction:
    int ml_instr;
    //deconstructed instruction
    vector<string> split_instr;
    //temp string used to append split_instr
    string part_instr;

	int line = 0;
    do
    {
        getline(afile, instr);

        for(size_t i=0; i<instr.length(); i++)
        {
            //Splitting line of instruction into word
            
            //if not a space
            if(instr.compare(i , 1, " ") != 0)//if still part of a word, append
            {
                part_instr.push_back(instr[i]);
            }else if(instr.compare(i, 1, "#") == 0)//if comment, stop interpreting
            {
                split_instr.push_back(part_instr);
                part_instr.clear();
                break;
            }else //if space, append the word to split_instr(uction), clear the temp string
            {
                split_instr.push_back(part_instr);
                part_instr.clear();
            }

			//label name
			vector<string> labels;
			//line for that label
			vector<int> labels_line;
			//is there a label in that line? 0 - no, 1 - yes
			int islabel = 0;
            
            //assigning opcode, first 8 bits
            if(split_instr[0] == "and")
            {
                ml_instr = CPU_AND << 24;
            }else if(split_instr[0] == "or")
            {
                ml_instr = CPU_OR << 24;
            }else if(split_instr[0] == "add")
            {
                ml_instr = CPU_ADD << 24;
            }else if(split_instr[0] == "sub")
            {
                ml_instr = CPU_SUB << 24;
            }else if(split_instr[0] == "mult")
            {
                ml_instr = CPU_MULT << 24;
            }else if(split_instr[0] == "slt")
            {
                ml_instr = CPU_SLT << 24;
            }else if(split_instr[0] == "nor")
            {
                ml_instr = CPU_NOR << 24;
            }else if(split_instr[0] == "lw")
            {
                ml_instr = CPU_LW << 24;
            }else if(split_instr[0] == "sw")
            {
                ml_instr = CPU_SW << 24;
            }else if(split_instr[0] == "andi")
            {
                ml_instr = CPU_ANDI << 24;
            }else if(split_instr[0] == "ori")
            {
                ml_instr = CPU_ORI << 24;
            }else if(split_instr[0] == "addi")
            {
                ml_instr = CPU_ADDI << 24;
            }else if(split_instr[0] == "subi")
            {
                ml_instr = CPU_SUBI << 24;
            }else if(split_instr[0] == "multi")
            {
                ml_instr = CPU_MULTI << 24;
            }else if(split_instr[0] == "slti")
            {
                ml_instr = CPU_SLTI << 24;
            }else if(split_instr[0] == "nori")
            {
                ml_instr = CPU_NORI << 24;
            }else if(split_instr[0] == "sll")
            {
                ml_instr = CPU_SLL << 24;
            }else if(split_instr[0] == "srl")
            {
                ml_instr = CPU_SRL << 24;
            }else if(split_instr[0] == "j")
            {
                ml_instr = CPU_J << 24;
            }else if(split_instr[0] == "bne")
            {
                ml_instr = CPU_BNE << 24;
            }else //if this is a label:
			{
				labels.push_back(split_instr[0]);
				labels_line.push_back(line);
				islabel = 1;

				if(split_instr[1] == "and")
				{
					ml_instr = CPU_AND << 24;
				}else if(split_instr[1] == "or")
				{
					ml_instr = CPU_OR << 24;
				}else if(split_instr[1] == "add")
				{
					ml_instr = CPU_ADD << 24;
				}else if(split_instr[1] == "sub")
				{
					ml_instr = CPU_SUB << 24;
				}else if(split_instr[1] == "mult")
				{
					ml_instr = CPU_MULT << 24;
				}else if(split_instr[1] == "slt")
				{
					ml_instr = CPU_SLT << 24;
				}else if(split_instr[1] == "nor")
				{
					ml_instr = CPU_NOR << 24;
				}else if(split_instr[1] == "lw")
				{
					ml_instr = CPU_LW << 24;
				}else if(split_instr[1] == "sw")
				{
					ml_instr = CPU_SW << 24;
				}else if(split_instr[1] == "andi")
				{
					ml_instr = CPU_ANDI << 24;
				}else if(split_instr[1] == "ori")
				{
					ml_instr = CPU_ORI << 24;
				}else if(split_instr[1] == "addi")
				{
					ml_instr = CPU_ADDI << 24;
				}else if(split_instr[1] == "subi")
				{
					ml_instr = CPU_SUBI << 24;
				}else if(split_instr[1] == "multi")
				{
					ml_instr = CPU_MULTI << 24;
				}else if(split_instr[1] == "slti")
				{
					ml_instr = CPU_SLTI << 24;
				}else if(split_instr[1] == "nori")
				{
					ml_instr = CPU_NORI << 24;
				}else if(split_instr[1] == "sll")
				{
					ml_instr = CPU_SLL << 24;
				}else if(split_instr[1] == "srl")
				{
					ml_instr = CPU_SRL << 24;
				}else if(split_instr[1] == "j")
				{
					ml_instr = CPU_J << 24;
				}else if(split_instr[1] == "bne")
				{
					ml_instr = CPU_BNE << 24;
				}
			}


			for(int i=(1+islabel); i<=split_instr.size(); i++)//TODO fix this
			{
				//registers, example: r1
				split_instr[i].erase(split_instr[i].begin());
				int write_address = stoi(split_instr[i]) + FIRST_INSTR - 1;
				ml_instr = ml_instr | (write_address << ((3-i+islabel)*8));
			}

			


			



            
        }

		line = line +1;
    } while (instr.empty() == false);
    



    



    afile.close();
}




int main()
{
    char cstr[64];
    fstream test;
    test.open("log_testram.txt", fstream::in);
    // test.getline(cstr, 64);
    string str;
    getline(test, str);
    cout << str.size() << "\n";
    cout << str << "\n";
    
    test.close();
    return 0;
}