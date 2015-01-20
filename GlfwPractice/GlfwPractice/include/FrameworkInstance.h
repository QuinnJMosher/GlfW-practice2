#ifndef _FrameworkInstance_h_
#define _FrameworkInstance_h_
#include "RenderObj.h"

class FrameworkInstance {
public:
	static void Init();
	static FrameworkInstance* GetFrwkInst();
	static void End();
	GLFWwindow* window;
	RenderObj renderer;
private:
	FrameworkInstance();
	~FrameworkInstance();
	static FrameworkInstance* instance;

};

#endif 