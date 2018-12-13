CXX  		:= g++
CXX_FLAGS 	:= -Wall -Wextra -std=c++17 -Wfatal-errors -fdiagnostics-color -g -fPIC
LD_FLAGS 	:= -shared

BIN		:= bin
MAIN		:= src
SRC		:= src/mtecs/**
INCLUDE		:= -Iinclude -I../utilities/include
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= libmtecs.so

all: $(BIN)/$(EXECUTABLE)

run: clean all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES) $(LD_FLAGS)
clean:
	-rm $(BIN)/*
