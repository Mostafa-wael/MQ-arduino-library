#include "MQ2.h"


MQ2::MQ2(char* p="A0",int d=0):MQ(p,d)
{
	data_analog_pin=p;
	data_digital_pin=d;
}
void MQ2::calibrate_data()
{
  map (analog_data,0,5,300,10000); //mapping the data to the  operating voltage (from the datasheet)
  analog_data = analog_data; // expressing the data in terms of ppm instead of voltages (from the datasheet)

}
void MQ2::Serial_print_data()
{
  Serial.print ("MQ2");
  Serial.print (" : ");
   Serial.print (" Smoke = ");
   Serial.print (analog_data);
  Serial.print (" PPM  ,the conc is ");
  if (digital_data) Serial.print ("High"); return;
  Serial.print ("Low");


}


MQ2 MQ2::operator = (MQ2 passed)
{
 analog_data=passed.get_analog_data();
 digital_data= passed.get_digital_data();
}
MQ2 MQ2::operator + (MQ2 passed)
{

	MQ2 tempo;
	tempo.set_analog_data((passed.get_analog_data()+analog_data)/2);
	tempo.set_digital_data((passed.get_digital_data()+digital_data)/2);

}

bool MQ2::analog_data_cmp (MQ2 passed,int error=10)
{
	if((error >0&&error <101)) error =10;

	float analog_data_error=((analog_data+passed.get_analog_data())/200*error);
	if ((analog_data>passed.get_analog_data())>analog_data_error) return 1;
	if ((analog_data>passed.get_analog_data())<analog_data_error) return -1;
	return 0;
}
bool MQ2::digital_data_cmp (MQ2 passed,int error=10)
{
 if((error >0&&error <101)) error =10;

	float digital_data_error=((digital_data+passed.get_digital_data())/200*error);
	if ((digital_data>passed.get_analog_data())>digital_data_error) return 1;
	if ((digital_data>passed.get_analog_data())<digital_data_error) return -1;
	return 0;
}

bool MQ2::operator ==  (MQ2 passed)
{
	return (analog_data_cmp (passed,10)&&digital_data_cmp(passed ,10)) ;

}
bool MQ2::operator !=  (MQ2 passed)
{
	return (!(*this==passed));
}
MQ2::~MQ2(void)
{

}
