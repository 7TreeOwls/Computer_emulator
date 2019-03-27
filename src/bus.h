#pragma once

#include "ram.h"

//BUS class - connects CPU and RAM and InputOutput
class Bus
{
private:
    //pointer to RAM
    Ram *pRAM;
public:
    Bus();
    Bus(Ram *pointerRAM);
    //address bus
    int address_bus;
    //data bus
    int data_bus;
    //read and write signals
    int read(int address);
    void write(int address, int value);
};