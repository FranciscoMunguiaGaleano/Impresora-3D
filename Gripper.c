#include<16f1454.h>
#fuses NOWDT,NOPROTECT,NOLVP,NOMCLR,INTRC_IO
#use delay(internal=48000000)
#use standard_io(A)
#use standard_io(c)
#use I2C(master, sda=PIN_C3,scl=PIN_C4,slow)
#include <usb_cdc.h>
INT8 datos,datos1,datos2;
void Esclavo_1()
{
   i2c_start();
   i2c_write(0xa0);
   i2c_write(datos);
   i2c_write(datos1);
   i2c_stop();
}
void Esclavo_11()
{
   i2c_start();
   i2c_write(0xa0);
   i2c_write(datos);
   i2c_write(datos1);
   i2c_write(datos2);
   i2c_stop();
}
void Esclavo_2()
{
   i2c_start();
   i2c_write(0xb0);
   i2c_write(datos);
   i2c_write(datos1);
   i2c_stop();
}
void Esclavo_21()
{
   i2c_start();
   i2c_write(0xb0);
   i2c_write(datos);
   i2c_write(datos1);
   i2c_write(datos2);
   i2c_stop();
}
void Esclavo_3()
{
   i2c_start();
   i2c_write(0xc0);
   i2c_write(datos);
   i2c_write(datos1);
   i2c_stop();
}
void Esclavo_31()
{
   i2c_start();
   i2c_write(0xc0);
   i2c_write(datos);
   i2c_write(datos1);
   i2c_write(datos2);
   i2c_stop();
}
void Esclavo_4()
{
   i2c_start();
   i2c_write(0xd0);
   i2c_write(datos);
   i2c_write(datos1);
   i2c_stop();
}
void Esclavo_41()
{
   i2c_start();
   i2c_write(0xd0);
   i2c_write(datos);
   i2c_write(datos1);
   i2c_write(datos2);
   i2c_stop();
}
void Esclavo_5()
{
   i2c_start();
   i2c_write(0xe0);
   i2c_write(datos);
   i2c_write(datos1);
   i2c_stop();
}
void Esclavo_51()
{
   i2c_start();
   i2c_write(0xe0);
   i2c_write(datos);
   i2c_write(datos1);
   i2c_write(datos2);
   i2c_stop();
}
void Esclavo_6()
{
   i2c_start();
   i2c_write(0xf0);
   i2c_write(datos);
   i2c_write(datos1);
   i2c_stop();
}
void Esclavo_61()
{
   i2c_start();
   i2c_write(0xf0);
   i2c_write(datos);
   i2c_write(datos1);
   i2c_write(datos2);
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
         if (dato>=0x30 && dato<=0x40)
         {
            num=dato-48;
         }
         if (dato>=97 && dato<=102)
         {
            num=dato-87;
         }
         
         switch (num)
         {
            case 1:
            {
               output_high(PIN_A4);
               printf(usb_cdc_putc,"\n\rEje x atras");
               //***************
               datos=0x00;
               datos1=0x00;
               Esclavo_1();
               //**************
               datos=0x00;
               datos1=0x03;
               Esclavo_1();
               //**************
               datos=0x71;
               datos1=0x20;
               datos2=0x02;
               Esclavo_11();
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
               break;
            }
            case 2:
            {
               output_high(PIN_A4);
               printf(usb_cdc_putc,"\n\rEje x adelante");
               datos=0x00;
               datos1=0x00;
               Esclavo_1();
               //**************
               datos=0x00;
               datos1=0x03;
               Esclavo_1();
               //**************
               datos=0x71;
               datos1=0x20;
               datos2=0x00;
               Esclavo_11();

               break;
            }
            case 3:
            {
               output_high(PIN_A4);
               printf(usb_cdc_putc,"\n\rEje z abajo");
               datos=0x00;
               datos1=0x00;
               Esclavo_2();
               //**************
               datos=0x00;
               datos1=0x03;
               Esclavo_2();
               //**************
               datos=0x71;
               datos1=0x20;
               datos2=0x02;
               Esclavo_21();
               break;
            }
            case 4:
            {
               output_high(PIN_A4);
               printf(usb_cdc_putc,"\n\r Eje z arriba");
               datos=0x00;
               datos1=0x00;
               Esclavo_2();
               //**************
               datos=0x00;
               datos1=0x03;
               Esclavo_2();
               //**************
               datos=0x71;
               datos1=0x20;
               datos2=0x01;
               Esclavo_21();
               break;
            }
            case 5:
            {
               output_high(PIN_A4);
               printf(usb_cdc_putc,"\n\rEje y derecha");
               datos=0x00;
               datos1=0x00;
               Esclavo_3();
               //**************
               datos=0x00;
               datos1=0x03;
               Esclavo_3();
               //**************
               datos=0x71;
               datos1=0x20;
               datos2=0x00;
               Esclavo_31();
               break;
            }
            case 6:
            {
               output_high(PIN_A4);
               printf(usb_cdc_putc,"\n\r Eje y izquierda");
               //***************
               datos=0x00;
               datos1=0x00;
               Esclavo_3();
               //**************
               datos=0x00;
               datos1=0x03;
               Esclavo_3();
               //**************
               datos=0x71;
               datos1=0x20;
               datos2=0x02;
               Esclavo_31();
               break;
            }
            case 7:
            {
               output_high(PIN_A4);
               printf(usb_cdc_putc,"\n\rGriper menos");
               datos=0x00;
               datos1=0x00;
               Esclavo_4();
               //**************
               datos=0x00;
               datos1=0x03;
               Esclavo_4();
               //**************
               datos=0x71;
               datos1=0x20;
               datos2=0x02;
               Esclavo_41();
               break;
            }
            case 8:
            {
               output_high(PIN_A4);
               printf(usb_cdc_putc,"\n\r Griper mas");
               datos=0x00;
               datos1=0x00;
               Esclavo_4();
               //**************
               datos=0x00;
               datos1=0x03;
               Esclavo_4();
               //**************
               datos=0x71;
               datos1=0x20;
               datos2=0x00;
               Esclavo_41();
               break;
            }
            case 9:
            {
               output_high(PIN_A4);
               printf(usb_cdc_putc,"\n\rGiro menos");
               datos=0x00;
               datos1=0x00;
               Esclavo_5();
               //**************
               datos=0x00;
               datos1=0x00;
               Esclavo_5();
               //**************
               datos=0x71;
               datos1=120;
               datos2=0x00;
               Esclavo_51();
               break;
            }
            case 0:
            {
               output_high(PIN_A4);
               printf(usb_cdc_putc,"\n\r Giro mas");
               datos=0x00;
               datos1=0x00;
               Esclavo_5();
               //**************
               datos=0x00;
               datos1=0x00;
               Esclavo_5();
               //**************
               datos=0x71;
               datos1=120;
               datos2=0x01;
               Esclavo_51();
               break;
            }
            case 10:
            {
               output_high(PIN_A4);
               printf(usb_cdc_putc,"\n\rAbre");
               datos=0x00;
               datos1=0x00;
               Esclavo_6();
               //**************
               datos=0x00;
               datos1=0x00;
               Esclavo_6();
               //**************
               datos=0x71;
               datos1=120;
               datos2=0x00;
               Esclavo_61();
               break;
            }
            case 11:
            {
               output_high(PIN_A4);
               printf(usb_cdc_putc,"\n\r Cierra");
               datos=0x00;
               datos1=0x00;
               Esclavo_6();
               //**************
               datos=0x00;
               datos1=0x00;
               Esclavo_6();
               //**************
               datos=0x71;
               datos1=120;
               datos2=0x01;
               Esclavo_61();
               break;
            }
            default:
            {
               break;
            }
         }
   }
}
}
while(1);
}
