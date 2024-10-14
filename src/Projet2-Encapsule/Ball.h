#pragma once

class Ball {
public:
	
	Ball(int x, int y, int size, sf::Texture texture, int speed, int lifespan);

	void move();

	void checkCollison();

	void changeDirection();

	void decrementLifespan(int time_elapsed);

	void checkLifespan();

private:

	void destroy();

	int	ball_x;
	int ball_y;
	int ball_speed;
	int ball_lifespan;
	sf::Sprite ball_sprite;

};