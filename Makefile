#compiler
CC=g++

#header directory
IDIR=include
#.o directory
ODIR=obj
#implement directory
SRCDIR=source
#ncurse directory
#NCURSE_IDIR=/opt/homebrew/Cellar/ncurses/6.4/include
#NCURSE_LDIR=/opt/homebrew/Cellar/ncurses/6.4/lib

#flags
CFLAGS=-I$(IDIR)
#NCURSE_FLAG=-I$(NCURSE_IDIR) -L$(NCURSE_LDIR)
#ncurse flag
LIBS=-lm #-lpthread -lpanel -lncurses
#include header file
#有新的標頭檔放這裡
_DEPS=def.h hello.h creature.h animation.h enemy.h player.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
#.o file output
#有新的.o檔打在後面
_OBJ=main.o hello.o creature.o animation.o enemy.o player.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))
#原始碼，新的.cpp檔放這裡
_SRC=main.cpp hello.cpp creature.cpp animation.cpp enemy.cpp player.cpp
SRC=$(patsubst %,$(SRCDIR)/%,*.cpp)


TARGET_APP=RPG_FxxKU


runaway:
	$(CC) $(SRC) -o $(TARGET_APP) $(CFLAGS) $(LIBS)

$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET_APP): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

run: $(TARGET_APP)
	./$(TARGET_APP)

clean: 
	rm $(OBJ) && rm ./$(TARGET_APP)