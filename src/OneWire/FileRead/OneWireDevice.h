#ifndef ONE_WIRE_H
#define ONE_WIRE_H

#define FILE_PATH "/sys/devices/w1_bus_master1/"
#define END_PATH "/w1_slave"

#include "commun.h"

class OneWireDevice
{
    private:
        string filePath_;
        float lastTemperature_;
        bool hasUpdated_;
        bool hasValidPath_;
        
        string createFilePath(string deviceID);
        
    public:
        OneWireDevice();
        OneWireDevice(string deviceID);
        ~OneWireDevice();
        
        bool updateTemperature();
        
        bool isValidPath();
        
        bool getLastTemperature(float * temperature);
};

#endif
