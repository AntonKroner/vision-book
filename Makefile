CC = g++-14
CCFLAGS = -std=gnu++23 -fmodules-ts -flang-info-module-cmi -Wall -Wpedantic -fsanitize=address -static-libasan -fno-omit-frame-pointer #-O3
EXECUTABLE = vision.exe

ARITHMETIC = arithmetic/subtracter.cpp arithmetic/adder.cpp arithmetic/arithmetic.cpp
MODULES = $(ARITHMETIC)

all: $(EXECUTABLE)
$(EXECUTABLE): $(MODULES) main.cpp
	$(CC) $(CCFLAGS) $+ -o $@

clean:
	rm -f $(EXECUTABLE) ./build/* ./gcm.cache/*
