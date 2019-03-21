
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

#define CPU_LW 0x10 //(0b0001 0000) = lw <write_register> <offset>(<read_register>)/<constant>
#define CPU_SW 0x20 //(0b0010 0000) = sw <read_register> <offset>(<write_register>)

#define CPU_ANDI 0x30 //(0b0011 0000) = andi <write_register> <read_register1> <constant>
#define CPU_ORI 0x31 //(0b0011 0001) = ori <write_register> <read_register1> <constant>
#define CPU_ADDI 0x32 //(0b0011 0010) = addi <write_register> <read_register1> <constant>
#define CPU_SUBI 0x33 //(0b0011 0011) = subi <write_register> <read_register1> <constant>
#define CPU_MULTI 0x34 //(0b0011 0100) = multi <write_register> <read_register1> <constant>
#define CPU_SLTI 0x35 //(0b0011 0101) = slti <write_register> <read_register1> <constant>
#define CPU_NORI 0x36 //(0b0011 0110) = nori <write_register> <read_register1> <constant>

#define CPU_SLL 0x40 //(0b0100 0000) = sll <write_register> <read_register1> <constant> //shift left
#define CPU_SRL 0x41 //(0b0100 0001) = srl <write_register> <read_register1> <constant> //shift right

#define CPU_J 0x50 //(0b0101 0000) = j <label> //jump to label
#define CPU_BNE 0x51 //(0b0101 0000) = bne <read_register1> <read_register2> <label> //jump if not equal


// ALU Opcodes:
#define ALU_AND 0b0000 //= AND
#define ALU_OR 0b0001 //= OR
#define ALU_ADD 0b0010 //= add
#define ALU_SUB 0b0011 //= substract
#define ALU_MULT 0b0100 //= multiply
#define ALU_SLT 0b0101 //= set-on-less-than
#define ALU_NOR 0b0110 //= NOR