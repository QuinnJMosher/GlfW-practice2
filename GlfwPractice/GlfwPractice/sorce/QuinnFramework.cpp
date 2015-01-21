#include "QuinnFramework.h"
int FrameworkInitalize() {
	if (glfwInit()) {
		FrameworkInstance::Init();
		return 0;
	}
	return -1;
}

void FrameworkShutdown() {
	FrameworkInstance::End();
	glfwTerminate();
}

int OpenWindow(float in_windowWidth, float in_windowHeight, char* in_windowName) {
	GLFWwindow* tempWinPtr = FrameworkInstance::GetFrwkInst()->renderer.OpenWindow(in_windowWidth, in_windowHeight, in_windowName);
	if (tempWinPtr == nullptr) {
		return -1;
	}
	FrameworkInstance::GetFrwkInst()->window = tempWinPtr;
	FrameworkInstance::GetFrwkInst()->renderer.Ininitalize();
	return 0;
}

bool FrameworkUpdate() {
	return FrameworkInstance::GetFrwkInst()->renderer.ShouldClose();
}

void FrameworkClearScreen() {
	FrameworkInstance::GetFrwkInst()->renderer.ClearScreen();
}

float GetWindowWidth() {
	return FrameworkInstance::GetFrwkInst()->renderer.GetWindowWidth();
}

float GetWindowHeight() {
	return FrameworkInstance::GetFrwkInst()->renderer.GetWindowHeight();
}

void DrawShape(Shape in_shape) {
	FrameworkInstance::GetFrwkInst()->renderer.RenderShape(in_shape);
}

void DrawSprite(Shape in_shape, Texture in_texture) {
	FrameworkInstance::GetFrwkInst()->renderer.RenderTexture(in_shape, in_texture);
}

bool GetKeyDown(int in_key) {
	if (glfwGetKey(FrameworkInstance::GetFrwkInst()->window, in_key) == GLFW_PRESS) {
		return true;
	}
	return false;
}

bool GetKeyUp(int in_key) {
	if (glfwGetKey(FrameworkInstance::GetFrwkInst()->window, in_key) == GLFW_RELEASE) {
		return true;
	}
	return false;
}

float GetMouseX() {
	double x = 0;
	double y = 0;
	glfwGetCursorPos(FrameworkInstance::GetFrwkInst()->window, &x, &y);
	return x;
}

float GetMouseY() {
	double x = 0;
	double y = 0;
	glfwGetCursorPos(FrameworkInstance::GetFrwkInst()->window, &x, &y);
	return GetWindowHeight() - y;
}

void GetMousePos(float& in_x, float& in_y) {
	double x = 0;
	double y = 0;
		glfwGetCursorPos(FrameworkInstance::GetFrwkInst()->window, &x, &y);
	in_x = x;
	in_y = GetWindowHeight() - y;
}

void HideMouse() {
	glfwSetInputMode(FrameworkInstance::GetFrwkInst()->window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

void ShowMouse() {
	glfwSetInputMode(FrameworkInstance::GetFrwkInst()->window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}