#ifndef LEVEL_H
#define LEVEL_H
#include "tile.h"

typedef struct
{
	int   iWidth;
	int   iHeight;
	void *a2tTiles;
	int   iCharacterXPos;
	int   iCharacterYPos;

} LEVEL_TYPE;


extern int level_get_width  (LEVEL_TYPE *ptLevel);
extern int level_get_height (LEVEL_TYPE *ptLevel);

extern void level_init            (LEVEL_TYPE *ptLevel, int iWidth, int iHeight);
extern void level_place_portals   (LEVEL_TYPE *ptLevel, int iXCoordA, int iYCoordA, int iXCoordB, int iYCoordB);
extern void level_place_character (LEVEL_TYPE *ptLevel, int iCharacterXPos, int iCharacterYPos);
#endif // LEVEL_H
