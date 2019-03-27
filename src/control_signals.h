#pragma once

//Contians control signals for CPU
class Control_signals
{
public:
    Control_signals();
    bool ALU_constant;
    int ALU_opcode;
    bool branch;
    bool store;
    bool stop = false;
    void updateSignals(int opcode);
};