#include "OneWireDevice.h"

OneWireDevice::OneWireDevice()
{
    filePath_ = createFilePath("28-000006052315");
    if(exists_test(filePath_))
        hasValidPath_ = true;
    else
        hasValidPath_ = false;
        
    hasUpdated_ = false;
    lastTemperature_ = 0.0f;
}

OneWireDevice::OneWireDevice(string deviceID)
{
    filePath_ = createFilePath(deviceID);
    if(exists_test(filePath_))
        hasValidPath_ = true;
    else
        hasValidPath_ = false;
        
    hasUpdated_ = false;
    lastTemperature_ = 0.0f;
}

OneWireDevice::~OneWireDevice()
{
    
}

string OneWireDevice::createFilePath(string deviceID)
{
    return FILE_PATH + deviceID + END_PATH;
}
    
bool OneWireDevice::updateTemperature()
{
    if(hasValidPath_)
    {
        ifstream onewireFin(filePath_);
    
        string data = "";
        
        string temp = "";
        
        while(onewireFin.good())
        {
            onewireFin >> temp;
            
            data += temp;
        }
        
        temp = data;
        
        size_t found = temp.find_last_of('=');
        
        if(found != string::npos)
        {
            data = temp.substr(found + 1);
            
            lastTemperature_ = stof(data) / 1000;
            
            return(hasUpdated_ = true);
        }
        else
        {
            return (hasUpdated_ = false);
        }
    }
    return false;
}

bool OneWireDevice::isValidPath()
{
    return (hasValidPath_ = exists_test(filePath_));
}
        
bool OneWireDevice::getLastTemperature(float * temperature)
{
    if(hasUpdated_)
    {
        *temperature = lastTemperature_;
    }
    return hasUpdated_;
}