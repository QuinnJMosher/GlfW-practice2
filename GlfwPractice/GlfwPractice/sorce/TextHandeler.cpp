#include "TextHandeler.h"

TextHandeler::TextHandeler() { }
TextHandeler::~TextHandeler() {
	GLuint targetId = fontTexture.GetTextureID();
	glDeleteTextures(1, &targetId);
	fontTexture.~Texture();
	fontInfo.~XMLDocument();
}

void TextHandeler::SetFont(std::string in_fontName) {
	fontName = in_fontName;
	if (fontInfo.LoadFile(in_fontName.c_str()) != XML_NO_ERROR) {
			throw "file not found";
	}

	XMLElement* textureElement = fontInfo.FirstChildElement("font")->FirstChildElement("pages")->FirstChildElement("page");
	const char* textureName = textureElement->Attribute("file");
	fontTexture = Texture(textureName);

}

Character TextHandeler::GetChar(int in_char) {
	Character output;
	output.texture = fontTexture;
	XMLElement* element = fontInfo.FirstChildElement("font")->FirstChildElement("chars")->FirstChildElement("char");

	while (element->IntAttribute("id") != in_char && element->IntAttribute("id") <= 255) {
		element = element->NextSiblingElement();
	}

	//normalize these
	output.Upos = element->IntAttribute("x") / (float)fontTexture.width;
	output.Vpos = element->IntAttribute("y") / (float)fontTexture.height;
	output.width = element->IntAttribute("width") / (float)fontTexture.width;
	output.height = element->IntAttribute("height") / (float)fontTexture.height;
	//thses can be left alone
	output.Xoffset = element->FloatAttribute("xoffset");
	output.YOffset = element->FloatAttribute("yoffset");
	output.advance = element->FloatAttribute("xadvance");

	return output;

}