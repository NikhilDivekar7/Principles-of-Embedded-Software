SOURCES = main.c \
		project1.c \
		conversion.c \
		debug.c \
		memory.c

SOURCES_KL25Z = main.c \
		project1.c \
		conversion.c \
		debug.c \
		memory.c \
		system_MKL25Z4.c

INCLUDES = -I ../include/common

INCLUDES_KL25Z = -I ../include/common \
	     -I ../include/CMSIS \
	     -I ../include/kl25z
