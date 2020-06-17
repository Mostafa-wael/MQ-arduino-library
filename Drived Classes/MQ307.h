#pragma once
#include "MQ.h"
class MQ307 : public MQ
/*Sensitive for Carbon Monoxide
The heater uses an alternating voltage of 0.2V and 0.9.
It detects the same gases as the MQ-7, but uses a lower heater voltage.
*/

{
public:
	private :
	char* data_analog_pin;
	int data_digital_pin;
	float analog_data;
	bool digital_data;
public:
	MQ307(char*,int);
    void calibrate_data();
	void Serial_print_data();

	 MQ307 operator = (MQ307);
	 MQ307 operator + (MQ307);
	 bool operator ==  (MQ307);
	 bool operator !=  (MQ307);
	 bool analog_data_cmp (MQ307,int );
	 bool digital_data_cmp (MQ307,int );

	~MQ307(void);
};

