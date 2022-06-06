#include <stdio.h>
#include <string.h>

#include "tile.h"


extern char* tile_get_texture (TILE_TYPE tTile)
{
	char* pcTexture = NULL;

	switch(tTile.eTileType)
	{
		case TILE_TYPE_FLOOR_TYPE:
		{
			pcTexture = strdup(".");
		}
		break;

		case TILE_TYPE_WALL_TYPE:
		{
			pcTexture = strdup("#");
		}
		break;

		case TILE_TYPE_PORTAL_TYPE:
		{
			pcTexture = strdup("O");
		}
		break;

		default:
		{
			fprintf(stderr, "unknown tile: %d", tTile.eTileType);
		}
		break;
	}

	return pcTexture;
}
