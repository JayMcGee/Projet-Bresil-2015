
#define DEVICE "28-000006052315"

#include "commun.h"

using namespace std;


int main(int argc, char * argv[])
{
    cout << "Preparing to read in one wire device file" << endl;
    
    OneWireDevice ow(DEVICE);
    
    cout << "Device created succesfully" << endl;
    
    float temp;
    
    if(ow.isValidPath())
    {
        cout << "Device path is valid" << endl;
        if(ow.updateTemperature())
        {
            cout << "Temperature updated " << endl;
            if(ow.getLastTemperature(&temp))
            {
                cout << "Current temperature : " << temp << endl;
            }
            else
                cout << "Could not retrieve latest temperature" << endl;
        }
        else
            cout << "Could not update temperature" << endl;
    }
    else 
        cout << "Device path is not valid";
    
    return 1;
}