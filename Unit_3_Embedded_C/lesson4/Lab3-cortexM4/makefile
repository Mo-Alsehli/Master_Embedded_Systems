#@copyright Mohamed Magdi
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -mthumb -gdwarf-2 -g
INCS= -I . 
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
Project_name=lab3-cortexM4

all: $(Project_name).bin
	@echo "============== Build done successfully:) =================="

%.o: %.c
	$(CC)gcc $(CFLAGS) -c $(INCS) $< -o $@
# The above lines represent the two following instructions.
#uart.o: uart.c
#	$(CC)gcc -c $(CFLAGS) $(INCS) $< -o $@
#app.o: app.c
#	$(CC)gcc -c $(CFLAGS) $(INCS) $< -o $@
#startup.o: startup.s
#	$(CC)as $(CFLAGS) $< -o $@
$(Project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=map_file
	cp $(Project_name).elf $(Project_name).axf
	
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy -O binary $< $@

clean_all:
	rm *.o *.elf *.bin
clean: 
	rm *.elf *.bin