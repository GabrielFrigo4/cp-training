CXX      = g++
CXXFLAGS = -std=c++23 -O2 -Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wl,-z,stack-size=268435456
EXE      = ./main
SRC      = ./main.cpp
INPUT    = ./input.txt

all: $(EXE)
	@echo "=== Running program ==="
	@cat $(INPUT) | $(EXE)

$(EXE): $(SRC)
	@echo "=== Compiling with optimized flags ==="
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXE)

debug: $(SRC)
	@echo "=== Compiling with debug flags and sanitizers ==="
	$(CXX) -std=c++23 -g -fsanitize=address,undefined -DLOCAL -Wall -Wextra -Wshadow $(SRC) -o $(EXE)
	@echo "=== Running in debug mode ==="
	@cat $(INPUT) | $(EXE)

clean:
	@echo "=== Cleaning binary ==="
	rm -f $(EXE)

.PHONY: all debug clean
