#define F_CPU 2000000UL

#define MSG "HJKLMNOPQRSTUVWXYZ"

#include <avr/io.h>
#include <util/delay.h>

void enter(uint8_t pattern){
    PORTD = (PORTD & 0x0f) << 4;
    PORTD |= (PORTB & 0xf0) >> 4;
    PORTB = (PORTB & 0x0f) << 4;
    PORTB |= pattern;
    _delay_ms(500);
}


void draw(uint16_t letter){
    int idx;
    uint8_t PD_HI = (letter & 0xf000) >> 12;
    uint8_t PD_LW = (letter & 0x0f00) >> 8;
    uint8_t PB_HI = (letter & 0x00f0) >> 4;
    uint8_t PB_LW = (letter & 0x000f);

    enter(PD_HI);
    enter(PD_LW);
    enter(PB_HI);
    enter(PB_LW);
}

int main(){
    DDRB=0xff;
    DDRD=0xff;
    uint16_t letter;
    while(1){
        int i=0;
        while(MSG[i]!=0){
            switch(MSG[i]){
                case 'A':
                    letter = 0xe55e;
                    break;
                case 'B':
                    letter = 0xfac0;
                    break;
                case 'C':
                    letter = 0x6990;
                    break;
                case 'D':
                    letter = 0xf960;
                    break;
                case 'E':
                    letter = 0xfdb0;
                    break;
                case 'F':
                    letter = 0xf510;
                    break;
                case 'G':
                    letter = 0x69dd;
                    break;
                case 'H':
                    letter = 0xf2f0;
                    break;
                case 'I':
                    letter = 0x9f90;
                    break;
                case 'J':
                    letter = 0x9f10;
                    break;
                case 'K':
                    letter = 0xf4a0;
                    break;
                case 'L':
                    letter = 0xf880;
                    break;
            }
            draw(letter);
            enter(0x0000);
            i += 1;
        }
    }
}
