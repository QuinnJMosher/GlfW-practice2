#ifndef _Texture_h_
#define _Texture_h_
#include "SOIL.h"
#include <iostream>

class Texture {
public:
	Texture(const char* in_filename);
	~Texture();

	unsigned int GetTextureID();

private:
	unsigned int loadTexture(const char* a_pFilename, int & a_iWidth, int & a_iHeight, int & a_iBPP);

	unsigned int TextureID;

	int width;
	int height;
	int bpp;
};

#endif