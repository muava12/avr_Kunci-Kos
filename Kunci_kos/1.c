/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.0 Professional
Automatic Program Generator
© Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 06/01/2014
Author  : 
Company : 
Comments: 


Chip type               : ATmega8
Program type            : Application
AVR Core Clock frequency: 12,000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega8.h>
#include <delay.h>

// Declare your global variables here
int input[4], tekan, hasil, i, j;

//------ PUSH BUTTON ------------------------
#define ok PINC.0
#define tombol_1 PINC.1
#define tombol_2 PINC.2
#define tombol_3 PINC.3

//------ OPTOCOUPLE --------------------------
#define opto1 PORTB.1
#define opto2 PORTB.2
#define buzzer PORTB.1
#define ON 0
#define OFF 1

//------ LED KEDIP ---------------------------
#define plus PORTC.5
#define min PORTC.4

//------ PSSWRD --------------------------------
#define password 3312

//------ AKSI BUKA KUNCI ---------------------
void aksi() {
                    
}

//------ SUARA BAZZER ------------------------
void buzzer_tekan() {
    buzzer = ON ;
    min = 0 ; plus = 1 ;
    delay_ms(200);
    buzzer = OFF ;  
    min = 0 ; plus = 0 ;
    delay_ms(100);
}

void buzzer_benar() {
    buzzer = ON ; min = 0 ; plus = 1 ; delay_ms(100);
    buzzer = OFF ; min = 0 ; plus = 0 ; delay_ms(100); 
    buzzer = ON ; min = 0 ; plus = 1 ; delay_ms(100);
    buzzer = OFF ; min = 0 ; plus = 0 ; delay_ms(100);    
}

void buzzer_salah() {
    buzzer = ON ; min = 0 ; plus = 1 ; delay_ms(300);
    buzzer = OFF ; 
    min = 0 ; plus = 0 ;    
}

void buzzer_maling() {
    for (i=0; i<3; i++) {
    buzzer = ON ; min = 0 ; plus = 1 ; delay_ms(600);
    buzzer = OFF ; min = 0 ; plus = 0 ; delay_ms(400); 
    }    
}

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port B initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTB=0x00;
DDRB=0xFF;

// Port C initialization
// Func6=Out Func5=Out Func4=Out Func3=In Func2=In Func1=In Func0=In 
// State6=0 State5=0 State4=0 State3=P State2=P State1=P State0=P 
PORTC=0x0F;
DDRC=0x70;

// Port D initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTD=0x00;
DDRD=0x00;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
TCCR0=0x00;
TCNT0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
MCUCR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;

// USART initialization
// USART disabled
UCSRB=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// ADC initialization
// ADC disabled
ADCSRA=0x00;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;


while (1)
      { 
      
      awal:
      PORTC.4 = 0; PORTC.5 = 0; PORTB.1 = 1; PORTB.2 = 1;
        if (ok == 0) {
            hasil = input[0]*1000 + input[1]*100 + input[2]*10 + input[3]*1 ;
          if (hasil == password) {
                while(1) {
                    buzzer_benar();
                    //delay_ms(500); 
                    
                //RESET NILAI KE AWAL
                    i = 0;   
                    hasil = 0; 
                    for (j=0; j<= 4; j++) {
                    input[j] = 0 ;        
                    }  
                //AKSI
                    while(1) {
                     plus = 1; min = 0;  
                     for(j=0; j<5; j++) {
                        delay_ms(200);
                        if (ok == 0) goto awal;
                        }   
                    plus = 0; min = 0;  
                      for(j=0; j<2; j++) {
                         delay_ms(200);
                        if (ok == 0) goto awal; 
                        }  
                    }
                //KEMBALI KE AWAL PROGRAM    
                    goto awal;
                }; 
           }
          else 
          {
                    buzzer_salah();
                    delay_ms(200); 
                    i= 0;
                    goto awal;
          } 
        }  
        
        else if (tombol_1 == 0) { 
            tekan = 1;
            input[i] = tekan; 
            i = i+1;
            plus = 1;
            buzzer_tekan();
            goto awal;
        }
        else if (tombol_2 == 0) {
            tekan = 2;
            input[i] = tekan;
            i = i+1;
            plus = 1;
            buzzer_tekan();
            goto awal;
        }
        else if (tombol_3 == 0) {
            tekan = 3;
            input[i] = tekan;            
            i = i+1;
            plus = 1; 
            buzzer_tekan();           
            goto awal;
        } 
      }  
      
}
