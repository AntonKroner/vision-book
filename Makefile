CC = g++-14
CCFLAGS = -std=gnu++26 -fmodules-ts -flang-info-module-cmi -Wall -Wpedantic# -fsanitize=address -static-libasan -fno-omit-frame-pointer #-O3
EXECUTABLE = vision.exe

LINALG = ./linalg/Numeric.cpp ./linalg/Matrix.cpp ./linalg/linalg.cpp
IMAGE = ./Image/Image.cpp
ARITHMETIC = arithmetic/subtracter.cpp arithmetic/adder.cpp arithmetic/arithmetic.cpp
MODULES = $(IMAGE) $(ARITHMETIC) $(LINALG)

all: $(EXECUTABLE)
$(EXECUTABLE): $(MODULES) main.cpp
	$(CC) $(CCFLAGS) $+ -o $@

clean:
	rm -f $(EXECUTABLE) ./build/* ./gcm.cache/* ./compile_commands.json
