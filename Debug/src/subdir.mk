################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GU.cpp \
../src/VAO.cpp \
../src/VAOLoader.cpp \
../src/VBO_DATA.cpp \
../src/camera.cpp \
../src/entity.cpp \
../src/entity_renderer.cpp \
../src/files.cpp \
../src/heights_generator.cpp \
../src/master_renderer.cpp \
../src/mat4.cpp \
../src/shader_program.cpp \
../src/static_shader.cpp \
../src/terrain.cpp \
../src/terrain_renderer.cpp \
../src/terrain_shader.cpp \
../src/uniform.cpp \
../src/uniform_float.cpp \
../src/uniform_int.cpp \
../src/uniform_mat4.cpp \
../src/uniform_vec2.cpp \
../src/vec2.cpp \
../src/vec3.cpp \
../src/vec4.cpp \
../src/water_renderer.cpp \
../src/water_shader.cpp \
../src/water_tile.cpp 

OBJS += \
./src/GU.o \
./src/VAO.o \
./src/VAOLoader.o \
./src/VBO_DATA.o \
./src/camera.o \
./src/entity.o \
./src/entity_renderer.o \
./src/files.o \
./src/heights_generator.o \
./src/master_renderer.o \
./src/mat4.o \
./src/shader_program.o \
./src/static_shader.o \
./src/terrain.o \
./src/terrain_renderer.o \
./src/terrain_shader.o \
./src/uniform.o \
./src/uniform_float.o \
./src/uniform_int.o \
./src/uniform_mat4.o \
./src/uniform_vec2.o \
./src/vec2.o \
./src/vec3.o \
./src/vec4.o \
./src/water_renderer.o \
./src/water_shader.o \
./src/water_tile.o 

CPP_DEPS += \
./src/GU.d \
./src/VAO.d \
./src/VAOLoader.d \
./src/VBO_DATA.d \
./src/camera.d \
./src/entity.d \
./src/entity_renderer.d \
./src/files.d \
./src/heights_generator.d \
./src/master_renderer.d \
./src/mat4.d \
./src/shader_program.d \
./src/static_shader.d \
./src/terrain.d \
./src/terrain_renderer.d \
./src/terrain_shader.d \
./src/uniform.d \
./src/uniform_float.d \
./src/uniform_int.d \
./src/uniform_mat4.d \
./src/uniform_vec2.d \
./src/vec2.d \
./src/vec3.d \
./src/vec4.d \
./src/water_renderer.d \
./src/water_shader.d \
./src/water_tile.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/dinu/c-cpp/NS_CPP/include" -O3 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


