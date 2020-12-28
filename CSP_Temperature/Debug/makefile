################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
CSP_Temperature.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
CSP_Temperature.list \

OBJCOPY_BIN += \
CSP_Temperature.bin \


# All Target
all: CSP_Temperature.elf secondary-outputs

# Tool invocations
CSP_Temperature.elf: $(OBJS) $(USER_OBJS) C:\Users\David\Desktop\workspace_1.04\CSP_Temperature\STM32F103RBTX_FLASH.ld
	arm-none-eabi-gcc -o "CSP_Temperature.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\David\Desktop\workspace_1.04\CSP_Temperature\STM32F103RBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="CSP_Temperature.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

CSP_Temperature.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "CSP_Temperature.list"
	@echo 'Finished building: $@'
	@echo ' '

CSP_Temperature.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "CSP_Temperature.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
