#include "cpu.h"


Cpu::Cpu(){}

Cpu::Cpu(Ram *pointerRAM)
{
    pRAM = pointerRAM;
    //signal connection to ALUs:
    PC_ALU = Alu(&pc, &pc_increment, &pc_next, &pc_alu_opcode_const);
    ALU = Alu(&in_alu1, &in_alu2, &accumulator_alu, &control.ALU_opcode, &is_not_zero_alu);
    
}

void Cpu::instruction_fetch()
{
    //TODO add incrementation of pc
    //fetching of instruction from PC to Instruction register
    pc = pRAM->read(PC_ADDRESS);
    instruction = pRAM->read(pc);
    pRAM->write(IR_ADDRESS, instruction);
    //Incrementation of Program Counter signal
    PC_ALU.update();
}

void Cpu::decode()
{
    //opcode is first 8bits
    instruction = pRAM->read(IR_ADDRESS);
    //opcode is first 8 bits - 0xXX 00 00 00 where XX is the opcode
    int opcode = instruction >> 24;
    control.updateSignals(opcode);

    //Division of instruction
    //0x00 XX 00 00 - XX is write_address
    write_address = (instruction & 0x00FF0000) >> 16;
    //0x00 00 XX 00 - XX is read_address1
    int read_address1 = (instruction & 0x0000FF00) >> 8;
    //0x00 00 00 XX - XX is read_address2
    int read_address2 = instruction & 0x000000FF;

    read_data1 = pRAM->read(read_address1);
    read_data2 = pRAM->read(read_address2);
    //0x00 00 00 XX - XX is constant/offset
    constant = instruction & 0x000000FF;
}

void Cpu::execute()
{
    //2 MUXES before ALU:
    in_alu1 = control.store ? write_address : read_data1;
    in_alu2 = control.ALU_constant ? constant : read_data2;

    ALU.update();
    //AND gate before MUX for setting the next PC value
    pc_control = control.branch && is_not_zero_alu;
    //MUX for setting the next PC value
    pc_next = pc_control ? write_address : pc;
}

void Cpu::mem_access()
{
    //set the new PC
    pRAM->write(PC_ADDRESS, pc_next);
    int address__to_write;
    int value_to_write;

    if(control.store == false)//all instruction except sw - store word
    {
        address__to_write = write_address;
        value_to_write = accumulator_alu;
    }else //sw - store word
    {
        address__to_write = accumulator_alu;
        value_to_write = read_data1;
    }
    pRAM->write(address__to_write, value_to_write);
}

void Cpu::update()
{
    instruction_fetch();
    decode();
    execute();
    mem_access();
}

void Cpu::run()
{
    while(control.stop == false)
    {
        update();
    }
}