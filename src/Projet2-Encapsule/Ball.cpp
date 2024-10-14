#include "pch.h"
#include "Ball.h"

Ball::Ball(int x, int y, int size, sf::Texture texture, int speed, int lifespan)
{
	this->ball_x = x;
	this->ball_y = y;
	// create circle with size param
	this->ball_sprite.setTexture(texture);
	this->ball_speed = speed;
	this->ball_lifespan = lifespan;
}

void Ball::move()
{
	// move sprite from an angle with :
	// this->ball_sprite.setPosition()
	// &
	// this->ball_speed
}

void Ball::checkCollison()
{
	//if (this->ball_x < 0) { changeDirections() }
	//if (this->ball_y < 0) { ... }
	//if (this->ball_x > window.size_x) { ... }
	//if (this->ball_y > window.size_y) { ... }
}

void Ball::changeDirection()
{
	// need math helper
}

void Ball::decrementLifespan(int time_elapsed)
{
	this->ball_lifespan -= time_elapsed;
}

void Ball::checkLifespan()
{
	if (this->ball_lifespan <= 0) {
		destroy();
	}
}

void Ball::destroy()
{
	delete(this);
}
