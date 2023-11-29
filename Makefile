#compiler
CC=clang++

#header directory
IDIR=include
#.o directory
ODIR=obj
#implement directory
SRCDIR=source
#ncurse directory
NCURSE_IDIR=/opt/homebrew/Cellar/ncurses/6.4/include
NCURSE_LDIR=/opt/homebrew/Cellar/ncurses/6.4/lib

#flags
CFLAGS=-I$(IDIR)
NCURSE_FLAG=-I$(NCURSE_IDIR) -L$(NCURSE_LDIR)
#ncurse flag
LIBS=-lm -lpthread -lpanel -lncurses
#include header file
_DEPS=def.h hello.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
#.o file output
_OBJ=main.o hello.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

_SRC=main.cpp hello.cpp
SRC=$(patsubst %,$(SRCDIR)/%,*.cpp)


TARGET_APP=dick


runaway:
	$(CC) $(SRC) -o $(TARGET_APP) $(CFLAGS) $(LIBS) && ./$(TARGET_APP)

$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET_APP): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) 

run: $(TARGET_APP)
	./$(TARGET_APP)

clean: 
	rm $(OBJ) && rm ./$(TARGET_APP)