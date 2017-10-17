#include <mega128.h>
#include <delay.h>

 static flash unsigned char digit[] = {
    (0b00111111),     // 0
    (0b00000110),     // 1
    (0b01011011),     // 2
    (0b01001111),     // 3
    (0b01100110),     // 4
    (0b01101101),     // 5
    (0b01111101),     // 6
    (0b00000111),     // 7
    (0b01111111),     // 8
    (0b01101111),     // 9
 };   
 
 unsigned char m;
 
 void ind(unsigned char chislo){
 
   unsigned char desjatki=0;
  
  while (chislo>=10) {
  chislo-=10;
  desjatki++;
  }
  
  if(m==0){
  PORTB.0=1;
  PORTD=digit[desjatki];
  delay_ms(5);
  PORTB.0=0;
  PORTB.1=1;
  PORTD=digit[chislo];
  delay_ms(5);
  PORTB.1=0;
  m=1; 
  }
  else{
  PORTB.2=1;
  PORTD=digit[desjatki];
  delay_ms(5);
  PORTB.2=0;
  PORTB.3=1;
  PORTD=digit[chislo];
  delay_ms(5);
  PORTB.3=0;
  m=0;
  
  }
  
 }

void main(void)
 {
 PORTB=0x00;
 DDRB=0b00001111;
 
 PORTD=0x00;
 DDRD=0b01111111;
 
 while (1)
        {
        ind(00);
        ind(17);
        delay_ms(1000);
        ind(17);
        ind(8);
        delay_ms(1000);
        };
}