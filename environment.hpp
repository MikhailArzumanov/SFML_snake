#pragma once
#include "libs.hpp"
struct point {
	int x, y;
	point operator+=(point another);
};
enum GameObjects {
	empty, snake_obj,
	orange, wall, objs_amount
};
enum Directions {
	forward = 0,  right = 1,
	backward = 2, left = 3,
	directions_amount
};
extern const int N, M, ORANGE_SCORE;
extern sf::RenderWindow window;
extern sf::Clock the_clock;
extern int score;
extern int counter;
extern bool is_orange_eaten;
extern std::queue<point> snake;
extern GameObjects** table;
extern Directions direction, last_direction;
extern bool is_game_over;
extern sf::Font score_font;
extern sf::Text score_txt;