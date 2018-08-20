TARGET = letter
MCU = atmega48
BAUDRATE = 19200
PROGRAMMER = avrisp
PORT = "/dev/ttyUSB0"

default: $(TARGET).c
	avr-gcc -mmcu=$(MCU) -O1 -o $(TARGET).o $(TARGET).c
	avr-objcopy -j .text -j .data -O ihex $(TARGET).o $(TARGET).hex

flash: $(TARGET).hex
	avrdude -p m48 -P $(PORT) -c $(PROGRAMMER) -b $(BAUDRATE) -F -U flash:w:$(TARGET).hex

clean:
	rm $(TARGET).o $(TARGET).hex

