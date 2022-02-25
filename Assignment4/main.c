//Turns LED on and off
#include <avr/io.h>
#include <util/delay.h>

 
int main (void)
{
	
	
  /* Arduino boards have a LED at PB5 */
 //set PB5, pin 13 of arduino as output
 
 DDRD   |= 0b00000000;



 DDRB   |= ((1 << DDB5));
  while (1) {

 int i = PIND;
 int u,v,w,a,b,output;
     
     w= i & 0b00000100;
     v= i & 0b00001000;
     u= i & 0b00010000;
	a=!(!(w&&w)&&v);
        b=!(!(v&&v)&&!(u&&u));
         output=!(!(!(a&&a)&&!(a&&a))&& !(!(b&&b)&&!(b&&b)));

if(output==1)
PORTB = ((1 <<  PB5));
else
PORTB = ((0 <<  PB5));

  }

  /* . */
  return 0;

}
