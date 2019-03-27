#pragma once

#include "alu.h"
#include "control_signals.h"
#include "bus.h"



class Cpu
{
private:
    //pointer to BUS
    Bus *pBUS;

    //program counter signals and its ALU
    Alu PC_ALU;
    bool pc_control; //signal for PC mux
    int pc_next = 0;
    int pc_increment_const = 1; //constant
    int pc_alu_opcode_const = ALU_ADD; //constant

    //Control signals:
    Control_signals control;
    
    //Registers:
    int pc = 0;
    int instruction;
    int accumulator_alu; //main ALU output

    //signals between decode() and execute()
    int constant;
    int write_address;
    int read_data1;
    int read_data2;

    //execute (main) ALU and its signals:
    Alu ALU;
    int in_alu1;
    int in_alu2;
    bool is_not_zero_alu;

    //CPU operation:
    //instruction fetch
    void instruction_fetch();
    //decode of instruction
    void decode();
    //execute instruction
    void execute();
    //MEM - memory write
    void mem_access();


public:
    Cpu();
    //Initialisation with connection to RAM
    Cpu(Bus *pointerBUS);

    //one operation of CPU:
    void update();

    //CPU runs until all instructions performed
    void run();
};