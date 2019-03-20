

class Alu
{
    private:
        int AND(int a, int b);
        int OR(int a, int b);
        int add(int a, int b);
        int substract(int a, int b);
        int multiply(int a, int b);
        int slt(int a, int b);
        int NOR(int a, int b);
    public:
        Alu();
        int Control = 0b0000;
        //0b0000 = AND
        //0b0001 = OR
        //0b0010 = add
        //0b0011 = substract
        //0b0100 = multiply
        //0b0101 = set-on-less-than
        //0b0110 = NOR
        int Output = 0;
        //updates ALU output:
        int send_to(int in1, int in2, int control, int *output=nullptr);
        int send_to(int in1, int in2, int *output=nullptr);
        
};


