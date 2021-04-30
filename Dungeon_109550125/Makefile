OBJS = main.o Dungeon.o Monster.o NPC.o Chest.o \
		Player.o Room.o GameCharacter.o Item.o Object.o Record.o
CFLAGS = -MD

Dungeon: $(OBJS)
	g++ $(OBJS) -o Dungeon

%.o: %.cpp
	g++ $(CFLAGS) -o $@ -c $<

clean:
	rm Dungeon *.o *.d *.h.gch data

.PHONY: Dungeon clean

-include $(OBJS:.o=.d)
