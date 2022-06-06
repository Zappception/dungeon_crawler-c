#include <stdio.h>
#include <stdlib.h>

#include "tile.h"
#include "level.h"
#include "character.h"

extern void terminal_ui_draw (LEVEL_TYPE *ptLevel)
{
	int  iXCoord;
	int  iYCoord;
	TILE_TYPE (*tTiles)[ptLevel->iHeight] = ptLevel->a2tTiles;
	char *pcTexture;

	for (iYCoord = 0; iYCoord < level_get_height(ptLevel); iYCoord++)
	{
		for (iXCoord = 0; iXCoord < level_get_width(ptLevel); iXCoord++)
		{
			if ( (iXCoord == ptLevel->iCharacterXPos)
			  && (iYCoord == ptLevel->iCharacterYPos) )
			{
				printf("%s ", CHARACTER_TILE);
			}
			else
			{
				if ((pcTexture = tile_get_texture(tTiles[iXCoord][iYCoord])))
				{
					printf("%s ", pcTexture);
					free(pcTexture);
				}
			}
		}
		printf("\n");
	}
}
