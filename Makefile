TARGET = AirWatcherSHABE

CC = g++
CCFLAGS = -g -ansi -pedantic -std=c++17 -fno-omit-frame-pointer
LDFLAGS = -g -fno-omit-frame-pointer

BUILDDIR := ./build
SOURCEDIR:= ./src

SRC = $(wildcard $(SOURCEDIR)/*.cpp)
OBJ:=$(SRC:$(SOURCEDIR)/%.cpp=$(BUILDDIR)/%.o)

all : dir $(TARGET)

$(TARGET): $(OBJ)
	@echo "Building $@..."
	@$(CC) $(LDFLAGS) $(OBJ) -o $@
	

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp
	@echo "Compiling $<..."
	@$(CC) $(CCFLAGS) -c $< -o $@

dir:
	@mkdir $(BUILDDIR)
	

clean:
	@echo "Cleaning..."
	@rm $(TARGET)
	@rm -r $(BUILDDIR) 
