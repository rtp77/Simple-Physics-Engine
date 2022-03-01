#include<iostream>
#include<SFML/Graphics.hpp>

int main(int argc, char** argv[]) {

	sf::RenderWindow window(sf::VideoMode(1000, 800), "Fluid Flow");

	bool aiming = false;
	bool action = false;
	float velocity = 0;
	float acceleration = 9.81;

	sf::Clock clock;

	sf::CircleShape ball(40);
	ball.setPosition(300, 100);
	ball.setOrigin(ball.getRadius(),ball.getRadius());

	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
			else if (e.type==sf::Event::MouseButtonPressed and e.type!=sf::Event::MouseButtonReleased) {
				aiming = true;
				action = false;
			}
			else if (e.type == sf::Event::MouseButtonReleased and e.type != sf::Event::MouseButtonPressed) {
				aiming = false;
				clock.restart();
				action = true;
			}
		}

		//Aiming
		if (aiming == true) {
			ball.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
		}

		//Velocity=Acceleration*Time
		if (action == true) {
			sf::Time t = clock.getElapsedTime();
			velocity = acceleration * t.asSeconds();
			if (ball.getPosition().y >= (window.getSize().y - 42)) { action = false; }
		}

		//Action
		if (action == true) {
			ball.move(0, velocity);
		}


		window.clear(sf::Color::Black);
		window.draw(ball);
		window.display();
		
	}
}
