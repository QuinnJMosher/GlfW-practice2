#ifndef _QuinnFramework_h_
#define _QuinnFramework_h_
#include "FrameworkInstance.h"

//startup/shutdown meathods
int FrameworkInitalize();
void FrameworkShutdown();

int OpenWindow(float in_windowHeight, float in_windowWidth, char* in_windowName);

//a window must be open for the folowing meathods to work
//window Utility
bool FrameworkUpdate();
void FrameworkClearScreen();

float GetWindowWidth();
float GetWindowHeight();

//drawing meathods
void DrawShape(Shape in_shape);
void DrawSprite(Shape in_shape, Texture in_texture);

//Input Meathods
bool GetKeyDown(int in_key);
bool GetKeyUp(int in_key);

#endif 