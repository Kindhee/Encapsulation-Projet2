#pragma once
#include "pch.h"

class Ball {
public:
	
	//Ball(int x, int y, int size, sf::Texture texture, int speed, int lifespan);

	Ball(float x, float y, int dir_x, int dir_y, int size, float speed, int lifespan);

	void move(int size_x, int size_y);

	void checkCollison();

	void changeDirection();

	void decrementLifespan(float time_elapsed);

	int getLifespan();

	sf::CircleShape ball_circle;

private:

	float ball_x;
	float ball_y;
	int ball_dir_x;
	int ball_dir_y;
	float ball_speed;
	float ball_lifespan;

	//sf::Sprite ball_sprite;

};