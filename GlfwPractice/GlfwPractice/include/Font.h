#ifndef _Font_h_
#define _Font_h_
#include "ft2build.h"
#include FT_FREETYPE_H
#include <cassert>

class Font {
public:
	Font(const char* in_fontname, int in_size);
	~Font();

	FT_Face getface();
private:
	static FT_Library FreeTypeInstance;
	FT_Face fontFace;
	int fontSize;
	FT_GlyphSlot currentGlyph;

};

#endif