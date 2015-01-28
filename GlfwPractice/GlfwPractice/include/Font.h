#ifndef _Font_h_
#define _Font_h_
#include <cassert>
#include "ft2build.h"
#include FT_FREETYPE_H

class Font {
public:
	Font(const char* in_fontname, int in_size);
	~Font();

	int GetFontSize();
	const char* getFontName();

	void SetGlyph(char in_glyph);
	FT_GlyphSlot* GetGlyphSlot();
private:
	static FT_Library FTL_Instance;
	FT_Face face;

	int fontSize;
	const char* fontname;

};

#endif