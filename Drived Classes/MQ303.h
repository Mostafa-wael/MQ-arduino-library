#pragma once
#include "MQ.h"
class MQ303 : public MQ
/*Sensitive for Alcohol, Ethanol, smoke (just like the MQ-3)
The heater uses 0.9V
It detects the same gases as the MQ-3, but uses a lower heater voltage.
*/
{
public:
	private :
	char* data_analog_pin;
	int data_digital_pin;
	float analog_data;
	bool digital_data;
public:
	MQ303(char*,int);
    void calibrate_data();
	void Serial_print_data();

	 MQ303 operator = (MQ303);
	 MQ303 operator + (MQ303);
	 bool operator ==  (MQ303);
	 bool operator !=  (MQ303);
	 bool analog_data_cmp (MQ303,int );
	 bool digital_data_cmp (MQ303,int );

	~MQ303(void);

};



