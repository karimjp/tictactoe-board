################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AutomatedUser.cpp \
../src/Control.cpp \
../src/TestDrive.cpp \
../src/TicTacToeBoard.cpp \
../src/main.cpp 

OBJS += \
./src/AutomatedUser.o \
./src/Control.o \
./src/TestDrive.o \
./src/TicTacToeBoard.o \
./src/main.o 

CPP_DEPS += \
./src/AutomatedUser.d \
./src/Control.d \
./src/TestDrive.d \
./src/TicTacToeBoard.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


