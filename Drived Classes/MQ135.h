#pragma once
#include "MQ.h"
class MQ135 : public MQ //Carbon monoxide gas sensor
{
public:
	private :
	char* data_analog_pin;
	int data_digital_pin;
	float analog_data;
	bool digital_data;
public:
	MQ135(char*,int);
    void calibrate_data();
	void Serial_print_data();

	 MQ135 operator = (MQ135);
	 MQ135 operator + (MQ135);
	 bool operator ==  (MQ135);
	 bool operator !=  (MQ135);
	 bool analog_data_cmp (MQ135,int );
	 bool digital_data_cmp (MQ135,int );

	~MQ135(void);
};

