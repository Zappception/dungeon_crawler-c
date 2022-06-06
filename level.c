#include <stdlib.h>

#include "level.h"
#include "portal.h"

extern int level_get_width (LEVEL_TYPE *ptLevel)
{
	return ptLevel->iWidth;
}

extern int level_get_height (LEVEL_TYPE *ptLevel)
{
	return ptLevel->iHeight;
}

extern void level_init (LEVEL_TYPE *ptLevel, int iWidth, int iHeight)
{
	int iXCoord;
	int iYCoord;

	ptLevel->iWidth  = iWidth;
	ptLevel->iHeight = iHeight;
	ptLevel->a2tTiles = malloc((ptLevel->iWidth * ptLevel->iHeight * sizeof(TILE_TYPE)));

	TILE_TYPE (*tTiles)[ptLevel->iHeight] = ptLevel->a2tTiles;

	iYCoord = 0;
	for (iXCoord = 0; iXCoord < ptLevel->iWidth; iXCoord++)
	{
		tTiles[iXCoord][iYCoord].eTileType          = TILE_TYPE_WALL_TYPE;
		tTiles[iXCoord][iYCoord].ptTileSpecificData = NULL;
	}

	iYCoord = ptLevel->iHeight - 1;
	for (iXCoord = 0; iXCoord < ptLevel->iWidth; iXCoord++)
	{
		tTiles[iXCoord][iYCoord].eTileType           = TILE_TYPE_WALL_TYPE;
		tTiles[iXCoord][iYCoord].ptTileSpecificData = NULL;
	}

	iXCoord = 0;
	for (iYCoord = 1; iYCoord < ptLevel->iHeight - 1; iYCoord++)
	{
		tTiles[iXCoord][iYCoord].eTileType          = TILE_TYPE_WALL_TYPE;
		tTiles[iXCoord][iYCoord].ptTileSpecificData = NULL;
	}

	iXCoord = ptLevel->iWidth - 1;
	for (iYCoord = 1; iYCoord < ptLevel->iHeight - 1; iYCoord++)
	{
		tTiles[iXCoord][iYCoord].eTileType          = TILE_TYPE_WALL_TYPE;
		tTiles[iXCoord][iYCoord].ptTileSpecificData = NULL;
	}

	for (iXCoord = 1; iXCoord < ptLevel->iWidth - 1; iXCoord++)
	{
		for (iYCoord = 1; iYCoord < ptLevel->iHeight - 1; iYCoord++)
		{
			tTiles[iXCoord][iYCoord].eTileType          = TILE_TYPE_FLOOR_TYPE;
			tTiles[iXCoord][iYCoord].ptTileSpecificData = NULL;
		}
	}
}

extern void level_place_portals (LEVEL_TYPE *ptLevel, int iXCoordA, int iYCoordA, int iXCoordB, int iYCoordB)
{
	TILE_TYPE (*tTiles)[ptLevel->iHeight] = ptLevel->a2tTiles;

	tTiles[iXCoordA][iYCoordA].eTileType = TILE_TYPE_PORTAL_TYPE;
	tTiles[iXCoordB][iYCoordB].eTileType = TILE_TYPE_PORTAL_TYPE;

	tTiles[iXCoordA][iYCoordA].ptTileSpecificData = malloc(sizeof(PORTAL_DATA_TYPE));
	tTiles[iXCoordB][iYCoordB].ptTileSpecificData = malloc(sizeof(PORTAL_DATA_TYPE));

	((PORTAL_DATA_TYPE*)tTiles[iXCoordA][iYCoordA].ptTileSpecificData)->iXCoord = iXCoordA;
	((PORTAL_DATA_TYPE*)tTiles[iXCoordA][iYCoordA].ptTileSpecificData)->iYCoord = iYCoordA;
	((PORTAL_DATA_TYPE*)tTiles[iXCoordB][iYCoordB].ptTileSpecificData)->iXCoord = iXCoordB;
	((PORTAL_DATA_TYPE*)tTiles[iXCoordB][iYCoordB].ptTileSpecificData)->iYCoord = iYCoordB;

	((PORTAL_DATA_TYPE*)tTiles[iXCoordA][iYCoordA].ptTileSpecificData)->ptEndPoint = (PORTAL_DATA_TYPE*)tTiles[iXCoordB][iYCoordB].ptTileSpecificData;
	((PORTAL_DATA_TYPE*)tTiles[iXCoordB][iYCoordB].ptTileSpecificData)->ptEndPoint = (PORTAL_DATA_TYPE*)tTiles[iXCoordA][iYCoordA].ptTileSpecificData;
}

extern void level_place_character (LEVEL_TYPE *ptLevel, int iCharacterXPos, int iCharacterYPos)
{
	ptLevel->iCharacterXPos = iCharacterXPos;
	ptLevel->iCharacterYPos = iCharacterYPos;
}
