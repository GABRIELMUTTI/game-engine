CXX  		:= g++
CXX_FLAGS 	:= -std=c++17 -fPIC -Wall -Wextra -Wfatal-errors -fdiagnostics-color -g

BIN		:= bin
MAIN		:= src
SRC		:= src
INCLUDE		:= -I../include -I../../utilities/include
LIB		:= ../bin
DEPS		:= ..

LIBRARIES	:= -lmtecs
EXECUTABLE	:= main

all: bdep $(BIN)/$(EXECUTABLE)

bdep:
	@echo "Building dependencies:"
	@$(foreach d, $(DEPS), cd $(d) && echo "\tBuilding $(d)." && make -s all;)

run: clean all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)
clean:
	-rm $(BIN)/*

