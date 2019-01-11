################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs.cpp \

C_SRCS_QUOTED += \
"../S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs.c" \

C_SRCS += \
../S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs.c \

CPP_SRCS_QUOTED += \
"../S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs.cpp" \

OBJS += \
./S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs_c.obj \
./S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs_cpp.obj \

OBJS_QUOTED += \
"./S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs_c.obj" \
"./S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs_cpp.obj" \

CPP_DEPS_QUOTED += \
"./S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs_cpp.d" \

CPP_DEPS += \
./S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs_cpp.d \

C_DEPS += \
./S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs_c.d \

C_DEPS_QUOTED += \
"./S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs_c.d" \

OBJS_OS_FORMAT += \
./S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs_c.obj \
./S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs_cpp.obj \


# Each subdirectory must supply rules for building sources it contributes
S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs_c.obj: ../S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: S12Z Compiler'
	"$(S12Z_ToolsDirEnv)/mwccs12lisa" -c @@"S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs.args" -o "S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/%.d: ../S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs_cpp.obj: ../S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs.cpp
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: S12Z Compiler'
	"$(S12Z_ToolsDirEnv)/mwccs12lisa" -c @@"S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs_1.args" -o "S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/specs_cpp.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/%.d: ../S12Z_CAN_DBW/.metadata/.plugins/org.eclipse.cdt.make.core/%.cpp
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


