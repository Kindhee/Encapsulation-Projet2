#include "pch.h"
#include "Ball.h"

//Ball::Ball(int x, int y, int size, sf::Texture texture, int speed, int lifespan)
//{
//	this->ball_x = x;
//	this->ball_y = y;
//	// create circle with size param
//	this->ball_sprite.setTexture(texture);
//	this->ball_speed = speed;
//	this->ball_lifespan = lifespan;
//}

Ball::Ball(float x, float y, int dir_x, int dir_y, int size, float speed, int lifespan)
{
	this->ball_x = x;
	this->ball_y = y;

	this->ball_dir_x = dir_x;
	this->ball_dir_y = dir_y;

	this->ball_circle = sf::CircleShape(size);
	this->ball_circle.setOrigin(size / 2, size / 2);

	this->ball_speed = speed;
	this->ball_lifespan = lifespan;
}

void Ball::move(int size_x, int size_y)
{
	float rad = this->ball_circle.getRadius();

	int futureX = this->ball_x + this->ball_dir_x * this->ball_speed;
	int futureY = this->ball_y + this->ball_dir_y * this->ball_speed;

	if (futureX > size_x - rad || futureX < 0)
		this->ball_dir_x = -this->ball_dir_x;
	if (futureY > size_y - rad || futureY < 0)
		this->ball_dir_y = -this->ball_dir_y;

	this->ball_x += this->ball_dir_x * this->ball_speed;
	this->ball_y += this->ball_dir_y * this->ball_speed;

	this->ball_circle.setPosition(this->ball_x, this->ball_y);
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

void Ball::decrementLifespan(float time_elapsed)
{
	this->ball_lifespan -= time_elapsed;
}

int Ball::getLifespan()
{
	return this->ball_lifespan;
}
