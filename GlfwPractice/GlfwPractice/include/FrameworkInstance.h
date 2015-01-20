#ifndef _FrameworkInstance_h_
#define _FrameworkInstance_h_
#include "RenderObj.h"

class FrameworkInstance {
public:
	static void Init();
	static FrameworkInstance* GetFrwkInst();
	GLFWwindow* window;
	RenderObj renderer;
	//InputObj inHandeler;
private:
	FrameworkInstance();
	~FrameworkInstance();
	static FrameworkInstance* instance;

};

#endif 