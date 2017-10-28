#include <CLOCK.h>

unsigned int8 dem=0,loc;
const int8 num[10] = {0x02, 0x9e,0x24,0x0c,0x98,0x48,0x40,0x1e,0x00,0x08};
unsigned int8 gio,phut, giay, gio1,gio2, phut1,phut2,giay1,giay2 ; 

#INT_TIMER0
void ngatTimer0()
{
   dem=dem+1;
   if(dem==76)
   {
      giay++;
      dem=0;
   }
}

void main()
{
   setup_timer_0(T0_INTERNAL|T0_DIV_256);
   set_timer0(0);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   while(1)
   {  
      if(giay==60)
      {
         delay_ms(1);
         phut++;
         giay=0;
      }
      if(phut==60)
      {
         gio++;
         phut=0;
      }
      if(gio==24)
      {
         gio=0;
      }
      giay1=giay%10;
      giay2=giay/10;
      phut1=phut%10;
      phut2=phut/10;
      gio1=gio%10;
      gio2=gio/10;
      //giay1
      output_bit(PIN_C7,1);
      output_d(num[giay1]);
      delay_ms(1);
      output_d(0xff);
      output_bit(PIN_C7,0);
      //giay2
      output_bit(PIN_C6,1);
      output_d(num[giay2]);
      delay_ms(1);
      output_d(0xff);
      output_bit(PIN_C6,0);
      //phut1
      output_bit(PIN_C5,1);
      output_d(num[phut1]);
      delay_ms(1);
      output_d(0xff);
      output_bit(PIN_C5,0);
      //phut2
      output_bit(PIN_C4,1);
      output_d(num[phut2]);
      delay_ms(1);
      output_d(0xff);
      output_bit(PIN_C4,0);
      //gio1
      output_bit(PIN_C3,1);
      output_d(num[gio1]);
      delay_ms(1);
      output_d(0xff);
      output_bit(PIN_C3,0);
      //gio2
      output_bit(PIN_C2,1);
      output_d(num[gio2]);
      delay_ms(1);
      output_d(0xff);
      output_bit(PIN_C2,0);
      if (input(PIN_C0)==0)
     {
      gio++;
      delay_ms(200);
     }
     if (input(PIN_C1)==0)
     {
      phut++;
      delay_ms(200);
     }
   }
}
