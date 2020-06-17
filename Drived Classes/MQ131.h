#pragma once
#include "MQ.h"
class MQ131 : public MQ //ozone sensor
	/*
	Output Voltage :dVs: ≥1.0V(in 200ppm O3
	Sensitive for Ozone
	The heater uses 6V.
	The load-resistor is 100k...200k, which is a lot higher than for other sensors. This sensor is also very sensitive. It measures in ppb (parts per billion) where other sensors measure in ppm (parts per million).
	 datasheet: http://duckduckgo.com/?q=%22mq131%22+gas+sensor+filetype%3Apdf
	*/
{
	private :
	char* data_analog_pin;
	int data_digital_pin;
	float analog_data;
	bool digital_data;
public:
	MQ131(char*,int);
    void calibrate_data();
	void Serial_print_data();

	 MQ131 operator = (MQ131);
	 MQ131 operator + (MQ131);
	 bool operator ==  (MQ131);
	 bool operator !=  (MQ131);
	 bool analog_data_cmp (MQ131,int );
	 bool digital_data_cmp (MQ131,int );

	~MQ131(void);
};

