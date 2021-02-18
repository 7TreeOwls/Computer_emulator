#pragma once

#include "opcodes.h"

class Alu
{   
    //opcodes:
    // 0b0000 = AND
    // 0b0001 = OR
    // 0b0010 = add
    // 0b0011 = substract
    // 0b0100 = multiply
    // 0b0101 = set-on-less-than
    // 0b0110 = NOR
    // 0b0111 = sll shift left logical
    // 0b1000 = srl shift right logical
    private:
        //pointers to exterior signals
        int *in1_p;
        int *in2_p;
        int *out_p;
        int *opalu_p;
        bool *is_not_zero;
        //dummy when signal is not provided
        bool is_not_zero_dummy;
        
        //Methods and available computation:
        int AND(int a, int b);
        int OR(int a, int b);
        int add(int a, int b);
        int substract(int a, int b);
        int multiply(int a, int b);
        int slt(int a, int b);
        int NOR(int a, int b);
        int sll(int a, int b);
        int srl(int a, int b);
    public:
        Alu();
        //Initialisation with connection of signals:
        Alu(int *input1, int *input2, int *output, 
            int *opcode_alu);
        //additional signal, tells if result is not 0
        Alu(int *input1, int *input2, int *output, 
            int *opcode_alu, bool *is_not_zero_sig);

        //updates output of Alu:
        void update();

        
};


