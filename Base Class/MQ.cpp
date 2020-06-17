#include "MQ.h"
/**************************-**********************************
*															 *
				   Utility functions
*															 *
***************************-*********************************/
void MQ::calibrate_data()
{
 read_data();

}
/**************************-**********************************
*															 *
					Intilaization
*															 *
***************************-*********************************/
MQ::MQ(char* a="A0",int d=0)
{
	if (d>=0&&d<=13) data_digital_pin=d;
	else data_digital_pin=d;
	if (a=="A0"||a=="A1"||a=="A2"||a=="A3"||a=="A4"||a=="A5") data_analog_pin=a;
	else
	data_analog_pin="A0";

	intialize();
}
void MQ:: intialize ()
{
	pinMode(data_analog_pin, INPUT);
	pinMode(data_digital_pin, INPUT);
}
void MQ::read_data()
{
	digital_data= digitalRead(data_digital_pin);
	analog_data = analogRead(data_analog_pin)/1023.0*5; // converts the bits into voltages
}
/**************************-**********************************
*															 *
						Setters
*															 *
***************************-*********************************/
void  MQ::set_analog_data(float a)
{
	analog_data=a;
}
void  MQ::set_digital_data(bool d)
{
	digital_data=d;
}
/**************************-**********************************
*															 *
						Getters
*															 *
***************************-*********************************/
int MQ::get_sensor_analog_value()
{
	return analogRead(data_analog_pin);
}
float MQ::get_analog_data()
{
	calibrate_data();
	return analog_data;
}
bool MQ:: get_digital_data()
{
	read_data();
	return digital_data;
}
void MQ::Serial_print_data()
{

}



MQ::~MQ(void)
{
}
