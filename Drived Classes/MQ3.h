#pragma once
#include "MQ.h"
class MQ3 : public MQ //Ethanol sensor
{
public:
	private :
	char* data_analog_pin;
	int data_digital_pin;
	float analog_data;
	bool digital_data;
public:
	MQ3(char*,int);
    void calibrate_data();
	void Serial_print_data();

	 MQ3 operator = (MQ3);
	 MQ3 operator + (MQ3);
	 bool operator ==  (MQ3);
	 bool operator !=  (MQ3);
	 bool analog_data_cmp (MQ3,int );
	 bool digital_data_cmp (MQ3,int );

	~MQ3(void);

};



