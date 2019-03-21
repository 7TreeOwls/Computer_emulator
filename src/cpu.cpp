#include "cpu.h"


Cpu::Cpu(){}

Cpu::Cpu(Ram *pointerRAM)
{
    pRAM = pointerRAM;
    PC_ALU = Alu(&pc, &pc_increment, &pc_next, &pc_alu_opcode_const);
}

void Cpu::instruction_fetch()
{
    //TODO add incrementation of pc
    //fetching of instruction from PC to Instruction register
    pc = pRAM->read(PC_ADDRESS);
    pRAM->write(IR_ADDRESS, pc);
    //Incrementation of Program Counter signal
    PC_ALU.update();
}

void Cpu::decode()
{
    //opcode is first 8bits
    int opcode = pRAM->read(IR_ADDRESS) >> 24;
    update_control_signals(opcode);

    //register addresses - R type instruction
    int read_address1 = (pRAM->memory[IR_ADDRESS] >> 16) & 0x00FF;
    int read_address2 = (pRAM->memory[IR_ADDRESS] >> 8) & 0x0000FF;
    int write_address = pRAM->memory[IR_ADDRESS] & 0x000000FF;

}

void Cpu::update_control_signals(int opcode){}