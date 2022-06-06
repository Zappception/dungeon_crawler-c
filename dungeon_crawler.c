#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dungeon_crawler.h"
#include "portal.h"


static void dungeon_crawler_move (LEVEL_TYPE *ptLevel, int iXDiff, int iYDiff);



static void dungeon_crawler_move (LEVEL_TYPE *ptLevel, int iXDiff, int iYDiff)
{
	int iNewXCoord = ptLevel->iCharacterXPos + iXDiff;
	int iNewYCoord = ptLevel->iCharacterYPos + iYDiff;
	TILE_TYPE (*tTiles)[ptLevel->iHeight] = ptLevel->a2tTiles;

	switch (tTiles[iNewXCoord][iNewYCoord].eTileType)
		{
		case TILE_TYPE_WALL_TYPE:
		{
			// do nothing
		}
		break;

		case TILE_TYPE_PORTAL_TYPE:
		{
			iNewXCoord = ((PORTAL_DATA_TYPE*)((PORTAL_DATA_TYPE*)tTiles[(ptLevel->iCharacterXPos + iXDiff)][(ptLevel->iCharacterYPos + iYDiff)].ptTileSpecificData)->ptEndPoint)->iXCoord;
			iNewYCoord = ((PORTAL_DATA_TYPE*)((PORTAL_DATA_TYPE*)tTiles[(ptLevel->iCharacterXPos + iXDiff)][(ptLevel->iCharacterYPos + iYDiff)].ptTileSpecificData)->ptEndPoint)->iYCoord;
			level_place_character(ptLevel, iNewXCoord, iNewYCoord);
		}
		break;

		default:
		{
			level_place_character(ptLevel, iNewXCoord, iNewYCoord);
		}
		break;
	}
}


extern bool dungeon_crawler_play (LEVEL_TYPE *ptLevel)
{
	char cInput;
	bool boReturn = false;
	//char cBuffer;

	//if(scanf("%c", &cInput) == 1)
	//{
	cInput = (char)fgetc(stdin);
	switch(cInput)
	{
		case 'q':
		{
			dungeon_crawler_move(ptLevel, -1, -1);
			boReturn = true;
		}
		break;

		case 'w':
		{
			dungeon_crawler_move(ptLevel, 0, -1);
			boReturn = true;
		}
		break;

		case 'e':
		{
			dungeon_crawler_move(ptLevel, 1, -1);
			boReturn = true;
		}
		break;

		case 'a':
		{
			dungeon_crawler_move(ptLevel, -1, 0);
			boReturn = true;
		}
		break;

		case 's':
		{
			//dungeon_crawler_move(ptLevel, 0, 0);
			boReturn = true;
		}
		break;

		case 'd':
		{
			dungeon_crawler_move(ptLevel, 1, 0);
			boReturn = true;
		}
		break;

#ifdef qwertz
		case 'y':
#else
		case 'z':
#endif // qwertz
		{
			dungeon_crawler_move(ptLevel, -1, 1);
			boReturn = true;
		}
		break;

		case 'x':
		{
			dungeon_crawler_move(ptLevel, 0, 1);
			boReturn = true;
		}
		break;

		case 'c':
		{
			dungeon_crawler_move(ptLevel, 1, 1);
			boReturn = true;
		}
		break;

		case 't':
		{
			exit(0);
		}
		break;

		case '\n':
		{
			// ignore
		}
		break;

		default:
		{
			fprintf(stderr, "invalid input: %c\n", cInput);
		}
		break;
   	}
	//}
	//else
	//{
		// clear buffer
		//while( (cBuffer = getchar() != '\n')
			//&& (cBuffer             != EOF) );
	//}
	return boReturn;
}
