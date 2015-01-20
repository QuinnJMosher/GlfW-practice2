#include "FrameworkInstance.h"

FrameworkInstance* FrameworkInstance::instance = nullptr;

FrameworkInstance::FrameworkInstance() {
	renderer = RenderObj();
	//inHandeler = InputObj();
}

FrameworkInstance::~FrameworkInstance() { }

void FrameworkInstance::Init() {
	instance = new FrameworkInstance();
}

FrameworkInstance* FrameworkInstance::GetFrwkInst() {
	return instance;
}

void FrameworkInstance::End() {
	instance->~FrameworkInstance();
}