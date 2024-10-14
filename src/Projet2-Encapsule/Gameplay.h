#pragma once
#include "Ball.h"

class Gameplay {
public :

	Gameplay();

	void StartGame();

private:

	std::vector<Ball> balls;
};