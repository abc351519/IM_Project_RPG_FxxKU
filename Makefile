#compiler
CC=g++
CVER=-std=c++17
#header directory
IDIR=include
#.o directory
ODIR=obj
#implement directory
SRCDIR=source
#flags
CFLAGS=-I$(IDIR) $(CVER) 
LIBS=-lm 
#有新的標頭檔放這裡
_DEPS=def.h creature.h animation.h enemy.h player.h area.h event.h battle.h rune.h graph.h error.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
#.o file output
#有新的.o檔打在後面
_OBJ=main.o creature.o animation.o enemy.o player.o area.o event.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))
#原始碼，新的.cpp檔放這裡
_SRC=main.cpp creature.cpp animation.cpp enemy.cpp player.cpp event.cpp battle.cpp game.cpp rune.cpp graph.cpp
SRC=$(patsubst %,$(SRCDIR)/%,$(_SRC))


TARGET_APP=RPG_FxxKU.exe

#安心使用
runaway:
	$(CC) $(SRC) -o $(TARGET_APP) $(CFLAGS) $(LIBS)

$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET_APP): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

run: $(TARGET_APP)
	./$(TARGET_APP)

clean: 
	rm ./$(TARGET_APP) ./RPG_FxxKU&&rm $(OBJ)


main.o: $(SRCDIR)/main.cpp
	$(CC) $^ -o $(ODIR)/$@ $(CFLAGS) $(LIBS)
creature.o: $(SRCDIR)/creature.cpp
	$(CC) $^ -o $(ODIR)/$@ $(CFLAGS) $(LIBS)
animation.o: $(SRCDIR)/animation.cpp
	$(CC) $^ -o $(ODIR)/$@ $(CFLAGS) $(LIBS)
enemy.o: $(SRCDIR)/enemy.cpp
	$(CC) $^ -o $(ODIR)/$@ $(CFLAGS) $(LIBS)
player.o: $(SRCDIR)/player.cpp
	$(CC) $^ -o $(ODIR)/$@ $(CFLAGS) $(LIBS)
event.o: $(SRCDIR)/event.cpp
	$(CC) $^ -o $(ODIR)/$@ $(CFLAGS) $(LIBS)
battle.o: $(SRCDIR)/battle.cpp
	$(CC) $^ -o $(ODIR)/$@ $(CFLAGS) $(LIBS)
game.o: $(SRCDIR)/game.cpp
	$(CC) $^ -o $(ODIR)/$@ $(CFLAGS) $(LIBS)
rune.o: $(SRCDIR)/rune.cpp
	$(CC) $^ -o $(ODIR)/$@ $(CFLAGS) $(LIBS)
graph.o: $(SRCDIR)/graph.cpp
	$(CC) $^ -o $(ODIR)/$@ $(CFLAGS) $(LIBS)