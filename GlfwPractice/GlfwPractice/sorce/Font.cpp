#include "Font.h"

FT_Library Font::FTL_Instance = nullptr;

Font::Font(const char* in_fontname, int in_size) {
	fontname = in_fontname;
	fontSize = in_size;

	if (FTL_Instance == nullptr) {
		if (FT_Init_FreeType(&FTL_Instance) != FT_Err_Ok) {
			FTL_Instance = nullptr;
			return;
		}
	}
	
	if (FT_New_Face(FTL_Instance, fontname, 0, &face) != FT_Err_Ok) {
		this->~Font();
		return;
	}

	FT_Set_Pixel_Sizes(face, 0, fontSize);

}

Font::~Font() { }

int Font::GetFontSize() {
	return fontSize;
}
const char* Font::getFontName() {
	return fontname;
}

void Font::SetGlyph(char in_glyph) {

	FT_Load_Char(face, in_glyph, FT_LOAD_RENDER);

}
FT_GlyphSlot* Font::GetGlyphSlot() {
	return &(face->glyph);
}