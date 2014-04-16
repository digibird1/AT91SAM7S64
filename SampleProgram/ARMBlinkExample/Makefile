#By Adam Pierce <adam@doctort.org>

#define the tool chain
CC      = ${HOME}/bin/Atmel/gcc-arm-none-eabi-4_8-2014q1/bin/arm-none-eabi-gcc
LD      = ${HOME}/bin/Atmel/gcc-arm-none-eabi-4_8-2014q1/bin/arm-none-eabi-ld
AS      = ${HOME}/bin/Atmel/gcc-arm-none-eabi-4_8-2014q1/bin/arm-none-eabi-as
CP      = ${HOME}/bin/Atmel/gcc-arm-none-eabi-4_8-2014q1/bin/arm-none-eabi-objcopy

# Commandline options for each tool.
CFLAGS  = -I./ -c -fno-common -O0 -g -mcpu=arm7tdmi
AFLAGS  = -ahls -mapcs-32 -o crt.o
LFLAGS  = -v -Map blink.map -Tram-ln.cmd
CPFLAGS = --output-target=ihex

# Our target.
all: blink.hex

clean:
	rm -f *.o *.hex *.elf *.map *.lst core *~

# Convert ELF binary to Intel HEX file.
blink.hex: blink.elf
	$(CP) $(CPFLAGS) blink.elf blink.hex

# Link - this produces an ELF binary.
blink.elf: blink.o crt.o
	$(LD) $(LFLAGS) -o blink.elf crt.o blink.o

# Compile the C runtime.
crt.o: ram-crt.s
	$(AS) $(AFLAGS) ram-crt.s > crt.lst

# Compile the main program.
blink.o: blink.c
	$(CC) $(CFLAGS) -c blink.c
