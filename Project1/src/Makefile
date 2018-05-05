include sources.mk

#variables
TARGET = project1
PRINTALLOW = KL25Z
PLATFORM = HOST
LINKER_FILE = ../platform/MKL25Z128xxx4_flash.ld
CPU = cortex-m0plus
ARCHITECTURE = armv6-m		
FPU = fpv4-sp-d16
SPECS = nosys.specs 

#check if platform is host
ifeq ($(PLATFORM), HOST)
	CC = gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99 $(INCLUDES)
	CPPFLAGS = -DHOST -DPROJECT1 -D VERBOSE
	LDFLAGS = -Wl,-Map=$(TARGET).map
	OBJFILES = $(SOURCES:.c=.o)
endif

#check if platform is Beaglebone
ifeq ($(PLATFORM),BBB)
	CC = arm-linux-gnueabihf-gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99 $(INCLUDES)
	CPPFLAGS = -DBBB -DPROJECT1 -D VERBOSE
	LDFLAGS = -Wl,-Map=$(TARGET).map
	OBJFILES = $(SOURCES:.c=.o)
endif

#check if platform is KL25Z
ifeq ($(PLATFORM),KL25Z)
	CC = arm-none-eabihf-gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99 -mcpu=$(CPU) \
		 -mthumb -march=$(ARCHITECTURE) -mfloat-abi=soft \
		 -mfpu=$(FPU) --specs=$(SPECS) $(INCLUDES_KL25Z)
	CPPFLAGS = -DKL25Z -DPROJECT1 -D$(PRINTALLOW)
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	OBJFILES = $(SOURCES_KL25Z:.c=.o) startup_MKL25Z4.o
endif

%.o : %.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

%.asm : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -S $< -o $@

%.i : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -E $< -o $@

build : $(OBJFILES)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJFILES) -o $(TARGET).elf

clean : 
	rm -f *.o
	rm -f project1.elf
	rm -f *.i
	rm -f *.map
	rm -f *.asm

upload:
	scp $(TARGET).elf root@192.168.7.2:/home/debian/bin
	ssh root@192.168.7.2
	cd /home/debian/bin




