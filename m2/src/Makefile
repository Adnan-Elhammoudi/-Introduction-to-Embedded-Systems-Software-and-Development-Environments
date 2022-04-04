#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple Make file which supports Host (Linux) and Cross platform: ARM
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#	   <FILE>.o - Builds <FILE>.o object file
#	   <FILE>.i - Generate the preprocessed output of the <FILE>.i
#      <FILE>.asm - Generate assembly output of <FILE>.asm	
#	      
#      compile-all : Compiles all files, doesn't build
#	   build: Compile all object files and link into a final executable
#	   clean: removes all generated files.
# Platform Overrides:
#      CPU -  ARM Cortex Architecture(cortex-m4) 
#	   ARCH - ARM Architecture (thumb)
#	   SPECS - Specs file to give the linker (nosys.specs)
#
#------------------------------------------------------------------------------
include sources.mk



TARGET 	= c1m2
COMMONCFLAGS 	= -Wall -O0  -g -std=c99
COMMONLDFLAGS = -Wl,-Map=$(TARGET).map


# Conditional If for select between Platforms (HOST & MSP432)
ifeq ($(PLATFORM),MSP432)
	CPU		= cortex-m4
	ARCH 		= armv7e-m
	SPECS 	        = nosys.specs
	ADDITIONAL 	= -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16

	# C compiler Flags and Defines for MSP432 PLATFORM
	CC 		= arm-none-eabi-gcc
	CFLAGS 		= $(COMMONCFLAGS) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) $(ADDITIONAL)

	# Linker Flags and Defines
	LINKER_FILE = -T msp432p401r.lds
	LINKER_PATH =  msp432p401r.lds
	LD 		= arm-none-eabi-ld
	LDFLAGS 	= $(COMMONLDFLAGS)   -L ../ $(LINKER_FILE)   -nostdlib

	#GNU Bin Utils Flags and Defines
	OBJDUMP = arm-none-eabi-objdump
	NM 		= arm-none-eabi-nm

		#Size Utility
		SIZE = arm-none-eabi-size 
else
# C compiler Flags and Defines for HOST
        CC	= gcc
        
	CFLAGS 	= $(COMMONCFLAGS)

	# Linker Flags and Defines
	LD 	= ld
         LDFLAGS = $(COMMONLDFLAGS)
		OBJDUMP = objdump
		
		#Size Utility
		SIZE = size
		
endif




CPPFLAGS =  -D$(PLATFORM) $(INCLUDES)


OBJS := $(SOURCES:.c=.o)

PREPRO := $(SOURCES:.c=.i)

ASMS := $(SOURCES:.c=.asm)

DEPS := $(SOURCES:.c=.d)

#Had to use this because other than memory.* and main.* other files are not getting deleted.  
FILES = *.asm *.i *.o *.d

%.o : %.c
	$(CC) $(CPPFLAGS) -c $< $(CFLAGS) -o $@
	@echo " -------Object " $@ " file generated for " $^ " Source File Successfuly------- "

%.i :  %.c
	
	
	$(CC)  $(CPPFLAGS) -E $< $(CFLAGS) -o $@
	@echo " -------Preprocessor " $@ " file generated for " $^ " Source File Successfuly------- "

%.asm :  %.c
	
	$(CC) $(CPPFLAGS) -S $(CFLAGS) -o $@ $<
	@echo " -------Assembly " $@ " file generated for " $^ " Source File Successfuly------- "

$(TARGET).asm :  $(TARGET).out
	
	$(OBJDUMP) -d $(TARGET).out >> $@
	@echo " -------Assembly " $@ " file generated for " $^ " TARGET File Successfuly------- "

%.d :  %.c
	
	$(CC) $(CPPFLAGS) -M $< $(CFLAGS) -o $@
	@echo " -------dependency " $@ " file generated for " $^ " Source File Successfuly------- "

.PHONY: compile-all
compile-all:   $(OBJS)
	@echo " -------------------------compile-all files without linking-------------------------"
	$(CC) $(CPPFLAGS) $(OBJS) -c $(CFLAGS) -o $(TARGET).o

.PHONY: build
build: clean  $(SOURCES) 
	@echo " -----------------Build the code and link into "$(TARGET).out"-------------------"
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SOURCES)  $(LDFLAGS) -o $(TARGET).out
	@echo " ------------------------------Size of the segments------------------------------"
	$(SIZE) $(TARGET).out

.PHONY: clean
clean:
	@echo " ------------------------------ removes all generated files-----------------------------"
	rm -f $(TARGET).asm $(FILES) $(TARGET).out $(TARGET).map $(PREPRO) $(ASMS) $(DEPS) $(OBJS)