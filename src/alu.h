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
    private:
        //pointers to exterior signals
        int *in1_p;
        int *in2_p;
        int *out_p;
        int *opalu_p;
        //Methods and available computation:
        int AND(int a, int b);
        int OR(int a, int b);
        int add(int a, int b);
        int substract(int a, int b);
        int multiply(int a, int b);
        int slt(int a, int b);
        int NOR(int a, int b);
    public:
        Alu();
        //Initialisation with connection of signals:
        Alu(int *input1, int *input2, int *output, int *opcode_alu);
        int Control = 0b0000;
        
        //updates output of Alu:
        void update();


        int Output = 0;
        //updates ALU output:
        int perform(int in1, int in2, int control, int *output=nullptr);
        int perform(int in1, int in2, int *output=nullptr);
        //when one of inputs has constant connection
        int perform(int in, int *output=nullptr);
        
};


