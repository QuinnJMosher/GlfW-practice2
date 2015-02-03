#ifndef _QuinnFramework_h_
#define _QuinnFramework_h_
#include "FrameworkInstance.h"
#include "Animation.h"

//startup/shutdown meathods
int FrameworkInitalize();
void FrameworkShutdown();
void DeleteTexture(Texture& target);

int OpenWindow(float in_windowWidth, float in_windowHeight, char* in_windowName);

//a window must be open for the folowing meathods to work
//window Utility
bool FrameworkUpdate();
void FrameworkClearScreen();

float GetWindowWidth();
float GetWindowHeight();

//drawing meathods
//void DrawShape(Shape in_shape);
void DrawSprite(Shape in_shape, Texture in_texture);
void DrawAnimation(Animation in_animation);
//text Drawing
void DrawString(const char* in_text, float in_xpos, float in_ypos, Color in_color = Color(1, 1, 1, 1));
void SetFontSize(float in_size);
void SetFont(const char* in_fontName);

//Input Meathods
bool GetKeyDown(int in_key);
bool GetKeyUp(int in_key);

//mouse Input/util
float GetMouseX();
float GetMouseY();
void GetMousePos(float& in_x, float& in_y);
void HideMouse();
void ShowMouse();

#endif 