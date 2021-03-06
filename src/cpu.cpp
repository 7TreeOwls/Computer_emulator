#include "cpu.h"
#include <iostream>


Cpu::Cpu(){}

Cpu::Cpu(Bus *pointerBUS)
{
    pBUS = pointerBUS;
    //signal connection to ALUs:
    PC_ALU = Alu(&pc, &pc_increment_const, &pc_next, 
				&pc_alu_opcode_const);
    ALU = Alu(&in_alu1, &in_alu2, &accumulator_alu, 
			&control.ALU_opcode, &is_not_zero_alu);
    
}

void Cpu::instruction_fetch()
{

    //fetching of instruction from PC to Instruction register
    pc = pBUS->read(PC_ADDRESS);
    instruction = pBUS->read(pc);
    pBUS->write(IR_ADDRESS, instruction);
    //Incrementation of Program Counter signal
    PC_ALU.update();
}

void Cpu::decode()
{
    //opcode is first 8 bits - 0xXX 00 00 00 where XX is the opcode
    int opcode = instruction >> 24;
    control.updateSignals(opcode);
    // cout << "opcode: " << std::hex << opcode << "\n";

    //Division of instruction
    //0x00 XX 00 00 - XX is write_address
    write_address = (instruction & 0x00FF0000) >> 16;
    //0x00 00 XX 00 - XX is read_address1
    int read_address1 = (instruction & 0x0000FF00) >> 8;
    //0x00 00 00 XX - XX is read_address2
    int read_address2 = instruction & 0x000000FF;

	if(control.load)
	{
		read_data1 = read_address1;
	}else
	{
		read_data1 = pBUS->read(read_address1);
	}
	read_data2 = pBUS->read(read_address2);

    //0x00 00 00 XX - XX is constant/offset
    constant = instruction & 0x000000FF;
    // cout << "constant: " << std::hex << constant << "\n";
}

void Cpu::execute()
{
    //2 MUXES before ALU:
    in_alu1 = control.store ? write_address : read_data1;
    in_alu2 = control.ALU_constant ? constant : read_data2;
    // cout << "in_alu2: " << std::hex << in_alu2 << "\n";

    ALU.update();
    //AND gate before MUX for setting the next PC value
    pc_control = control.branch && is_not_zero_alu;
	//OR gate before MUX for setting the next PC value
	pc_control = pc_control | control.jump;
    //MUX for setting the next PC value
	// cout << "pc_control " << pc_control << "\n";
	// cout << "pc_next " << pc_next << "\n";
    pc = pc_control ? write_address : pc_next;
	// cout << "pc " << pc << "\n";
}

void Cpu::mem_access()
{
    int address__to_write;
    int value_to_write;
    // cout << "accumulator_alu: " << std::hex << accumulator_alu << "\n";


    if(control.store == true) //sw - store word 
    {
        address__to_write = accumulator_alu;
        value_to_write = read_data1;
    }else if(control.load == true) //lw load word
	{
		address__to_write = write_address;
		value_to_write = pBUS->read(accumulator_alu);
	}else//all instruction except sw - store word
    {
		address__to_write = write_address;
        value_to_write = accumulator_alu;
    }
	// cout << "accumulator_alu " << accumulator_alu << "\n";
	// cout << "value_to_write " << accumulator_alu << "\n";
	if(control.branch == false) //no memory write if bne or jump instruction
	{
		pBUS->write(address__to_write, value_to_write);
	}

	//set the new PC
    pBUS->write(PC_ADDRESS, pc);
}

void Cpu::update()
{
    instruction_fetch();
    decode();
	if(control.stop == false)
	{
		execute();
    	mem_access();
	}
    
}

void Cpu::run()
{
    control.stop = false;
    while(control.stop == false)
    {
        update();
    }
    pBUS->write(PC_ADDRESS, FIRST_INSTR);
}