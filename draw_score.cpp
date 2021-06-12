#include "draw.hpp"

const float END_SCORE_X = 300;
const float END_SCORE_Y = 300;

void init_score() {
	score_font.loadFromFile("fonts/ar-destine.ttf");
	score_txt.setFont(score_font);
	score_txt.setFillColor(sf::Color::Black);
}

void set_score_text() {
	score_txt.setString(int_to_string(score));
	score_txt.setCharacterSize(100);
	score_txt.setPosition(END_SCORE_X, END_SCORE_Y);
}
void draw_end_score() {
	set_score_text();
	window.draw(score_txt);
	window.display();
}