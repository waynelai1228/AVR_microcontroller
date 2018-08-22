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

slave: $(TARGET)_slave.c
	avr-gcc -mmcu=$(MCU) -O1 -o $(TARGET)_slave.o $(TARGET)_slave.c
	avr-objcopy -j .text -j .data -O ihex $(TARGET)_slave.o $(TARGET)_slave.hex
flash-slave: $(TARGET)_slave.hex
	avrdude -p m48 -P $(PORT) -c $(PROGRAMMER) -b $(BAUDRATE) -F -U flash:w:$(TARGET)_slave.hex

all: default flash clean

all-slave: slave flash-slave clean-slave

clean:
	rm $(TARGET).o $(TARGET).hex

clean-slave:
	rm $(TARGET)_slave.o $(TARGET)_slave.hex

