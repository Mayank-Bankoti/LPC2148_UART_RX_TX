#include "LPC214X.h"

unsigned char receive()
{
	while(!(U0LSR & 0x01));
	return (U0RBR);
}

void transmit(unsigned char ch)
{
 while (!(U0LSR & 0x20));
 
 U0THR =ch;
}


int main()
 {
 	 unsigned char key;
	 unsigned char  temp[30] = "Welcome to FC" ;
 	 PINSEL0 = 5;
	 U0LCR = 0x83;
	 U0DLM =0x00;
	 U0DLL =97;
	 U0LCR =0x03;
	 while(1)
	 {
	 	key = receive();
		transmit(key);
	 }
	 return 0;
}