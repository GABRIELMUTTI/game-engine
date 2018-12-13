CC		:= g++
C_FLAGS 	:= -std=c++17 -fPIC -Wall -Wfatal-errors -fdiagnostics-color -g
LD_FLAGS 	:= -shared

INCLUDES	:= include
DEPS		:= -I../deps -I../utilities/include
LIBS 		:= lib	
BIN		:= bin
SRC		:= src/mtgraphics
INCLUDE		:= $(foreach d, $(INCLUDES), -I$d)
LIB		:= $(foreach d, $(LIBS), -L$d)

LIBRARIES	:= -lglfw3 -lrt -lm -ldl -lX11 -lpthread -lXrandr -lXinerama -lXxf86vm -lXcursor
OUTPUT		:= libmtgraphics.so

all: $(BIN)/$(OUTPUT)

clean:
	$(RM) $(BIN)/$(OUTPUT)

run:
	./$(BIN)/$(OUTPUT)

brun: clean all run

$(BIN)/$(OUTPUT): $(SRC)/*/**
	$(CC) $(C_FLAGS) $(INCLUDE) $(DEPS) $(LIB) $^ -o $@ $(LIBRARIES) $(LD_FLAGS)
