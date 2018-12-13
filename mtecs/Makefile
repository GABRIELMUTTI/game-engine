CXX  		:= g++
CXX_FLAGS 	:= -std=c++17 -fPIC -Wall -Wextra -Wfatal-errors -fdiagnostics-color -g
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
