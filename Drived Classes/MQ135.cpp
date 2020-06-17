#include "MQ135.h"


MQ135::MQ135(char* p="A0",int d=0):MQ(p,d)
{
	data_analog_pin=p;
	data_digital_pin=d;
}
void MQ135::calibrate_data()
{
	//should be heated for 24 hours, and left it in open air,
	//constrain (analog_data,2.5,4.3);//limits the digital data from 2.5 to 4.3
  map (analog_data,0,5,10, 2000); //mapping the data to the  operating voltage (from the datasheet) , we can use the division operation below instead
  analog_data = analog_data; // expressing the data in terms of ppm instead of voltages (from the datasheet)
}
void MQ135::Serial_print_data()
{
  Serial.print ("MQ135");
  Serial.print (" : ");
   Serial.print (" CO2  = ");
   Serial.print (analog_data);
  Serial.print (" PPM  ,the conc is ");
  if (digital_data) Serial.print ("High"); return;
  Serial.print ("Low");


}


MQ135 MQ135::operator = (MQ135 passed)
{
 analog_data=passed.get_analog_data();
 digital_data= passed.get_digital_data();
}
MQ135 MQ135::operator + (MQ135 passed)
{

	MQ135 tempo;
	tempo.set_analog_data((passed.get_analog_data()+analog_data)/2);
	tempo.set_digital_data((passed.get_digital_data()+digital_data)/2);

}

bool MQ135::analog_data_cmp (MQ135 passed,int error=10)
{
	if((error >0&&error <101)) error =10;

	float analog_data_error=((analog_data+passed.get_analog_data())/200*error);
	if ((analog_data>passed.get_analog_data())>analog_data_error) return 1;
	if ((analog_data>passed.get_analog_data())<analog_data_error) return -1;
	return 0;
}
bool MQ135::digital_data_cmp (MQ135 passed,int error=10)
{
 if((error >0&&error <101)) error =10;

	float digital_data_error=((digital_data+passed.get_digital_data())/200*error);
	if ((digital_data>passed.get_analog_data())>digital_data_error) return 1;
	if ((digital_data>passed.get_analog_data())<digital_data_error) return -1;
	return 0;
}

bool MQ135::operator ==  (MQ135 passed)
{
	return (analog_data_cmp (passed,10)&&digital_data_cmp(passed ,10)) ;

}
bool MQ135::operator !=  (MQ135 passed)
{
	return (!(*this==passed));
}
MQ135::~MQ135(void)
{

}
