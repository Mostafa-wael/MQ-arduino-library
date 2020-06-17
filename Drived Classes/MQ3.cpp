#include "MQ3.h"


MQ3::MQ3(char* p="A0",int d=0):MQ(p,d)
{
	data_analog_pin=p;
	data_digital_pin=d;
}
void MQ3::calibrate_data()
{
	analog_data/5*1023;

}
void MQ3::Serial_print_data()
{
  Serial.print ("MQ3");
  Serial.print (" : ");
   Serial.print (" value = ");
   Serial.print (analog_data);
  Serial.print (" and is ");
  if (digital_data) Serial.print ("High"); return;
  Serial.print ("Low");


}


MQ3 MQ3::operator = (MQ3 passed)
{
 analog_data=passed.get_analog_data();
 digital_data= passed.get_digital_data();
}
MQ3 MQ3::operator + (MQ3 passed)
{

	MQ3 tempo;
	tempo.set_analog_data((passed.get_analog_data()+analog_data)/2);
	tempo.set_digital_data((passed.get_digital_data()+digital_data)/2);

}

bool MQ3::analog_data_cmp (MQ3 passed,int error=10)
{
	if((error >0&&error <101)) error =10;

	float analog_data_error=((analog_data+passed.get_analog_data())/200*error);
	if ((analog_data>passed.get_analog_data())>analog_data_error) return 1;
	if ((analog_data>passed.get_analog_data())<analog_data_error) return -1;
	return 0;
}
bool MQ3::digital_data_cmp (MQ3 passed,int error=10)
{
 if((error >0&&error <101)) error =10;

	float digital_data_error=((digital_data+passed.get_digital_data())/200*error);
	if ((digital_data>passed.get_analog_data())>digital_data_error) return 1;
	if ((digital_data>passed.get_analog_data())<digital_data_error) return -1;
	return 0;
}

bool MQ3::operator ==  (MQ3 passed)
{
	return (analog_data_cmp (passed,10)&&digital_data_cmp(passed ,10)) ;

}
bool MQ3::operator !=  (MQ3 passed)
{
	return (!(*this==passed));
}
MQ3::~MQ3(void)
{

}
