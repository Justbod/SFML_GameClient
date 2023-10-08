#pragma once
#include "SFML/Graphics.hpp"

struct SnakeSegment
{
	SnakeSegment(int x, int y) : position(x, y) {}
	sf::Vector2i position;
};
using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction { None, Up, Down, Left, Right };

class Snake
{
public:
	Snake(int l_blockSize);
	~Snake();

	//helper methods
	void SetDirection(Direction l_dir);
	Direction GetDirection();
	int GetSpeed();
	sf::Vector2i GetPosition();
	int GetLives();
	int GetScore();
	void IncreaseScore();
	bool HasLost();

	void Lose(); //handle losing here
	void ToggleLost();

	void Extend(); //grow the snake
	void Reset(); // reset to starting position

	void Move(); //movement method
	void Tick(); //update method
	void Cut(int l_segments); //method for cutting snake
	void Render(sf::RenderWindow& l_window); 
private:
	void CheckCollision();

	SnakeContainer m_snakeBody; //segment vector
	int m_size; //size of the graphics
	Direction m_dir; //current direction
	int m_speed; //speed of the snake
	int m_lives; //lives
	int m_score; //score
	bool m_lost; //losing state
	sf::RectangleShape m_bodyRect; //shape used in rendering
};