#pragma once
#include "SFML/Graphics.hpp"
#include "Window.h"

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
private:
	void MoveGift();
	Window m_window;

	sf::Texture m_giftTexture;
	sf::Sprite m_gift;
	sf::Vector2i m_increment;

	sf::Clock m_clock;
	sf::Time m_elapsed;
};