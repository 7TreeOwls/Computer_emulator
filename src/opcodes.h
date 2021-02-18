#pragma once

// CPU Opcodes and assembly instructions:
//     R-type instructions:

#define CPU_AND 0x00 //(0b0000 0000) = and <write_register> <read_register1> <read_register2> 
#define CPU_OR 0x01 //(0b0000 0000) = or <write_register> <read_register1> <read_register2>
#define CPU_ADD 0x02 //(0b0000 0010) = add <write_register> <read_register1> <read_register2>
#define CPU_SUB 0x03 //(0b0000 0011) = sub <write_register> <read_register1> <read_register2>
#define CPU_MULT 0x04 //(0b0000 0100) = mult <write_register> <read_register1> <read_register2>
#define CPU_SLT 0x05 //(0b0000 0101) = slt <write_register> <read_register1> <read_register2>
#define CPU_NOR 0x06 //(0b0000 0110) = nor <write_register> <read_register1> <read_register2>

//     I-type instructions:

#define CPU_LW 0x10 //(0b0001 0000) = lw <write_register> <offset from read_register2>(<read_register1>)
#define CPU_LWI 0x11 //(0b0001 0001) = lw <write_register> <offset>(<read_register>)

#define CPU_SW 0x20 //(0b0010 0000) = sw <read_register1> <offset from read_register2>(<write_register>)
#define CPU_SWI 0x21 //(0b0010 0001) = sw <read_register> <offset>(<write_register>)

#define CPU_ANDI 0x30 //(0b0011 0000) = andi <write_register> <read_register1> <constant>
#define CPU_ORI 0x31 //(0b0011 0001) = ori <write_register> <read_register1> <constant>
#define CPU_ADDI 0x32 //(0b0011 0010) = addi <write_register> <read_register1> <constant>
#define CPU_SUBI 0x33 //(0b0011 0011) = subi <write_register> <read_register1> <constant>
#define CPU_MULTI 0x34 //(0b0011 0100) = multi <write_register> <read_register1> <constant>
#define CPU_SLTI 0x35 //(0b0011 0101) = slti <write_register> <read_register1> <constant>
#define CPU_NORI 0x36 //(0b0011 0110) = nori <write_register> <read_register1> <constant>
#define CPU_SLLI 0x37 //(0b0011 0111) = sll <write_register> <read_register1> <constant> //shift left
#define CPU_SRLI 0x38 //(0b0011 1000) = srl <write_register> <read_register1> <constant> //shift right

#define CPU_J 0x50 //(0b0101 0000) = j <label> //jump to label
#define CPU_BNE 0x51 //(0b0101 0001) = bne <read_register1> <read_register2> <label> //jump if not equal

#define CPU_END 0x0F //(0b1111 1111) = ends the operation of cpu, resets the pc

// ALU Opcodes:
#define ALU_AND 0b0000 //= AND
#define ALU_OR 0b0001 //= OR
#define ALU_ADD 0b0010 //= add
#define ALU_SUB 0b0011 //= substract
#define ALU_MULT 0b0100 //= multiply
#define ALU_SLT 0b0101 //= set-on-less-than
#define ALU_NOR 0b0110 //= NOR
#define ALU_SLL 0b0111 //=sll shift left logical
#define ALU_SRL 0b1000 //=srl shift right logical