#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "terminal_ui.h"
#include "dungeon_crawler.h"


static LEVEL_TYPE *ptCurrentLevel;


//int main (int argc, char **argv)
int main (void)
{
	LEVEL_TYPE tFirstLevel;

	level_init(&tFirstLevel, 7, 7);
	level_place_portals(&tFirstLevel, 1, 2, 2, 3);
	level_place_character(&tFirstLevel, 1, 1);

	ptCurrentLevel = &tFirstLevel;

	terminal_ui_draw(ptCurrentLevel);

	while (true)
	{
		if (dungeon_crawler_play(ptCurrentLevel))
		{
			terminal_ui_draw(ptCurrentLevel);
		}
	}

}
