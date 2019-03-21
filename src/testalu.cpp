#include <iostream>
#include <bitset>
#include "alu.h"

//Test the functions of ALU
using namespace std;


int main()
{
    //test of version1
    // Alu ALU;
    // int a = 5; //0b101
    // int b = 7; //0b111

    // int result = 0;

    // for(int i=0b0000; i<=0b0110; i++)
    // {
    //     result = ALU.send_to(a, b, i);
    //     cout << "Opcode: " << bitset<4>(i);
    //     cout << "\nOutput: " << result;
    //     cout << "\nOutput binary: " << bitset<32>(result) << "\n";
    // }

    //test of version2
    int input1 = 5; //0b0101
    int input2 = 7; //0b0111
    int result = 0;
    int alu_opcode = 0b0000;

    Alu ALU(&input1, &input2, &result, &alu_opcode);

    for(int i=0b0000; i<=0b0110; i++)
    {
        alu_opcode = i;
        ALU.update();
        cout << "Opcode: " << bitset<4>(i);
        cout << "\nOutput: " << result;
        cout << "\nOutput binary: " << bitset<32>(result) << "\n";
    }
}