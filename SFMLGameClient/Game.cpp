#include "Game.h"

Game::Game() : m_window("Snake", sf::Vector2u(800, 600)), m_snake(m_world.getBLockSize()),m_world(sf::Vector2u(800,600)) {

	//setting up class members
	m_giftTexture.loadFromFile("assets/gift_1.png");
	m_gift.setTexture(m_giftTexture);
	m_increment = sf::Vector2i(40, 40);
}

Game::~Game() {}

sf::Time Game::getElapsed() { return m_clock.getElapsedTime(); }
void Game::RestartClock() { m_elapsed += m_clock.restart().asSeconds(); }
Window* Game::GetWindow() { return &m_window; }

void Game::HandleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
		&& m_snake.GetDirection() != Direction::Down)
	{
		m_snake.SetDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
		&& m_snake.GetDirection() != Direction::Up)
	{
		m_snake.SetDirection(Direction::Down);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
		&& m_snake.GetDirection() != Direction::Right)
	{
		m_snake.SetDirection(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
		&& m_snake.GetDirection() != Direction::Left)
	{
		m_snake.SetDirection(Direction::Right);
	}
}

void Game::Update()
{
	float timestep = 1.0f / m_snake.GetSpeed();

	if (m_elapsed >= timestep) {
		m_snake.Tick();
		m_world.Update(m_snake);
		m_elapsed -= timestep;
		if (m_snake.HasLost()) {
			m_snake.Reset();
		}
	}

	m_window.Update(); // update window events
	//MoveGift();
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

	/*float fElasped = m_elapsed.asSeconds();

	m_gift.setPosition( m_gift.getPosition().x + (m_increment.x * fElapsed), 
						m_gift.getPosition().y + (m_increment.y * fElasped));
						*/
}

void Game::Render()
{
	m_window.BeginDraw(); //clear
	// render here
	m_world.Render(*m_window.GetRenderWindow());
	m_snake.Render(*m_window.GetRenderWindow());

	m_window.EndDraw(); //display
}


