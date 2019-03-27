#include "ram.h"

Ram::Ram()
{
    //Initialises empty memory
    memory[0] = 0x00000000;
    //at start program counter points to address of first instruction
    memory[1] = FIRST_INSTR;
    //setting instructions to 0x000000 except for lact one
    for(int i=2; i<LAST_INSTR; i++)
    {
        memory[i] = 0x00000000;
    }
    //stop instruction
    memory[LAST_INSTR] = 0x0F000000;
    for(int i=LAST_INSTR+1; i<RAM_SIZE; i++)
    {
        memory[i] = 0x00000000;
    }
    //clear file for DEBUG
    if(DEBUG)
    {
        logfile.open("log.txt", fstream::out | fstream::trunc);
        logfile  << "Memory log:\n\n";
        logfile.close();
		clock_cycle = 0;
    }
    
}

int Ram::read(int address)
{
    if(DEBUG)
    {
        logfile.open("log.txt", fstream::app | fstream::out);
		showbase(logfile);
        logfile << clock_cycle << ": " 
				<< "read " << std::hex << memory[address] 
                << " from " << std::hex << address << "\n";
        logfile.close();

    }
    return memory[address];
}

void Ram::write(int address, int value)
{
    if(DEBUG)
    {
        logfile.open("log.txt", fstream::app | fstream::out);
		showbase(logfile);
        logfile << clock_cycle << ": " 
				<< "write " << std::hex << value 
                << " to " << std::hex << address << "\n";
        logfile.close();

		//new clock cycle will start
		if(address == PC_ADDRESS)
		{
			clock_cycle = clock_cycle + 1;
		}
    }
    memory[address] = value;
}