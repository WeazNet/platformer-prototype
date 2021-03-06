OBJS = *.cpp debug/*.cpp
COMPILER = g++
COMPILER_FLAGS = -Wall -g
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = main

all: $(OBJS)
	$(COMPILER) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)