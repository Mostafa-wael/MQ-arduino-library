#include <MQ7.h>

MQ7 temp(A0,0); // it has 2-pins: A0 & 0
void setup() {

}

void loop() {
 temp.read_data();
 temp.calibrate_data();
 temp.Serial_print_data();

}
