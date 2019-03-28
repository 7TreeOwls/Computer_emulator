#include "control_signals.h"
#include "opcodes.h"

#include <iostream>


Control_signals::Control_signals()
{
	ALU_constant = false;
    ALU_opcode = ALU_AND;
    branch = false;
	jump = false;
	store = false;
    stop = false;
}

void Control_signals::updateSignals(int opcode)
{
    
    if(opcode == 0x0F) //stop the computer because end of instructions
    {
        stop = true;
        // std::cout << "stop inside control: " << stop << "\n";
    }else if((opcode & 0xF0) == 0x00) //R-type instruction
    {
        ALU_constant = 0;
        branch = 0;
		jump = 0;
        //ALU opcode is the same as last 4 bits of CPU opcode
        ALU_opcode = opcode & 0x0F;
		load = 0;
        store = 0;
    }else if((opcode & 0xF0) == 0x10) //load
    {
        //last bit of opcode decides whether offset is a constant or from register
		ALU_constant = opcode & 0b00000001;
        branch = 0;
		jump = 0;
        ALU_opcode = ALU_ADD;
		load = 1;
        store = 0;
    }else if((opcode & 0xF0) == 0x20) //store
    {
        //last bit of opcode decides whether offset is a constant or from register
		ALU_constant = opcode & 0b00000001;
        branch = 0;
		jump = 0;
        ALU_opcode = ALU_ADD;
		load = 0;
        store = 1;
    }else if((opcode & 0xF0) == 0x30) //calculation with constant
    {
        ALU_constant = 1;
        branch = 0;
		jump = 0;
        //ALU opcode is the same as last 4 bits of CPU opcode
        ALU_opcode = opcode & 0x0F;
		load = 0;
        store = 0;
    }else if((opcode & 0xF0) == 0x50) //jump and bne
    {
        ALU_constant = 0;
        branch = 1;
		if(opcode == 0x50)
		{
			jump = 1;
		}else
		{
			jump = 0;
		}
		
        //if equal, result is 0x00, signal is_not_zero is high
        ALU_opcode = ALU_SUB;
		load = 0;
        store = 0;
    }
	
}