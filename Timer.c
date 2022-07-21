#include <Timer.h>
#use delay(clock=8Mhz)

long tiempo;
//long milisegundos;

#INT_TIMER0                   //habilito la interrupcion del timer0
void TIMER0_isr()             //declaro lo que haré al momento de la interrupcion del timer
{
output_toggle(PIN_B4);
tiempo++;
if(tiempo==10)
{
output_toggle(PIN_B0);  //Hace el parpadeo cada 20 Segundos
tiempo=0;
}
set_timer0(34285);
//disable_interrupts(INT_TIMER0);
}


void main()
{
   set_tris_b(0);
   
   //TIMER DE 2 SEGUNDOS//
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_128);   //la interrupcion es algo externo y no debe de ir en el ciclo while
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   set_timer0(34285);
   
   while(1)
   {
   }
}

