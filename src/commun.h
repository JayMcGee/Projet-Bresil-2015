/**
*
*/


#include "SuperEasyJSON\json.h"

#define NOM_STATION "aquarius001"



namespace aquarius
{
	typedef float t_Temperature;
	typedef int t_PH;
	typedef int t_Conductivity;
	typedef int t_DO;
	typedef int t_Humidity;

	// Data structure to pass all sensor data easily
	struct SensorData
	{
		t_PH water_ph;
		t_DO water_do;
		t_Conductivity water_conduc;
		t_Temperature water_temp;
		t_Temperature case_temp;
		t_Humidity case_humidity;
	};

}