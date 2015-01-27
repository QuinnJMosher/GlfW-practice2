#include "Font.h"

FT_Library Font::FreeTypeInstance = NULL;

Font::Font(const char* in_fontname, int in_size) {
	if (FreeTypeInstance = NULL) {
		assert(!FT_Init_FreeType(&FreeTypeInstance));
	}

	FT_New_Face(FreeTypeInstance, in_fontname, 0, &fontFace);

	FT_Set_Pixel_Sizes(fontFace, 0, in_size);
}

Font::~Font() { }

FT_Face Font::getface() {
	return fontFace;
}