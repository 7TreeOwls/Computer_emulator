#include "control_signals.h"
#include "opcodes.h"

void Control_signals::updateSignals(int opcode)
{
    if((opcode & 0xF0) == 0x00) //R-type instruction
    {
        ALU_constant = 0;
        branch = 0;
        //ALU opcode is the same as last 4 bits of CPU opcode
        ALU_opcode = opcode & 0x0F;
        store = 0;
    }else if((opcode & 0xF0) == 0x10) //load or store
    {
        ALU_constant = 1;
        branch = 0;
        ALU_opcode = ALU_ADD;
        //store signal is the last bit of opcode when 4th bit is set
        store = opcode & 0b00000001;
    }else if((opcode & 0xF0) == 0x30) //calculation with constant
    {
        ALU_constant = 1;
        branch = 0;
        //ALU opcode is the same as last 4 bits of CPU opcode
        ALU_opcode = opcode & 0x0F;
        store = 0;
    }else if((opcode & 0xF0) == 0x50) //jump and bne
    {
        ALU_constant = 0;
        branch = 1;
        //if equal, result is 0x00, signal is_not_zero is high
        ALU_opcode = ALU_SUB; 
        store = 0;
    }else if(opcode == 0x0F)
    {
        stop = true;
    }
}