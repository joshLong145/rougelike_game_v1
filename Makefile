CC = clang++
OPTS = -c -Wall

# Project name
PROJECT = rougeShooter

# Directories
OBJDIR = obj
SRCDIR = src

# Libraries
LIBS = -lstdc++ -lm -lsfml-graphics -lsfml-window -lsfml-system


# Files and folders
SRCS    = $(shell find $(SRCDIR) -name '*.cpp')
SRCDIRS = $(shell find . -name '*.cpp' | dirname {} | sort | uniq | sed 's/\/$(SRCDIR)//g' )
OBJS    = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

# Targets
rougeShooter: buildrepo $(OBJS)
	@echo "***Linking object files"
	$(CC) $(OBJS) $(LIBS) -o bin/$@
	@echo "****running binary"
	bin/$@
obj/%.o: src/%.cpp
	@echo "**** Creating object files"
	$(CC) $(OPTS) -c $< -o $@

clean:
	@echo "****Removing all files"
	rm $(PROJECT) $(OBJDIR) -Rf

buildrepo:
	@echo "****Building repository"
	@$(call make-repo)

# Create obj directory structure
define make-repo
	mkdir -p $(OBJDIR)
	for dir in $(SRCDIRS); \
	do \
		mkdir -p $(OBJDIR)/$$dir; \
	done
endef
