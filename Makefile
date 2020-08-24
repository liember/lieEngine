# type make TARGET=test for using test/main.cpp instead default input point path
# you may see default value in " TARGET " variable
# use " se456es " with ctrl + F for fast searc it

# ------------------------------------------------------------------------------------
# compiler 
CC = g++
CFLAGS = -Wall -std=c++17 -g -I include
DEPFLAGS = -MP -MMD 
DEPDIR = dep/
OBJDIR = build/
BINDIR = bin/
SRCDIR = src/
LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf 
SRC_FILES := $(wildcard $(SRCDIR)*.cpp)
OBJ_FILES := $(patsubst $(SRCDIR)%.cpp,$(OBJDIR)%.o,$(SRC_FILES))
DEP_FILES := $(wildcard $(DEPDIR)*.d)
EXECUTABLE = $(BINDIR)main

all:dirs $(MOD_MAKES) $(EXECUTABLE)
	@echo
	@echo [!][!][!][!][!] COMPILATION SUCSESS [!][!][!][!][!]
	@echo
	
# now its not autoconfigurable dependece
$(MODDIR)%:
	echo lol
	make -C $(basename $@)

# link object file with modules and compile
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ $(INCLUDE_FLAG) $(LIBS_FLAG) $(LIBS) -o $@
 
 # make object files from files in " SRCDIR " directory
$(OBJDIR)%.o : $(SRCDIR)%.cpp
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE_FLAG) -c -o $@ $< 
	mv -f $(OBJDIR)$*.d $(DEPDIR)$*.d

# make project's dirs
dirs:
	mkdir -p $(OBJDIR) $(BINDIR) $(DEPDIR) $(LIBDIR)

# remove unnecessary content of project's dirs	
clean:
	rm -f $(BINDIR)* $(OBJDIR)*.o $(DEPDIR)*.d

# remove project's dirs (don't remove " SRCDIR ")
cleanall:
	rm -R $(OBJDIR) $(BINDIR) $(DEPDIR) $(LIBDIR)

include $(DEP_FILES)

.PHONY: test
.PHONY: clean
.PHONY: cleanall
.PHONY: all