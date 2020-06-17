#pragma once
#include "Arduino.h"

class MQ //for sensing various types of gases
{
private :
	char* data_analog_pin;
	int data_digital_pin;
	float analog_data;
	bool digital_data;
public:
	MQ(char* a="A0",int d=0);
	void intialize ();
	void read_data();
	virtual void calibrate_data();
	float get_analog_data();
	bool get_digital_data();
	int get_sensor_analog_value();
	void set_digital_data(bool);
	void set_analog_data(float);
	virtual void Serial_print_data()=0;


	~MQ(void);
};

