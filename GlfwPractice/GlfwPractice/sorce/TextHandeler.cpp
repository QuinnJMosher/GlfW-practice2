#include "TextHandeler.h"

TextHandeler::TextHandeler() { }
TextHandeler::~TextHandeler() { }

void TextHandeler::SetFont(std::string in_fontName) {
	fontName = in_fontName;
	bool inRoot = true;
	if (fontInfo.LoadFile(in_fontName.c_str()) != XML_NO_ERROR) {
		in_fontName = "fonts/" + in_fontName;
		inRoot = false;
		if (fontInfo.LoadFile(in_fontName.c_str()) != XML_NO_ERROR) {
			throw "file not found";
		}
	}

	XMLElement* textureElement = fontInfo.FirstChildElement("font")->FirstChildElement("pages")->FirstChildElement("page");
	char* textureName;
	textureElement->Attribute("file", textureName);
	if (inRoot) {
		fontTexture = Texture(textureName);
	} else {
		std::string txNmAndFtDir = "fonts/" + *textureName;
		fontTexture = Texture(txNmAndFtDir.c_str);
	}

}
Character TextHandeler::GetChar(char in_char);

Character::Character();
Character::~Character();