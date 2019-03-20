#include "alu.h"


Alu::Alu(){
    Control = 0;
}

int Alu::send_to(int in1, int in2, int control, int *output)
{
    switch (control)
    {
        case 0b0000:
            Output = AND(in1, in2);
            break;
        case 0b0001:
            Output = OR(in1, in2);
            break;
        case 0b0010:
            Output = add(in1, in2);
            break;
        case 0b0011:
            Output = substract(in1, in2);
            break;
        case 0b0100:
            Output = multiply(in1, in2);
            break;
        case 0b0101:
            Output = slt(in1, in2);
            break;
        case 0b0110:
            Output = NOR(in1, in2);
            break;
    
        default:
            Output = 0;
            break;
    }
    //Checks whether pointer to output was provided:
    if(output != nullptr)
    {
        *output = Output;
    }
    return Output;
}

//Override of function when exterrior control signal is not passed
int Alu::send_to(int in1, int in2, int *output)
{
    int result;
    result = send_to(in1, in2, Control, output);
    return result;
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

