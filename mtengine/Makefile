CC		:= g++
C_FLAGS 	:= -std=c++17 -fPIC -Wall -Wfatal-errors -fdiagnostics-color -g
LD_FLAGS 	:= -shared

INCLUDES	:= include

DEPS		:= ../mtecs 	\
		../mtgraphics 	\


INCLUDES	:= include 		\
		../mtecs/include 	\
		../mtgraphics/include 	\
		../utilities/include	\
		../deps 		\
		..deps/boost

LIBS := 	lib 			\
		../mtgraphics/bin 	\
		../mtecs/bin 		\
		../deps/assimp/bin 	\
		../deps/boost/bin

BIN		:= bin
SRC		:= src/mtengine
INCLUDE		:= $(foreach d, $(INCLUDES), -I$d)
LIB		:= $(foreach d, $(LIBS), -L$d)
TEST		:= tests

LIBRARIES	:= -lassimp -lmtecs -lmtgraphics


EXECUTABLE := libmtengine.so

all: $(BIN)/$(EXECUTABLE)

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


$(BIN)/$(EXECUTABLE): $(SRC)/*/** $(TEST)/*
	python -m cogapp -r include/mtengine/factory/ComponentRegister.hpp
	python -m cogapp -r include/mtengine/factory/SystemRegister.hpp
	$(CC) $(C_FLAGS) $(INCLUDE) $(DEP) $(LIB) $^ -o $@ $(LD_FLAGS) $(LIBRARIES)
