#include <iostream>

#include "ram.h"
#include "bus.h"
#include "cpu.h"

using namespace std;

int main()
{
    Ram RAM;
    Bus BUS(&RAM);
    RAM.write(FIRST_INSTR, 0x32770079);
    // RAM.write(FIRST_INSTR+1, 0x0F000000);
    RAM.write(FIRST_INSTR+1, 0x02777879);
    RAM.write(FIRST_INSTR+2, 0x03777879);
    RAM.write(FIRST_INSTR+3, 0x04777879);
    RAM.write(FIRST_INSTR+4, 0x05777879);
    RAM.write(FIRST_INSTR+5, 0x06777879);

    RAM.write(FIRST_INSTR+6, 0x10777879);
    RAM.write(FIRST_INSTR+7, 0x11777879);

    RAM.write(FIRST_INSTR+8, 0x30777879);
    RAM.write(FIRST_INSTR+9, 0x31777879);
    RAM.write(FIRST_INSTR+10, 0x32777879);
    RAM.write(FIRST_INSTR+11, 0x33777879);
    RAM.write(FIRST_INSTR+12, 0x34777879);
    RAM.write(FIRST_INSTR+13, 0x35777879);
    RAM.write(FIRST_INSTR+14, 0x36777879);

    RAM.write(FIRST_INSTR+15, 0x50147879);
    RAM.write(FIRST_INSTR+16, 0x51157879);

    Cpu CPU(&BUS);
    CPU.run();

    // for(int i=0; i<18; i++)
    // {
    //     CPU.update();
    // }

    // CPU.update();
    
    return 0;
}