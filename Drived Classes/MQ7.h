#pragma once
#include "MQ.h"
static int id=0;
class MQ7 : public MQ //Carbon monoxide gas sensor
{
public:
	private :
	char* data_analog_pin;
	int data_digital_pin;
	float analog_data;
	bool digital_data;
public:
	MQ7(char*,int);
    void calibrate_data();
	void Serial_print_data();

	 MQ7 operator = (MQ7);
	 MQ7 operator + (MQ7);
	 bool operator ==  (MQ7);
	 bool operator !=  (MQ7);
	 bool analog_data_cmp (MQ7,int );
	 bool digital_data_cmp (MQ7,int );

	~MQ7(void);
};

