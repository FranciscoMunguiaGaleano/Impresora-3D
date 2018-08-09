#include<16f1454.h>
#fuses NOWDT,NOPROTECT,NOLVP,NOMCLR,INTRC_IO
#use delay(internal=48000000)
#use standard_io(A)
#use standard_io(c)
#use I2C(SLAVE,slow,scl=PIN_C0,sda=PIN_C1,address=0xc0)
int num=2,n=0,estado,i=0,begin=0,eject,p,t,casa=0;
int32 tiempo,pasos,buffer,j,array[8],k,direccion;
void Parametros()
{
   tiempo=0;
   buffer=array[0]*10000;
   tiempo=tiempo+buffer;
   buffer=array[2]*100;
   tiempo=tiempo+buffer;
   buffer=array[4];
   tiempo=tiempo+buffer;
   pasos=0;
   buffer=array[1]*10000;
   pasos=pasos+buffer;
   buffer=array[3]*100;
   pasos=pasos+buffer;
   buffer=array[5];
   pasos=pasos+buffer;
   direccion=array[6];
}
void stop()
{
   k=0;
   while(k<tiempo)
   {
      #asm
      nop
      nop
      nop
      nop
      nop
      nop
      nop
      nop
      nop
      nop
      nop
      nop
      #endasm
      k++;
   }
}

void pulso()
{
   j=0;
   while(j<pasos)
   {
      output_high(PIN_A5);
      stop();
      output_low(PIN_A5);
      stop();
      j++;
   }
}
void Home()
{
while(input(PIN_C2)==0)
{
   tiempo=0x000060;
   output_low(PIN_A4);
   while(input(PIN_C2)==0)
   {
      output_high(PIN_A5);
      stop();
      output_low(PIN_A5);
      stop();
   }
   output_high(PIN_A4);
   pasos=800;
   for(j=0;j<=pasos;j++)
   {
      output_high(PIN_A5);
      stop();
      output_low(PIN_A5);
      stop();  
   }
   output_low(PIN_A4);
   tiempo=0x00000340;
   while(input(PIN_C2)==0)
   {
      output_high(PIN_A5);
      stop();
      output_low(PIN_A5);
      stop();
   }
}
}
#INT_SSP
void intrr_i2c()
{
int incoming;
incoming=i2c_read();
estado=i2c_isr_state();
   if(estado==1)
   {
      array[n]=incoming;
      n++;
   }
   if(estado==2)
   {
      array[n]=incoming;
      n++;
   }
   if(estado==3)
   {
      array[n]=incoming;
      n=0;
      Parametros();
      if(direccion==1)
      {
         output_low(PIN_A4);  
         begin=1;
      }
      if(direccion==0)
      {
         output_high(PIN_A4);
         begin=1;
      }
      if(direccion==2)
      {
         casa=1;
         begin=0;
      }
   }
}

void main()
{
   output_high(PIN_C4);
   enable_interrupts(INT_SSP);
   enable_interrupts(GLOBAL);
   output_low(PIN_A5);
   while(1)
   {
      if(begin==1 && (input(PIN_C5)==1) && casa==0)
      {
         output_low(PIN_C4);
         pulso();
         begin=0;
         output_high(PIN_C4);
      }
      if(casa==1 && (input(PIN_C5)==1))
      {
         output_low(PIN_C4);
         Home();
         casa=0;
         output_high(PIN_C4);
      }
   }
}
