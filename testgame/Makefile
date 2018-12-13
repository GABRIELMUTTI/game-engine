CC		:= g++
C_FLAGS 	:= -std=c++11 -Wfatal-errors -fdiagnostics-color -g

DEPS		:= ../mtecs 	\
		../mtgraphics 	\
		../mtecs	\
		../mtengine

INCLUDES	:= include 		\
		../mtecs/include 	\
		../mtgraphics/include 	\
		../mtengine/include 	\
		../utilities/include	\
		../deps 		\
		..deps/boost

LIBS 		:= lib 			\
		../mtgraphics/bin 	\
		../mtecs/bin 		\
		../mtengine/bin 	\
		../deps/assimp/bin 	\
		../deps/boost/bin

BIN		:= bin
SRC		:= src/testgame/**
INCLUDE		:= $(foreach d, $(INCLUDES), -I$d)
LIB		:= $(foreach d, $(LIBS), -L$d)

LIBRARIES 	:= -lboost_serialization -lassimp -lmtecs -lmtgraphics -lmtengine

ifeq ($(OS),Windows_NT)
EXECUTABLE	:= main.exe
else
EXECUTABLE	:= main
endif

all: bdep $(BIN)/$(EXECUTABLE)

clean:
	$(RM) $(BIN)/$(EXECUTABLE)

call: clean
	@echo "Cleaning dependencies:"
	@$(foreach d, $(DEPS), cd $(d) && make -s clean && echo "\tCleaning $(d).";)


run:
	./$(BIN)/$(EXECUTABLE)

brun: clean all run

bdep:
	@echo "Building dependencies:"
	@$(foreach d, $(DEPS), cd $(d) && echo "\tBuilding $(d)." && make -s all;)

$(BIN)/$(EXECUTABLE): $(SRC)/*
	$(CC) $(C_FLAGS) $(INCLUDE) $(LIB) $^ -o $@ $(LIBRARIES)
