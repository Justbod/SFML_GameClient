#include "Game.h"

Game::Game() : m_window("Chapter 2", sf::Vector2u(800, 600)) {
	//setting up class members
	m_giftTexture.loadFromFile("assets/gift_1.png");
	m_gift.setTexture(m_giftTexture);
	m_increment = sf::Vector2i(4, 4);
}

Game::~Game() {}

Window* Game::GetWindow() { return &m_window; }

void Game::HandleInput() {
	// Input handling.
}

void Game::Update()
{
	m_window.Update(); // update window events
	MoveGift();
}

void Game::MoveGift() 
{
	sf::Vector2u l_windSize = m_window.GetWindowSize();
	sf::Vector2u l_textSize = m_giftTexture.getSize();

	if ((m_gift.getPosition().x >
		l_windSize.x - l_textSize.x && m_increment.x > 0) ||
		(m_gift.getPosition().x < 0 && m_increment.x < 0)) {
		m_increment.x = -m_increment.x;
	}

	if ((m_gift.getPosition().y >
		l_windSize.y - l_textSize.y && m_increment.y > 0) ||
		(m_gift.getPosition().y < 0 && m_increment.y < 0)) {
		m_increment.y = -m_increment.y;
	}

	m_gift.setPosition( m_gift.getPosition().x + m_increment.x, m_gift.getPosition().y + m_increment.y );
}

void Game::Render()
{
	m_window.BeginDraw(); //clear
	m_window.Draw(m_gift);
	m_window.EndDraw(); //display
}


