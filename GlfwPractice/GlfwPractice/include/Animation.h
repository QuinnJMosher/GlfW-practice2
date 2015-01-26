#ifndef _Animation_h_
#define _Animation_h_
#include "shape.h"
#include "Texture.h"

class Animation {
public:
	Animation(Texture in_spriteSheet, Shape in_startingShape, unsigned int in_numFramesWide, unsigned int in_numFramesTall);
	Animation(const char* in_spriteSheetName, Shape in_startingShape, unsigned int in_numFramesWide, unsigned int in_numFramesTall);
	Animation(Texture in_spriteSheet, float in_startPosX, float in_startposY, float in_startWidth, float in_startHeight, unsigned int in_numFramesWide, unsigned int in_numFramesTall);
	Animation(const char* in_spriteSheetName, float in_startPosX, float in_startposY, float in_startWidth, float in_startHeight, unsigned int in_numFramesWide, unsigned int in_numFramesTall);
	~Animation();
	
	void SetFrame(unsigned int in_frameX, unsigned int in_frameY);
	void NextFrameX();
	void NextFrameY();
	void NextFrameAll();

	void ChangeNumFrames(unsigned int in_framesWide, unsigned int in_framesTall);//resets current frame

	void ChangeSpriteSheet(Texture in_newSpriteSheet);
	void ChangeSpriteSheet(const char* in_newSpriteSheetName);
	void MoveTo(float in_x, float in_y);
	void ChangeSize(float in_xWidth, float in_yWidth);

	unsigned int GetCurrentFrameX();
	unsigned int GetCurrentFrameY();
	unsigned int GetFramesWide();
	unsigned int GetFramesTall();

	Texture GetTexture();
	Shape GetShape();

private:
	Texture spriteSheet;
	Shape shape;

	unsigned int FramesWide;
	unsigned int FramesTall;
	unsigned int currentFrameX;
	unsigned int currentFrameY;
};

#endif