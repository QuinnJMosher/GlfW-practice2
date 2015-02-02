#ifndef _TextHandeler_h_
#define _TextHandeler_h_
#include "tinyxml2.h"
#include "Texture.h"
#include "Shape.h"
#include <string>
using namespace tinyxml2;

struct Character {

	Texture texture;

	float Upos;
	float Vpos;
	float width;
	float height;
	float Xoffset;
	float YOffset;
	float advance;
};

class TextHandeler {
public:
	TextHandeler();
	~TextHandeler();

	void SetFont(std::string in_fontName);
	Character GetChar(int in_char);
	
private:
	std::string fontName;
	Texture fontTexture;
	XMLDocument fontInfo;
};

#endif