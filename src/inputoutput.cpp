#include "inputoutput.h"

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
    cin >> dec >> val;
    return val;
}

int InputOutput::read()
{
    return val;
}

void InputOutput::write(int value)
{
    val = value;
	cout << dec << val << "\n";
}