#pragma once
#include "Ball.h"

class Gameplay {
public :

	Gameplay();

	void game(sf::RenderWindow* window);

	void displayGame(sf::RenderWindow* window);


private:

	std::vector<Ball*> balls;

	float timer = 0;
};