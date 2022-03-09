#include<iostream>
#include<cmath>
#include<SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(1000, 800), "2D 360 degrees movement");

	sf::CircleShape ball(5);
	ball.setFillColor(sf::Color::White);
	ball.setOrigin(5, 5);

	sf::CircleShape roll(5);
	roll.setFillColor(sf::Color::Green);
	roll.setOrigin(5, 5);
	roll.setPosition(300, 250);

	sf::RectangleShape box(sf::Vector2f(10.0f, 10.0f));
	box.setFillColor(sf::Color::White);
	box.setOrigin(5, 5);

	int arr[500];
	bool move = false;


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed) {
				//Initial Ball placement
				if (event.key.code == sf::Keyboard::W) { ball.move(0, -25); }
				if (event.key.code == sf::Keyboard::A) { ball.move(-25, 0); }
				if (event.key.code == sf::Keyboard::S) { ball.move(0, 25); }
				if (event.key.code == sf::Keyboard::D) { ball.move(25, 0); }
				//Initial Box placement
				if (event.key.code == sf::Keyboard::Up) { box.move(0, -25); }
				if (event.key.code == sf::Keyboard::Left) { box.move(-25, 0); }
				if (event.key.code == sf::Keyboard::Down) { box.move(0, 25); }
				if (event.key.code == sf::Keyboard::Right) { box.move(25, 0); }
				//Initial Green placement
				if (event.key.code == sf::Keyboard::G){roll.setPosition(ball.getPosition().x, ball.getPosition().y); }
				if (event.key.code == sf::Keyboard::M) { move = true; }
			}
		}


		int Ballx = ball.getPosition().x;
		int Bally = ball.getPosition().y;
		int Boxx = box.getPosition().x;
		int Boxy = box.getPosition().y;

		//Horizontal distance;
		int horizontal = abs(Ballx - Boxx);
		//Vertical distance;
		int vertical = abs(Bally - Boxy);

		//Get Path
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			std::cout << horizontal << " " << vertical << std::endl;
			int s = horizontal / vertical;
			int p = horizontal % vertical;
			for (int i = vertical; i > 0; i--) {
				if (i <= p) {
					//std::cout << s + 1 << " , ";
					arr[vertical - i] = s + 1;
				}
				else {
					//std::cout << s << " , ";
					arr[vertical - i] = s;
				}
			}
			std::cout << "\n";
			int i = 0;
			while (i < vertical) {
				std::cout << arr[i] << " , ";
				i++;
			}
			std::cout << "\n\n";
		}

		if (move==true) {
			int i = 0;
			while (i < vertical) {
				std::cout << arr[i] << " , ";
				sf::sleep(sf::milliseconds(50));
				roll.move(-arr[i] ,-1);
				window.clear(sf::Color::Black);
				window.draw(ball);
				window.draw(box);
				window.draw(roll);
				window.display();
				i++;
			}
			move = false;
			std::cout << "\n\n";
		}


		window.clear(sf::Color::Black);
		window.draw(ball);
		window.draw(box);
		window.draw(roll);
		window.display();
	}
}
