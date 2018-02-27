CC = g++
OBJS =src/*.cpp
LINKER_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
COMPILER_FLAGS = -std=c++14 -g
OBJ_Name = rougeShooter
BIN = bin/rougeShooter

#Compile and run
all: rougeShooter

%.o: %.cpp
	$(CXX) -c $< -o $@

%.o: %.hpp
	$(CXX) -c $< -o $@

rougeShooter:
	@echo "** building object files **"
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(BIN)$(OBJ_NAME)
	$(BIN)$(OBJ_NAME)

clean:
	@echo "** removing object files and executables **"
	rm -rf rougeShooter *.o

install:
	@echo "** installing..."
	cp bin/rougeShooter /usr/bin/

uninstall:
	@echo "** uninstalling...."
	$(RM) /usr/bin/rougeShooter
