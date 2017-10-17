
#include <mega64.h>
#include <alcd.h>
#asm
void main(void)
{
lcd_init(16);
lcd_clear();
#pragma rl+
      lcd_gotoxy(0,0);
      lcd_putsf("Шиптур");
      lcd_gotoxy(0,1);
      lcd_putsf("Руслан");
      lcd_gotoxy(14,1);
      lcd_putsf("17");
#pragma rl-
    while(1){};
}    
#endasm