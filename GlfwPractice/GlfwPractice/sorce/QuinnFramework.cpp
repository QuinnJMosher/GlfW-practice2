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
}

int OpenWindow(float in_windowHeight, float in_windowWidth, char* in_windowName) {
	GLFWwindow* tempWinPtr = FrameworkInstance::GetFrwkInst()->renderer.OpenWindow(in_windowHeight, in_windowWidth, in_windowName);
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