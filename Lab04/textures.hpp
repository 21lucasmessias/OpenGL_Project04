#ifndef TEXTURES_H
#define TEXTURES_H

#include "main.hpp"

#define EMPTY_INDEX 0
#define BRICK_INDEX 1
#define ROOF_INDEX 2
#define ASPHALT_INDEX 3
#define GRASS_INDEX 4
#define DOOR_ONE_INDEX 5
#define DOOR_TWO_INDEX 6
#define DOOR_THREE_INDEX 7
#define DOOR_FOUR_INDEX 8
#define DOOR_FIVE_INDEX 9
#define DOOR_SIX_INDEX 10
#define DOOR_SEVEN_INDEX 11

using namespace std;
using namespace glm;

struct Texture {
	GLint TEXTURE_WIDTH;
	GLint TEXTURE_HEIGHT;
	unsigned char* TEXTURE;
};

void loadTextures();
void freeTextures();
void applyTexture(unsigned char* TEXTURE, GLint TEXTURE_WIDTH, GLint TEXTURE_HEIGHT);

extern vector<Texture> textures;

#endif