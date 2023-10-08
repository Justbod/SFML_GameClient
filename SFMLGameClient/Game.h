#pragma once
#include "SFML/Graphics.hpp"
#include "Window.h"

class Game
{
private:
	void MoveGift();
	Window m_window;
	sf::Texture m_giftTexture;
	sf::Sprite m_gift;
	sf::Vector2i m_increment;
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();
};