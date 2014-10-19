#include <iostream>
#include "SIM.h"

using namespace std;

int main(int argc, char * argv[])
{
    cout << "Creating SIM900 connection .. " << endl;
    
    BlackUART port(UART1, Baud115200, ParityNo, StopOne, Char8);
    
    if(port.open(ReadWrite | NonBlock))
    {
        cout << "Port opened succesfully" << endl;
        
        SIM900 sim(&port);
    
        sim.getState();
        
        port.close();
    }
    else
        cout << "Port did not open" << endl;
    while(1)
    {
        
    }
    return 1;
}

