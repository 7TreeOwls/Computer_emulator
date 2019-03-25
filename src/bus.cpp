#include "bus.h"

Bus::Bus(){}

Bus::Bus(Ram *pointerRAM)
{
    pRAM = pointerRAM;
}

//CPU read from bus
int Bus::read(int address)
{
    address_bus = address;
    if(address_bus < RAM_SIZE)
    {
        data_bus = pRAM->read(address_bus);
    }
    return data_bus;
}

//CPu write to bus
void Bus::write(int address, int value)
{
    address_bus = address;
    data_bus = value;
    if(address_bus < RAM_SIZE)
    {
        pRAM->write(address_bus, data_bus);
    }
}