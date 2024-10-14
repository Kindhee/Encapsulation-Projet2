#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <windows.h>

#include "resource.h"

#include "Maths.h"

#include "Texture.h"
#include "Sprite.h"
#include "Window.h"
#include "Renderer.h"
#include "Ball.h"

#include "Gameplay.h"
#include "PerformanceTester.h"

#ifdef _DEBUG
#include <crtdbg.h>
#define DEBUG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DEBUG_NEW
#endif
