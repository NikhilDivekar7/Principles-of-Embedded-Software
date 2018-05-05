################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/buffer.c \
../Sources/conversion.c \
../Sources/dma.c \
../Sources/gpio.c \
../Sources/logger.c \
../Sources/main.c \
../Sources/memory.c \
../Sources/nordic.c \
../Sources/profiler.c \
../Sources/project3.c \
../Sources/rtc.c \
../Sources/spi.c \
../Sources/uart.c 

OBJS += \
./Sources/buffer.o \
./Sources/conversion.o \
./Sources/dma.o \
./Sources/gpio.o \
./Sources/logger.o \
./Sources/main.o \
./Sources/memory.o \
./Sources/nordic.o \
./Sources/profiler.o \
./Sources/project3.o \
./Sources/rtc.o \
./Sources/spi.o \
./Sources/uart.o 

C_DEPS += \
./Sources/buffer.d \
./Sources/conversion.d \
./Sources/dma.d \
./Sources/gpio.d \
./Sources/logger.d \
./Sources/main.d \
./Sources/memory.d \
./Sources/nordic.d \
./Sources/profiler.d \
./Sources/project3.d \
./Sources/rtc.d \
./Sources/spi.d \
./Sources/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


