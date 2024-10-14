#include "pch.h"
#include "Gameplay.h"

Gameplay::Gameplay()
{

}

void Gameplay::displayGame(sf::RenderWindow* window)
{
	for (int i = balls.size(); i > 0; i--)
	{
		Ball* ball_temp = balls[i - 1];
		window->draw(ball_temp->ball_circle);
	}
}

void Gameplay::game(sf::RenderWindow* window)
{

	timer += 0.333;

	if (timer > 600)
	{
		timer = 0;
		Ball* ball_temp = new Ball(100, 100, 1, 1, 10, 0.2f, 600);
		balls.push_back(ball_temp);
	}

	for (int i = balls.size(); i > 0; i--)
	{
		balls[i - 1]->move(window->getSize().x, window->getSize().y);

		balls[i - 1]->decrementLifespan(0.1f); // delta time next

		if (balls[i - 1]->getLifespan() <= 0.f)
		{
			delete balls[i - 1];
			balls.erase(balls.begin() + (i - 1));
		}
	}
}

