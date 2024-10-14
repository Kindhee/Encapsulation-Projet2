#pragma once
#include "Window.h"

class WindowGDI : public Window {
public:

	WindowGDI();

	void initWindow() override;

	void getWindow() override;
};