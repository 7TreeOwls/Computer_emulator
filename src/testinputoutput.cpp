#include "inputoutput.h"

using namespace std;

int main()
{
    InputOutput iomodule(128);

    cout << iomodule.address << "\n";

    int result;

    result = iomodule.read_new();

    iomodule.write(result);

    result = iomodule.read();

    cout << result << "\n";
    
    return 0;
}