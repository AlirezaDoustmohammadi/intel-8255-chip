

#include <mega16.h>
#include <delay.h>
#include <stdio.h>
#include <stdio.h>
// Declare your global variables here
  char c;  
  char x;

void sender(void);
// External Interrupt 0 service routine
interrupt [EXT_INT0] void ext_int0_isr(void)
{
    sender();  

}


interrupt [EXT_INT1] void ext_int1_isr(void)
{
    sender();  

}




void main(void)
{


// External Interrupt(s) initialization
// INT0: On
// INT0 Mode: Rising Edge
// INT1: on
// INT2: Off
GICR|=(1<<INT1) | (1<<INT0) | (0<<INT2);
MCUCR=(1<<ISC11) | (1<<ISC10) | (1<<ISC01) | (1<<ISC00);
MCUCSR=(0<<ISC2);
GIFR=(1<<INTF1) | (1<<INTF0) | (0<<INTF2);

// Global enable interrupts
#asm("sei")

// Standard Input/Output functions


// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 4800
UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (0<<U2X) | (0<<MPCM);
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (1<<RXEN) | (1<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
UCSRC=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
UBRRH=0x00;
UBRRL=0x0C;

UBRRH=0x00;
UBRRL=0x0C;
UCSRB=0b00011000; 
UCSRC=0b10000110;

// Global enable interrupts
#asm("sei")

 DDRB=0xff;
 DDRA=0xff;
 
 DDRD=0x00;
 PORTD=0x00;
 
// command data 
 PORTB=0xa4;
 
//A0 & A1 
 PORTA.5=1;
 PORTA.4=1; 
 

//~wr 
 PORTA.6=1;


sender(); 

while (1)
      { 
   
     
  
}
}

void sender(void){
  putsf(" I/O : ");
    x=getchar();
    putchar(x);
    putsf("\n\r");
    
    putsf(" character : ");
    c=getchar();
    putchar(c);
    putsf("\n\r");
    
    PORTB=c;
    
    if(x=='1'){
      PORTA.5=0;
      PORTA.4=0;
    
    }
    else if(x=='2'){
      PORTA.5=1;
      PORTA.4=0; 
      
    }   
    
       delay_ms(100);
       PORTA.6=0;
       delay_ms(100);
       PORTA.5=1;
       PORTA.4=1;
       PORTB=0xa4; 
       PORTA.6=1;
       MCUCR=0x02;


}
