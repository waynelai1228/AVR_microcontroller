NAME=letter

avr-gcc -mmcu=atmega48 -O1 -o $NAME.o $NAME.c 
avr-objcopy -j .text -j .data -O ihex $NAME.o $NAME.hex
avrdude -p m48 -P /dev/ttyUSB0 -c avrisp -b 19200 -F -U flash:w:$NAME.hex 

