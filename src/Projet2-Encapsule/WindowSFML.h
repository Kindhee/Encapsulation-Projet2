#pragma once
#include "Window.h"

class WindowSFML : public Window {
public:

	WindowSFML();

	void initWindow() override;

	void getWindow() override;
};