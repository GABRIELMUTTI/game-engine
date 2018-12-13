CC		:= g++
C_FLAGS 	:= -std=c++17 -Wall -Wextra -w -Wfatal-errors -g -fPIC
LD_FLAGS 	:= -shared

INCLUDES	:= include

DEPS		:= ../mtecs/include 	\
		../mtgraphics/include 	\
		../utilities/include 	\
		../deps 		\
		../deps/boost

LIBS := lib 				\
		../mtgraphics/bin 	\
		../mtecs/bin 		\
		../deps/assimp/bin 	\
		../deps/boost/bin

BIN		:= bin
SRC		:= src/mtengine
INCLUDE		:= $(foreach d, $(INCLUDES), -I$d)
DEP		:= $(foreach d, $(DEPS), -I$d)
LIB		:= $(foreach d, $(LIBS), -L$d)

LIBRARIES	:= -lassimp -lmtecs -lmtgraphics


EXECUTABLE := libmtengine.so

all: $(BIN)/$(EXECUTABLE)

clean:
	$(RM) $(BIN)/$(EXECUTABLE)

run:
	./$(BIN)/$(EXECUTABLE)

brun: clean all run

$(BIN)/$(EXECUTABLE): $(SRC)/*/**
	lua registry/CreateSystemRegister.lua
	lua registry/CreateComponentRegister.lua
	$(CC) $(C_FLAGS) $(INCLUDE) $(DEP) $(LIB) $^ -o $@ $(LD_FLAGS) $(LIBRARIES)
