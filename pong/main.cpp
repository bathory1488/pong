#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <iostream>
using namespace sf;
#define game_H 900
#define game_W 1200
float x1 = 450, x2 = game_H / 2;
float X1 = game_H / 2;
float Y1 = game_W / 2;
float dx = 1, dy = 1;
float r1 = 15;
int SSplayer2 = 0;
int SSplayer1 = 0;
int FPS = 260;


int main()
{
	Font font;
	font.loadFromFile("D:\\Downloads\\a_CampusPrspDnSh.ttf");
	Text text("", font, 100);

	srand(time(NULL));

	RenderWindow window(VideoMode(game_W, game_H), "PONG", Style::Close);
	window.setFramerateLimit(FPS);

	ContextSettings settings;
	settings.antialiasingLevel = 10;

	CircleShape shape(15.f);
	shape.setFillColor(Color::Black);
	shape.setOutlineThickness(5.f);
	shape.setOutlineColor(Color(1000, 1000, 1000));
	shape.setPosition(game_W / 2 - 8, game_H / 2);

	RectangleShape line;
	line.setSize(Vector2f(15, 900));
	line.setFillColor(Color::White);
	line.setPosition(1200 / 2, 900 / 2 - 450);

	RectangleShape player1;
	player1.setSize(Vector2f(15, 150));
	
	RectangleShape player2;
	player2.setSize(Vector2f(15, 150));
	
	while (window.isOpen())
	{
	
		Event event;
		while (window.pollEvent(event))
		{
		
			if (event.type == Event::Closed)
			
				window.close();
		}

		Vector2f pos = player1.getPosition();
		int y_1 = pos.y;
		Vector2f  pos_2 = player2.getPosition();
		int y2 = pos_2.y;

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			if (x1 < 0) { x1 = 0; }
			x1--;
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			if (x1 > game_H - 150) { x1 = game_H - 150;  }
			x1++;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			if (x2 < 0) { x2 = 0; }
			x2--;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			if (x2 > game_H - 150) { x2 = game_H - 150; }
			x2++;
		}

		X1 += dx;
		Y1 += dy;
		if ((Y1 + r1 <= y2 + 150) && (Y1 + r1 >= y2)  ) {

			if (X1 + r1 > game_W - 20)  {
				dx = -dx;
				FPS += 5;
			}
		}

		if ((Y1 + r1 <= y_1 + 150) && (Y1 + r1 >= y_1)) {


			if (X1 - r1 < 25) {
				dx = -dx;
				FPS += 5;
			}
		}

		if ((Y1 + r1 > game_H) || (Y1 - r1 < 0)) {
			dy = -dy;
		}

		if (X1 + r1 > game_W) {
			SSplayer1++;
			X1 = game_W / 2;
			Y1 = game_H / 2;
			dx = -dx;
			dy = -dy;
		}
		if (X1 - r1 < 0) {
			SSplayer2++;
			X1 = game_W / 2;
			Y1 = game_H / 2;
			dx = -dx;
			dy = -dy;
		}
	
		window.clear();
		window.draw(line);

		window.draw(player1);
		
			player1.setPosition(10, x1);

		window.draw(player2);

			player2.setPosition(game_W - 23, x2);

		window.draw(shape);

			shape.setRadius(r1);
			shape.setOrigin(r1, r1);
			shape.setPosition(X1, Y1);


			std::ostringstream playerCkor;
			playerCkor << SSplayer1;
			text.setFillColor(Color::White);
			text.setString(playerCkor.str());
			text.setPosition(500, 10);

		window.draw(text);
		
			std::ostringstream playerCkor_2;

			playerCkor_2 << SSplayer2;
			text.setFillColor(Color::White);
			text.setString(playerCkor_2.str());
			text.setPosition(game_W - 550, 10);

		window.draw(text);

		window.display();
	}
	return 0;
}