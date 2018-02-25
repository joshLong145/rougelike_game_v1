CC = g++
OBJS = *.cpp
LINKER_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
COMPILER_FLAGS = -std=c++14
OBJ_Name = rougeShooter
BIN = bin/log.txt

#Compile and run

all: thegame
	  $(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(BIN)$(OBJ_NAME)
	  $(BIN)$(OBJ_NAME)

