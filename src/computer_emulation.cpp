#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void compile(string assembly_file_name)
{
    fstream afile;
    char instruction[64] = {0};
    string instr("1");
    char *pCommand;

    afile.open(assembly_file_name);

    while(instr != "\0")
    afile.getline(instruction, 64);
    instr = string(instruction);
    



    afile.close();
}




int main()
{
    char cstr[64] = {"ss\0"};
    string str(cstr); //truncates \0
    cout << str.size();    
    
    return 0;
}