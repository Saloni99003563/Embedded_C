CC = arm-none-eabi-gcc
MACH = cortex-m4
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -o0
LDFLAGS= -mcpu=$(MACH) -mthumb -nostdlib -T linker_script.ld

all: test.o startup_stm32.o final.elf

test.o: test.c
	$(CC) $(CFLAGS) -o $@ $^ 

startup_stm32.o: startup_stm32.c
	$(CC) $(CFLAGS) -o $@ $^

final.elf: test.o startup_stm32.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	del *.o *.elf