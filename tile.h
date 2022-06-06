#ifndef TILE_H
#define TILE_H
typedef enum
{
	TILE_TYPE_FLOOR_TYPE,
	TILE_TYPE_WALL_TYPE,
	TILE_TYPE_PORTAL_TYPE,

	TILE_TYPE_TYPE_MAX
} TILE_TYPE_TYPE;

typedef struct
{
	TILE_TYPE_TYPE  eTileType;
	void           *ptTileSpecificData;
} TILE_TYPE;


extern char* tile_get_texture (TILE_TYPE tTile);
#endif // TILE_H
