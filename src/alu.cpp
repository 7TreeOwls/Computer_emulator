#include "alu.h"
#include <iostream>


Alu::Alu(){}

Alu::Alu(int *input1, int *input2, int *output, 
        int *opcode_alu)
{
    in1_p = input1;
    in2_p = input2;
    out_p = output;
    opalu_p = opcode_alu;
    is_not_zero = &is_not_zero_dummy;
}

Alu::Alu(int *input1, int *input2, int *output, 
        int *opcode_alu, bool *is_not_zero_sig)
{
    in1_p = input1;
    in2_p = input2;
    out_p = output;
    opalu_p = opcode_alu;
    is_not_zero = is_not_zero_sig;
}

void Alu::update()
{
    switch (*opalu_p)
    {
        case 0b0000:
            *out_p = AND(*in1_p, *in2_p);
            break;
        case 0b0001:
            *out_p = OR(*in1_p, *in2_p);
            break;
        case 0b0010:
            *out_p = add(*in1_p, *in2_p);
			// std::cout << "added: " << *in1_p << " " << *in2_p << "\n";
            break;
        case 0b0011:
            *out_p = substract(*in1_p, *in2_p);
            break;
        case 0b0100:
            *out_p = multiply(*in1_p, *in2_p);
            break;
        case 0b0101:
            *out_p = slt(*in1_p, *in2_p);
            break;
        case 0b0110:
            *out_p = NOR(*in1_p, *in2_p);
            break;
        case 0b0111:
            *out_p = sll(*in1_p, *in2_p);
            break;
        case 0b1000:
            *out_p = srl(*in1_p, *in2_p);
            break;
    
        default:
            *out_p = 0;
            break;
    }
    if(*out_p != 0)
    {
        *is_not_zero = 1;
    }else
    {
        *is_not_zero = 0;
    }
    
}



//Operations available in ALU
int Alu::AND(int a, int b)
{
    return (a & b);
}

int Alu::OR(int a, int b)
{
    return (a | b);
}

int Alu::add(int a, int b)
{
    return (a + b);
}

int Alu::substract(int a, int b)
{
    return (a - b);
}

int Alu::multiply(int a, int b)
{
    return (a*b);
}

int Alu::slt(int a, int b)
{
    if(a < b)
    {
        return 1;
    }else
    {
        return 0;
    }
    
}

int Alu::NOR(int a, int b)
{
    return (~(a | b));
}

int Alu::sll(int a, int b)
{
    return (a << b);
}

int Alu::srl(int a, int b)
{
    return(a >> b);
}

