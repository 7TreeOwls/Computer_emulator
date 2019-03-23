#include "ram.h"
#include "alu.h"
#include "control_signals.h"

class Cpu
{
private:
    //pointer to RAM
    Ram *pRAM;

    //program counter signals and its ALU
    Alu PC_ALU;
    bool pc_control; //signal for PC mux
    int pc_next = 0;
    int pc_increment = 1; //constant
    int pc_alu_opcode_const = ALU_ADD; //constant

    //Control signals:
    Control_signals control;
    
    //Registers:
    unsigned int pc = 0;
    unsigned int instruction;
    int accumulator_alu; //alu_out

    //signals between decode() and execute()
    int constant;
    int write_address;
    int read_data1;
    int read_data2;

    //execute (main) ALU and its signals:
    Alu ALU;
    int in_alu1;
    int in_alu2;
    int out_alu;
    bool is_not_zero_alu;


    


public:
    Cpu();
    //Initialisation with connection to RAM
    Cpu(Ram *pointerRAM);
    Cpu(int );
    //program counter
    int pc;
    
    //instruction fetch
    void instruction_fetch();
    //decode of instruction
    void decode();
    //execute instruction
    void execute();
    //MEM - memory write
    void mem_access();


};