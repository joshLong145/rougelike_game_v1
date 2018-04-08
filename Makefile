CC = clang #using clang for elacticity. 

APP = Issac_clone

SRCS = src/*.cpp

LINKER_FLAGS = -lstdc++ -lm -lsfml-graphics -lsfml-window -lsfml-system

COMPILER_FLAGS = -std=c++14

OBJ_NAME = rougeShooter

BUILD_DIR = bin/

OBJDIR = obj/

OBJS := $(patsubst %.cpp,$(OBJDIR)%.o,$(SRCS))

CFLAGS = -Wall -g

all: $(APP)


$(APP) : $(OBJS)
	@echo "*** Linking libraries ***"
	$(CC) $(OBJS) $(LINKER_FLAGS) -o $@

%.o: %.cpp
	$(CC) $(LINKER_FLAGS) $(COMPILER_FLAGS) $(CFLAGS) -c $< -o $@

#Compile and run
obj/%.o: $(SRCS)
	$(CC) $(CFLAGS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -c $< -o $@

build:
	@echo "** Compiling files... this will take a bit. **"
	$(CC) $(SRCS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(BUILD_DIR)$(OBJ_NAME)
	$(BUILD_DIR)$(OBJ_NAME)

clean:
	@echo "** removing object files and executables **"
	rm -rf rougeShooter *.o

install:
	@echo "** installing..."
	cp bin/rougeShooter /usr/bin/

uninstall:
	@echo "** uninstalling...."
	$(RM) /usr/bin/rougeShooter

	.phony clean
