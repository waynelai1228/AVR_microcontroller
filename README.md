# AVR_microcontroller
avr-gcc -mmcu=atmega48 -O1 -o <name> <name>.c 
avr-objcopy -j .text -j .data -O ihex <name> <name>.hex
avrdude -p m48 -P /dev/ttyUSB0 -c avrisp -b 19200 -F -U flash:w:<name>.hex 
