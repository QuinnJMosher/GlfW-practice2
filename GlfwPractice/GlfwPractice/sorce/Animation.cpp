#include "Animation.h"

Animation::Animation(Texture in_spriteSheet, Shape in_startingShape, unsigned int in_numFramesWide, unsigned int in_numFramesTall) {
	spriteSheet = in_spriteSheet;
	shape = in_startingShape;
	FramesWide = in_numFramesWide;
	FramesTall = in_numFramesTall;
	currentFrameX = 1;
	currentFrameY = 1;

	shape.SetUVLength(1.0f / FramesWide, 1.0f / FramesTall);
}
Animation::Animation(const char* in_spriteSheetName, Shape in_startingShape, unsigned int in_numFramesWide, unsigned int in_numFramesTall) {
	spriteSheet = Texture(in_spriteSheetName);
	shape = in_startingShape;
	FramesWide = in_numFramesWide;
	FramesTall = in_numFramesTall;
	currentFrameX = 1;
	currentFrameY = 1;

	shape.SetUVLength(1.0f / FramesWide, 1.0f / FramesTall);
}
Animation::Animation(Texture in_spriteSheet, float in_startPosX, float in_startposY, float in_startWidth, float in_startHeight, unsigned int in_numFramesWide, unsigned int in_numFramesTall) {
	spriteSheet = in_spriteSheet;
	shape = Shape(shapeType::RECTANGLE, in_startPosX, in_startposY, in_startHeight, in_startWidth);
	FramesWide = in_numFramesWide;
	FramesTall = in_numFramesTall;
	currentFrameX = 1;
	currentFrameY = 1;

	shape.SetUVLength(1.0f / FramesWide, 1.0f / FramesTall);
}
Animation::Animation(const char* in_spriteSheetName, float in_startPosX, float in_startposY, float in_startWidth, float in_startHeight, unsigned int in_numFramesWide, unsigned int in_numFramesTall) {
	spriteSheet = Texture(in_spriteSheetName);
	shape = Shape(shapeType::RECTANGLE, in_startPosX, in_startposY, in_startHeight, in_startWidth);
	FramesWide = in_numFramesWide;
	FramesTall = in_numFramesTall;
	currentFrameX = 1;
	currentFrameY = 1;

	shape.SetUVLength(1.0f / FramesWide, 1.0f / FramesTall);
}
Animation::~Animation() {  };

void Animation::SetFrame(unsigned int in_frameX, unsigned int in_frameY) {
	currentFrameX = in_frameX;
	currentFrameY = in_frameY;

	shape.SetUVStart(shape.GetULength() * (currentFrameX - 1), shape.GetVLength() * (currentFrameY - 1));
}
void Animation::NextFrameX() {
	currentFrameX++;
	if ((currentFrameX - 1) * shape.GetULength() >= 1) {
		currentFrameX = 1;
	}
	shape.SetUVStart(shape.GetULength() * (currentFrameX - 1), shape.GetVLength() * (currentFrameY - 1));
}
void Animation::NextFrameY() {
	currentFrameY++;
	if ((currentFrameY - 1) * shape.GetVLength() >= 1) {
		currentFrameY = 1;
	}
	shape.SetUVStart(shape.GetULength() * (currentFrameX - 1), shape.GetVLength() * (currentFrameY - 1));
}
void Animation::NextFrameAll() {
	NextFrameX();
	if (currentFrameX == 1) {
		NextFrameY();
	}
}

void Animation::ChangeNumFrames(unsigned int in_framesWide, unsigned int in_framesTall) {
	FramesWide = in_framesWide;
	FramesTall = in_framesTall;
	currentFrameX = 1;
	currentFrameY = 1;

	shape.SetUVLength(1.0f / FramesWide, 1.0f / FramesTall);
}

void Animation::ChangeSpriteSheet(Texture in_newSpriteSheet) {
	spriteSheet = in_newSpriteSheet;
}

void Animation::ChangeSpriteSheet(const char* in_newSpriteSheetName) {
	spriteSheet = Texture(in_newSpriteSheetName);
}

void Animation::MoveTo(float in_x, float in_y) {
	shape.SetPos(in_x, in_y);
}

void Animation::ChangeSize(float in_xWidth, float in_yWidth) {
	shape.SetWidth(in_yWidth);
	shape.SetHeight(in_xWidth);
}

unsigned int Animation::GetCurrentFrameX() {
	return currentFrameX;
}

unsigned int Animation::GetCurrentFrameY() {
	return currentFrameY;
}

unsigned int Animation::GetFramesWide() {
	return FramesWide;
}

unsigned int Animation::GetFramesTall() {
	return FramesTall;
}

Texture Animation::GetTexture() {
	return spriteSheet;
}

Shape Animation::GetShape() {
	return shape;
}