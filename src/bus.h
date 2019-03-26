#pragma once

#include "ram.h"
#include "inputoutput.h"

//BUS class - connects CPU and RAM and InputOutput
class Bus
{
private:
    //pointer to RAM
    Ram *pRAM;
    InputOutput *pIO;
public:
    Bus();
    Bus(Ram *pointerRAM);
    Bus(Ram *pointerRAM , InputOutput *pointerIO);
    //address bus
    int address_bus;
    //data bus
    int data_bus;
    //read and write signals
    int read(int address);
    void write(int address, int value);
};