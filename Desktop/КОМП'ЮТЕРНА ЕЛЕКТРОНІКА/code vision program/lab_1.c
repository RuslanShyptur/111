

#include <mega64.h>
#include <delay.h>

void main(void)
{

 PORTD=0b00000001;
 DDRD=0b00000010;

while (1)
{
    while (PIND.0==1){
    PORTD.1=1;
      PORTD.1=0;
      PORTD.2=1;
      PORTD.3=1;
      delay_ms(500);
      PORTD.3=0;
      delay_ms(500);
                     }
      
      
    while (PIND.0==0){ 
    PORTD.1=1;
    PORTD.2=1;
    delay_ms(500);
    PORTD.2=0;
    delay_ms(500);   
                     }
                     };  
     
}
