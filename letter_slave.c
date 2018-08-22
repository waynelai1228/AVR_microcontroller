#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define DELAY_TIME 50

volatile READ = 0x00;

/*same as enter in letter.c*/
void enter(uint8_t pattern){

    PORTD = (PORTD & 0x0f) << 4;
    PORTD |= (PORTB & 0xf0) >> 4;
    PORTB = (PORTB & 0x0f) << 4;
    PORTB |= pattern;
    _delay_ms(DELAY_TIME);
}

ISR(PCINT1_vect, ISR_BLOCK){
    READ = 0x00;

    /*reading data if broadcast receive is set as transfering*/
    if(!(PINC & 0x04)){
        _delay_ms(2);
        READ |= ((PINC & (1 << PC0)) << 3);
        _delay_ms(4);
        READ |= ((PINC & (1 << PC0)) << 2);
        _delay_ms(4);
        READ |= ((PINC & (1 << PC0)) << 1);
        _delay_ms(4);
        READ |= (PINC & (1 << PC0));
        _delay_ms(2);

        
        enter(READ);
    }
}

int main(){
    /*enable interrupt 1*/
    PCICR = 0x2;
    PCMSK1 = 0x4;
    sei();

    /*initialising pins*/
    DDRB = 0xff;
    DDRD = 0xff;
    DDRC = 0x00;

    /*enable pull up resister on PC2 and PC0*/
    PORTC = ((1 << PC2) | (1 << PC0));

    while(1){
    }
}
