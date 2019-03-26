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

