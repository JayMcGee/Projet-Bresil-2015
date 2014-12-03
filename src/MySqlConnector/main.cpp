
#define DEVICE "28-000006052315"
#include <stdlib.h>
#include <iostream>
#include <mysql_connection.h>
#include <driver.h>
#include <exception.h>
#include <resultset.h>
#include <statement.h>
#include "FileRead/OneWireDevice.h"

using namespace sql;
using namespace std;
int main(void){
    
//Declaration Objet
    OneWireDevice ow(DEVICE);
    float temp;
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;
    
//Connection    
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306","root","poutine");
    
    
    while(1)
    {
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
        sleep(2);
        
    //Query
        stmt = con->createStatement();
        stmt->execute("USE stationmeteocegep;");
        /* res = stmt->executeQuery("SELECT stationID FROM datastation LIMIT 4;");
        
        while(res->next())
        {
            
            cout << "ID station : " << res->getInt(1) << endl;
            
        }
        */
    }    
    delete res;
    delete stmt;
    delete con;

    return 0;
}