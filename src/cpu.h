#include "ram.h"
#include "alu.h"

class Cpu
{
private:
    //pointer to RAM
    Ram *pRAM;
    //program counter signals and its ALU
    Alu PC_ALU;
    int pc = 0;
    int pc_next = 0;
    int pc_increment = 1; //constant
    int pc_alu_opcode_const = ALU_ADD; //constant
    //Control signals:
    bool RegDst;
    bool Branch;
    bool MemRead;
    bool MemtoReg;
    int ALUop;
    bool MemWrite;
    bool ALUSrc;
    bool RegWrite;

    //Signals for execute:
    int read_data1;
    int read_data2;

public:
    Cpu();
    //Initialisation with connection to RAM
    Cpu(Ram *pointerRAM);
    Cpu(int );
    //program counter
    int pc;
    
    //instruction fetch
    void instruction_fetch();
    void decode();
    void update_control_signals(int opcode);

};