#include "MQ307.h"


MQ307::MQ307(char* p="A0",int d=0):MQ(p,d)
{

	data_analog_pin=p;
	data_digital_pin=d;
}
void MQ307::calibrate_data()
{
  constrain (analog_data,2.5,4.3);//limits the digital data from 2.5 to 4.3
 // map (analog_data,2.5,4.3,0,500); //mapping the data to the  operating voltage (from the datasheet) , we can use the division operation below instead
  analog_data = analog_data*500.0/4.3; // expressing the data in terms of ppm instead of voltages (from the datasheet)
}
void MQ307::Serial_print_data()
{
  Serial.print ("MQ307");
  Serial.print (" : ");
   Serial.print (" CO = ");
   Serial.print (analog_data);
  Serial.print (" PPM  ,the conc is ");
  if (digital_data) Serial.print ("High"); return;
  Serial.print ("Low");


}


MQ307 MQ307::operator = (MQ307 passed)
{
 analog_data=passed.get_analog_data();
 digital_data= passed.get_digital_data();
}
MQ307 MQ307::operator + (MQ307 passed)
{

	MQ307 tempo;
	tempo.set_analog_data((passed.get_analog_data()+analog_data)/2);
	tempo.set_digital_data((passed.get_digital_data()+digital_data)/2);

}

bool MQ307::analog_data_cmp (MQ307 passed,int error=10)
{
	if((error >0&&error <101)) error =10;

	float analog_data_error=((analog_data+passed.get_analog_data())/200*error);
	if ((analog_data>passed.get_analog_data())>analog_data_error) return 1;
	if ((analog_data>passed.get_analog_data())<analog_data_error) return -1;
	return 0;
}
bool MQ307::digital_data_cmp (MQ307 passed,int error=10)
{
 if((error >0&&error <101)) error =10;

	float digital_data_error=((digital_data+passed.get_digital_data())/200*error);
	if ((digital_data>passed.get_analog_data())>digital_data_error) return 1;
	if ((digital_data>passed.get_analog_data())<digital_data_error) return -1;
	return 0;
}

bool MQ307::operator ==  (MQ307 passed)
{
	return (analog_data_cmp (passed,10)&&digital_data_cmp(passed ,10)) ;

}
bool MQ307::operator !=  (MQ307 passed)
{
	return (!(*this==passed));
}
MQ307::~MQ307(void)
{

}
