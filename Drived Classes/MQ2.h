#pragma once
#include "MQ.h"
class MQ2 : public MQ //Carbon monoxide gas sensor
{
public:
	private :
	char* data_analog_pin;
	int data_digital_pin;
	float analog_data;
	bool digital_data;
public:
	MQ2(char*,int);
    void calibrate_data();
	void Serial_print_data();

	 MQ2 operator = (MQ2);
	 MQ2 operator + (MQ2);
	 bool operator ==  (MQ2);
	 bool operator !=  (MQ2);
	 bool analog_data_cmp (MQ2,int );
	 bool digital_data_cmp (MQ2,int );

	~MQ2(void);
};

