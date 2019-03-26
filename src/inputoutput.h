#pragma once

#include <iostream>
#include "ram.h"


class InputOutput
{
private:
    //value held in module
    int val;
public:
    InputOutput();
    InputOutput(int io_address);

    //address of io subsystem
    int address;

    //read and write signals:
    //(connected now to standard iostream,
    //accepts and outputs numbers)

    //waits for new input
    int read_new();
    //signal to just read last inputed value
    int read();
    //signal to write to output
    void write(int value);

};

InputOutput::InputOutput()
{
    //by default last place after ram
    address = RAM_SIZE;
    val = 0;
}

InputOutput::InputOutput(int io_address)
{
    address = io_address;
    val = 0;
}

int InputOutput::read_new()
{
    cin >> val;
    return val;
}

int InputOutput::read()
{
    return val;
}

void InputOutput::write(int value)
{
    cout << val << "\n";
}