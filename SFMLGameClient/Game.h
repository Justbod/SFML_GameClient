#pragma once
#include "SFML/Graphics.hpp"
#include "Window.h"
#include "World.h"
#include "Snake.h"

class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();

	sf::Time getElapsed();
	void RestartClock();

	World m_world;
	Snake m_snake;
private:
	void MoveGift();
	Window m_window;

	sf::Texture m_giftTexture;
	sf::Sprite m_gift;
	sf::Vector2i m_increment;

	sf::Clock m_clock;
	float m_elapsed;
};