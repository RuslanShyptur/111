
#include <mega64.h>
#include <alcd.h>

void main(void)
{
lcd_init(16);
lcd_clear();
      lcd_gotoxy(0,0);
      lcd_putsf("Shyptur");
      lcd_gotoxy(0,1);
      lcd_putsf("Ruslan");
      lcd_gotoxy(14,1);
      lcd_putsf("17");
    while(1){};
}    
