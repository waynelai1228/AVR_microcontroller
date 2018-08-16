#define F_CPU 2000000UL

#include <avr/io.h>
#include <util/delay.h>

#define LED1 (1<<PB0) 
#define LED2 (1<<PB1)
#define LED3 (1<<PB2)
#define LED4 (1<<PB3)
#define LED5 (1<<PB4)
#define LED6 (1<<PB5)
#define LED7 (1<<PB6)
#define LED8 (1<<PB7)
#define LED9 (1<<PD0)
#define LED10 (1<<PD1)
#define LED11 (1<<PD2)
#define LED12 (1<<PD3)
#define LED13 (1<<PD4)
#define LED14 (1<<PD5)
#define LED15 (1<<PD6)
#define LED16 (1<<PD7)

void change_LED(int num,int on){
    if(on){
        switch(num){
            case 1:
                PORTB |= LED1;
                break;
            case 2:
                PORTB |= LED2;
                break;
            case 3:
                PORTB |= LED3;
                break;
            case 4:
                PORTB |= LED4;
                break;
            case 5:
                PORTB |= LED5;
                break;
            case 6:
                PORTB |= LED6;
                break;
            case 7:
                PORTB |= LED7;
                break;
            case 8:
                PORTB |= LED8;
                break;
            case 9:
                PORTD |= LED9;
                break;
            case 10:
                PORTD |= LED10;
                break;
            case 11:
                PORTD |= LED11;
                break;
            case 12:
                PORTD |= LED12;
                break;
            case 13:
                PORTD |= LED13;
                break;
            case 14:
                PORTD |= LED14;
                break;
            case 15:
                PORTD |= LED15;
                break;
            case 16:
                PORTD |= LED16;
                break;
        }
    }
    else{
        switch(num){
            case 1:
                PORTB &= ~LED1;
                break;
            case 2:
                PORTB &= ~LED2;
                break;
            case 3:
                PORTB &= ~LED3;
                break;
            case 4:
                PORTB &= ~LED4;
                break;
            case 5:
                PORTB &= ~LED5;
                break;
            case 6:
                PORTB &= ~LED6;
                break;
            case 7:
                PORTB &= ~LED7;
                break;
            case 8:
                PORTB &= ~LED8;
                break;
            case 9:
                PORTD &= ~LED9;
                break;
            case 10:
                PORTD &= ~LED10;
                break;
            case 11:
                PORTD &= ~LED11;
                break;
            case 12:
                PORTD &= ~LED12;
                break;
            case 13:
                PORTD &= ~LED13;
                break;
            case 14:
                PORTD &= ~LED14;
                break;
            case 15:
                PORTD &= ~LED15;
                break;
            case 16:
                PORTD &= ~LED16;
                break;
        }
    }
}


int main(){
    DDRB |= LED1;
    DDRB |= LED2;
    DDRB |= LED3;
    DDRB |= LED4;
    DDRB |= LED5;
    DDRB |= LED6;
    DDRB |= LED7;
    DDRB |= LED8;
    DDRD |= LED9;
    DDRD |= LED10;
    DDRD |= LED11;
    DDRD |= LED12;
    DDRD |= LED13;
    DDRD |= LED14;
    DDRD |= LED15;
    DDRD |= LED16;
    int idx;
    int columnOneOffset=0;
    int columnTwoOffset=1;
    int columnThreeOffset=2;
    int columnFourOffset=3;
    int rowOneElement[26]={1,0,1,0,1,0,0,1,1,0,0,1,0,0,0,1,0,1,0,0,1,0,1,1,1,0};
    int rowTwoElement[26]={1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,1,0,1,0,1,0,1,0};
    int rowThreeElement[26]={1,0,1,0,1,0,1,1,1,1,0,0,0,1,0,0,0,1,0,1,1,0,1,1,0,0};
    int rowFourElement[26]={0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,1,1,1,0};
    while(1){
        if(columnOneOffset>25){
            columnOneOffset=0;
        }
        if(columnTwoOffset>25){
            columnTwoOffset=0;
        }
        if(columnThreeOffset>25){
            columnThreeOffset=0;
        }
        if(columnFourOffset>25){
            columnFourOffset=0;
        }
        change_LED(1,rowOneElement[columnOneOffset]);
        change_LED(2,rowOneElement[columnTwoOffset]);
        change_LED(3,rowOneElement[columnThreeOffset]);
        change_LED(4,rowOneElement[columnFourOffset]);
        change_LED(5,rowTwoElement[columnOneOffset]);
        change_LED(6,rowTwoElement[columnTwoOffset]);
        change_LED(7,rowTwoElement[columnThreeOffset]);
        change_LED(8,rowTwoElement[columnFourOffset]);
        change_LED(9,rowThreeElement[columnOneOffset]);
        change_LED(10,rowThreeElement[columnTwoOffset]);
        change_LED(11,rowThreeElement[columnThreeOffset]);
        change_LED(12,rowThreeElement[columnFourOffset]);
        change_LED(13,rowFourElement[columnOneOffset]);
        change_LED(14,rowFourElement[columnTwoOffset]);
        change_LED(15,rowFourElement[columnThreeOffset]);
        change_LED(16,rowFourElement[columnFourOffset]);
        _delay_ms(100);
        columnOneOffset+=1;
        columnTwoOffset+=1;
        columnThreeOffset+=1;
        columnFourOffset+=1;
    }
    
    return 0;
}
