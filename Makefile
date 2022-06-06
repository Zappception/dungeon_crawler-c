EXEC    = dungeon_crawler-c
OBJS    = main.c terminal_ui.c level.c dungeon_crawler.c tile.c
CCX     = x86_64-w64-mingw32-gcc
CFLAGS += -Wall -Wextra

linux: $(EXEC)

nds: $(EXEC).nds

windows: $(EXEC).exe

$(EXEC):
	$(CC) $(CFLAGS) -Dqwertz=1 $(OBJS) -o $(EXEC)

$(EXEC).nds: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS$(LDLIBS_$@))

$(EXEC).exe:
	$(CCX) $(CFLAGS) -Dqwertz=1 $(OBJS) -o $(EXEC).exe

romfs:
	$(ROMFSINST) /bin/$(EXEC)

clean:
	-rm -f $(EXEC) $(EXEC).nds $(EXEC).exe *.elf *.gdb *.o

