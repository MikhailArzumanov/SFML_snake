#include "environment.hpp"

point point::operator+=(point another) {
	x += another.x;
	y += another.y;
	return *this;
}

const int N = 20, M = 20, ORANGE_SCORE = 50;
sf::RenderWindow window(sf::VideoMode(720, 720), "Snake.exe");
sf::Clock the_clock;
int score = 0;
int counter;
bool is_orange_eaten = true;
std::queue<point> snake;
GameObjects** table;
Directions direction, last_direction;
bool is_game_over;
sf::Font score_font;
sf::Text score_txt;