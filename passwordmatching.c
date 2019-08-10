#include<avr/io.h>
#include<util/delay.h>
void lcd_init()
{
 lcd_cmd(0x02);
 lcd_cmd(0x28);
 lcd_cmd(0x0c);
 lcd_cmd(0x06);
 lcd_cmd(0x01);
}
 void lcd_cmd(int cmd)
 {
  PORTB=cmd & 0xf0;  //for upper bit;
  PORTB=PORTB+0x04; 
  _delay_ms(1);
  PORTB=PORTB-0x04;
  PORTB=(cmd<<4)&0xf0;      //for lower bit;
  PORTB=PORTB+0x04;     
  _delay_ms(1);
  PORTB=PORTB-0x04;
  }
   void lcd_data(int data)
   {
    PORTB=data&0xf0;
	PORTB=PORTB+0x05;
    _delay_ms(1);
	PORTB=PORTB-0x04;
	PORTB=(data<<4)&0xf0;
	PORTB=PORTB+0x05;
	_delay_ms(1);
	PORTB=PORTB-0x04;
   }
  void lcd_string(char *str)
   {
    int i=0;
	while(str[i]!='\0')
	{
	 lcd_data(str[i]);
	 //_delay_ms(1);
	 i++;
	 }
	 }
     void lcd_num(int num)
	 {
	  int a=0;
	  if(num==0)
	  {
	   lcd_data(48);
	   }
	   lcd_cmd(0x04);
	   while(num!=0)
	   {
	    a=num%10;
		lcd_data(48+a);
		num=num/10;
		}
		lcd_cmd(0x06);
		}
    int keypad()
   {
    while(1)
	{
	 PORTD=0xef;
	 if(PIND==0xee)
	 {
	  while(PIND==0xee);
	  return 7;
	  }
	  else if(PIND==0xed)
	  {
	   while(PIND==0xed);
	   return 4;
	   }
	   else if(PIND==0xeb)
	  {
	   while(PIND==0xeb);
	   return 1;
	   }
	   else if(PIND==0xe7)
	  {
	   while(PIND==0xe7);
	   return 10;
	   }
	   else if(PIND==0xde)
	  {
	   while(PIND==0xde);
	   return 8;
	   }
	   else if(PIND==0xdd)
	  {
	   while(PIND==0xdd);
	   return 5;
	   }
       else if(PIND==0xdb)
	  {
	   while(PIND==0xdb);
	   return 2;
	   }
	   else if(PIND==0xd7)
	  {
	   while(PIND==0xd7);
	   return 0;
	   }
	   else if(PIND==0xbe)
	  {
	   while(PIND==0xbe);
	   return 9;
	   }
	   else if(PIND==0xbd)
	  {
	   while(PIND==0xbd);
	   return 6;
	   }

	   else if(PIND==0xbb)
	  {
	   while(PIND==0xbb);
	   return 3;
	   }
	   else if(PIND==0xb7)
	  {
	   while(PIND==0xb7);
	   return 11;
	   }
	   else if(PIND==0x7e)
	  {
	   while(PIND==0x7e);
	   return 12;
	   }
	   else if(PIND==0x7d)
	  {
	   while(PIND==0x7d);
	   return 13;
	   }
	   else if(PIND==0x7b)
	  {
	   while(PIND==0x7b);
	   return 14;
	   }
	   else if(PIND==0x77)
	  {
	   while(PIND==0x77);
	   return 15;
	   }
	   }
	   int main()
	   {
	    DDRB=0xff;
		DDRD=0xf0;
		lcd_init();
		_delay_ms(10);
		while(1)
		{
		 int a=keypad();
		 lcd_cmd(0x01);
		 lcd_cmd(0x87);
		 lcd_cmd(a);
		 }
		}
