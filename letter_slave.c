#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


void enter(uint8_t pattern){
    PORTD = (PORTD & 0x0f) << 4;
    PORTD |= (PORTB & 0xf0) >> 4;
    PORTB = (PORTB & 0x0f) << 4;
    PORTB |= pattern;
    _delay_ms(500);
}

ISR(PCINT1_vect, ISR_BLOCK){
    uint8_t READ = 0x00;
    if(!(PINC & 0x04)){
        _delay_ms(2);
        READ |= ((PINC & (1 << PC0)) << 3);
        _delay_ms(4);
        READ |= ((PINC & 0x01) << 2);
        _delay_ms(4);
        READ |= ((PINC & 0x01) << 1);
        _delay_ms(4);
        READ |= (PINC & 0X01);
        enter(READ);
    }
}

int main(){
    PCICR = 0x2;
    PCMSK1 = 0x4;
    sei();
    DDRB = 0xff;
    DDRD = 0xff;
    DDRC = 0x00;
    PORTC = 0x04;
    while(1){
    }
}
