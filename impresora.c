#include<16f1454.h>
#fuses NOWDT,NOPROTECT,NOLVP,NOMCLR,INTRC_IO
#use delay(internal=48000000)
#use standard_io(A)
#use standard_io(c)
#use I2C(master, sda=PIN_C3,scl=PIN_C4,slow)
#include <usb_cdc.h>
INT8 datos,n=0,cadena[26];
void Esclavo_1()
{
   i2c_start();
   i2c_write(0xa0);
   i2c_write(datos);
   i2c_stop();
}
void Esclavo_2()
{
   i2c_start();
   i2c_write(0xb0);
   i2c_write(datos);
   i2c_write(0x00);
   i2c_stop();
}
void Esclavo_3()
{
   i2c_start();
   i2c_write(0xc0);
   i2c_write(datos);
   i2c_write(0x00);
   i2c_stop();
}
void Esclavo_4()
{
   i2c_start();
   i2c_write(0xd0);
   i2c_write(datos);
   i2c_write(0x00);
   i2c_stop();
}
void Esclavo_5()
{
   i2c_start();
   i2c_write(0xe0);
   i2c_write(datos);
   i2c_write(0x00);
   i2c_stop();
}
void Esclavo_6()
{
   i2c_start();
   i2c_write(0xf0);
   i2c_write(datos);
   i2c_write(0x00);
   i2c_stop();
}
int32 tiempo_1=17500;
char dato;
int8 num;
void main()
{
   output_high(PIN_A5);
   output_high(PIN_C2);
   output_high(PIN_C1);
   output_high(PIN_C0);
   delay_ms(1000);
   output_low(PIN_A4);
   output_low(PIN_A5);
   output_low(PIN_C2);
   output_low(PIN_C1);
   output_low(PIN_C0);
   delay_ms(500);
   i2c_start();
   i2c_write(0xa0);
   i2c_stop();

enable_interrupts(GLOBAL);
usb_cdc_init();
usb_init();
do 
{
usb_task();
if (usb_enumerated())
{
if(usb_cdc_kbhit())
   {
         dato= usb_cdc_getc();
//!         if (dato>=0x30 && dato<=0x40)
//!         {
//!            num=dato-48;
//!         }
//!         if (dato>=0x41 && dato<=0x46)
//!         {
//!            num=dato-49;
//!         }
         n=n+1;
         if (n==26)
         {
            n=0;
            delay_ms(1000);
            if(cadena[0]==0x01)
            {
                  printf(usb_cdc_putc,"Impresora      "); 
            }
            if(cadena[0]==0x0a)
            {
                  printf(usb_cdc_putc,"Linea recta    ");
            }
         }
         else
         {
         cadena[n]=num;
         }
//!         switch (num)
//!         {
//!            case 1:
//!            {
//!               output_high(PIN_A4);
//!               printf(usb_cdc_putc,"\n\rEje x adelante");
//!               //***************
//!               i2c_start();
//!               i2c_write(0xa0);
//!               datos=0x00;
//!               i2c_write(datos);
//!               datos=0x00;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xa0);
//!               datos=0x00;
//!               i2c_write(datos);
//!               datos=0x03;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xa0);
//!               datos=0x71;
//!               i2c_write(datos);
//!               datos=0x20;
//!               i2c_write(datos);
//!               datos=0x00;
//!               i2c_write(datos);
//!               i2c_stop();
//!               delay_ms(300);
//!               while(input(PIN_C5)==0);
//!               printf(usb_cdc_putc,"\n\radelante");
//!               i2c_start();
//!               i2c_write(0xa0);
//!               datos=0x00;
//!               i2c_write(datos);
//!               datos=0x00;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xa0);
//!               datos=0x00;
//!               i2c_write(datos);
//!               datos=0x03;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xa0);
//!               datos=0x40;
//!               i2c_write(datos);
//!               datos=0x20;
//!               i2c_write(datos);
//!               datos=0x00;
//!               i2c_write(datos);
//!               i2c_stop();
//!               break;
//!            }
//!            case 2:
//!            {
//!               output_high(PIN_A4);
//!               printf(usb_cdc_putc,"\n\rEje x atras");
//!               //***************
//!               i2c_start();
//!               i2c_write(0xa0);
//!               datos=0x00;
//!               i2c_write(datos);
//!               datos=0x00;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xa0);
//!               datos=0x00;
//!               i2c_write(datos);
//!               datos=0x01;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xa0);
//!               datos=0x71;
//!               i2c_write(datos);
//!               datos=0xFF;
//!               i2c_write(datos);
//!               datos=0x02;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               delay_ms(500);
//!               output_high(PIN_A4);
//!               delay_ms(300);
//!               output_low(PIN_A4);
//!               while(input(PIN_C5)==1);
//!               //***************
//!               i2c_start();
//!               i2c_write(0xa0);
//!               datos=0x0F;
//!               i2c_write(datos);
//!               datos=0x00;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xa0);
//!               datos=0x42;
//!               i2c_write(datos);
//!               datos=0x00;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xa0);
//!               datos=0x40;
//!               i2c_write(datos);
//!               datos=0x0A;
//!               i2c_write(datos);
//!               datos=0x00;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               delay_ms(1000);
//!               output_high(PIN_A4);
//!               delay_ms(300);
//!               output_low(PIN_A4);
//!               break;
//!            }
//!            case 3:
//!            {
//!               output_high(PIN_A4);
//!               printf(usb_cdc_putc,"\n\rEje z abajo");
//!               //***************
//!               i2c_start();
//!               i2c_write(0xb0);
//!               datos=0x00;
//!               i2c_write(datos);
//!               datos=0x00;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xb0);
//!               datos=0x00;
//!               i2c_write(datos);
//!               datos=0x01;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xb0);
//!               datos=0x71;
//!               i2c_write(datos);
//!               datos=0xFF;
//!               i2c_write(datos);
//!               datos=0x02;
//!               i2c_write(datos);
//!               i2c_stop();
//!
//!               break;
//!            }
//!            case 4:
//!            {
//!               output_high(PIN_A4);
//!               printf(usb_cdc_putc,"\n\r Eje z arriba");
//!               //***************
//!               i2c_start();
//!               i2c_write(0xb0);
//!               datos=0x00;
//!               i2c_write(datos);
//!               datos=0x00;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xb0);
//!               datos=0x00;
//!               i2c_write(datos);
//!               datos=0x01;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xb0);
//!               datos=0x71;
//!               i2c_write(datos);
//!               datos=0xFF;
//!               i2c_write(datos);
//!               datos=0x01;
//!               i2c_write(datos);
//!               i2c_stop();
//!
//!               break;
//!            }
//!            case 5:
//!            {
//!               output_high(PIN_A4);
//!               printf(usb_cdc_putc,"\n\rEje y derecha");
//!               //***************
//!               i2c_start();
//!               i2c_write(0xc0);
//!               datos=0x00;
//!               i2c_write(datos);
//!               datos=0x00;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xc0);
//!               datos=0x00;
//!               i2c_write(datos);
//!               datos=0x01;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xc0);
//!               datos=0x71;
//!               i2c_write(datos);
//!               datos=0xFF;
//!               i2c_write(datos);
//!               datos=0x00;
//!               i2c_write(datos);
//!               i2c_stop();
//!
//!               break;
//!            }
//!            case 6:
//!            {
//!               output_high(PIN_A4);
//!               printf(usb_cdc_putc,"\n\r Eje y izquierda");
//!               //***************
//!               i2c_start();
//!               i2c_write(0xc0);
//!               datos=0x00;
//!               i2c_write(datos);
//!               datos=0x00;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xc0);
//!               datos=0x00;
//!               i2c_write(datos);
//!               datos=0x01;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xc0);
//!               datos=0x71;
//!               i2c_write(datos);
//!               datos=0xFF;
//!               i2c_write(datos);
//!               datos=0x02;
//!               i2c_write(datos);
//!               i2c_stop();
//!
//!               break;
//!            }
//!            case 7:
//!            {
//!               output_high(PIN_A4);
//!               printf(usb_cdc_putc,"\n\rExtrusor menos");
//!               //***************
//!               i2c_start();
//!               i2c_write(0xd0);
//!               datos=0x00;
//!               i2c_write(datos);
//!               datos=0x00;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xd0);
//!               datos=0x00;
//!               i2c_write(datos);
//!               datos=0x01;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xd0);
//!               datos=0x71;
//!               i2c_write(datos);
//!               datos=0xFF;
//!               i2c_write(datos);
//!               datos=0x00;
//!               i2c_write(datos);
//!               i2c_stop();
//!
//!               break;
//!            }
//!            case 8:
//!            {
//!               output_low(PIN_A4);
//!               printf(usb_cdc_putc,"\n\r Extrusor mas");
//!               //***************
//!               i2c_start();
//!               i2c_write(0xd0);
//!               datos=0x00;
//!               i2c_write(datos);
//!               datos=0x00;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xd0);
//!               datos=0x00;
//!               i2c_write(datos);
//!               datos=0x01;
//!               i2c_write(datos);
//!               i2c_stop();
//!               //**************
//!               i2c_start();
//!               i2c_write(0xd0);
//!               datos=0x71;
//!               i2c_write(datos);
//!               datos=0xFF;
//!               i2c_write(datos);
//!               datos=0x01;
//!               i2c_write(datos);
//!               i2c_stop();
//!
//!               break;
//!            }
//!            default:
//!            {
//!               break;
//!            }
//!         }
   }
}
}
while(1);
}
