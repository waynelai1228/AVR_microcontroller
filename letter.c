#define F_CPU 2000000UL

#define MSG "WAYNE"

#include <avr/io.h>
#include <util/delay.h>

void enter(uint8_t pattern){
    PORTD = (PORTD & 0x0f) << 4;
    PORTD |= (PORTB & 0xf0) >> 4;
    PORTB = (PORTB & 0x0f) << 4;
    PORTB |= pattern;
    _delay_ms(150);
}


void draw(uint16_t letter){
    int idx;
    uint8_t PD_HI = (letter & 0xf000) >> 12;
    uint8_t PD_LW = (letter & 0x0f00) >> 8;
    uint8_t PB_HI = (letter & 0x00f0) >> 4;
    uint8_t PB_LW = (letter & 0x000f);

    if(PD_HI != 0x0000){
        enter(PD_HI);
    }
    if(PD_LW != 0x0000){
        enter(PD_LW);
    }
    if(PB_HI != 0x0000){
        enter(PB_HI);
    }
    if(PB_LW != 0x0000){
        enter(PB_LW);
    }
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
                    letter = 0xfa40;
                    break;
                case 'C':
                    letter = 0x6990;
                    break;
                case 'D':
                    letter = 0xf960;
                    break;
                case 'E':
                    letter = 0x6db0;
                    break;
                case 'F':
                    letter = 0xf510;
                    break;
                case 'G':
                    letter = 0x695d;
                    break;
                case 'H':
                    letter = 0xf22f;
                    break;
                case 'I':
                    letter = 0x9f90;
                    break;
                case 'J':
                    letter = 0x49f1;
                    break;
                case 'K':
                    letter = 0xf4a0;
                    break;
                case 'L':
                    letter = 0xf880;
                    break;
                case 'M':
                    letter = 0xe1e1;
                    draw(letter);
                    letter = 0xe000;
                    break;
                case 'N':
                    letter = 0xf24f;
                    break;
                case 'O':
                    letter = 0x6996;
                    break;
                case 'P':
                    letter = 0xf520;
                    break; 
                case 'Q':
                    letter = 0x69d6;
                    draw(letter);
                    letter = 0x8000;
                    break;
                case 'R':
                    letter = 0xf5a0;
                    break;
                case 'S':
                    letter = 0xbdd0;
                    break;
                case 'T':
                    letter = 0x1f10;
                    break;
                case 'U':
                    letter = 0x7887;
                    break;
                case 'V':
                    letter = 0x7870;
                    break;
                case 'W':
                    letter = 0x7878;
                    draw(letter);
                    letter = 0x7000;
                    break;
                case 'X':
                    letter = 0x9669;
                    break;
                case 'Y':
                    letter = 0x12c2;
                    draw(letter);
                    letter = 0x1;
                    break;
                case 'Z':
                    letter = 0x9db9;
                    break;
            }
            draw(letter);
            enter(0x0000);
            i += 1;
        }
    }
}
