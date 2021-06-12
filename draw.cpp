#include "draw.hpp"
const float block_height = 720.f / N;
const float block_width = min(block_height, 1280.f / M);

sf::RectangleShape block(sf::Vector2f(block_width, block_height));
sf::Color color_map[GameObjects::objs_amount];

void init_color_map() {
	color_map[GameObjects::wall]		= sf::Color::Red;
	color_map[GameObjects::orange]		= sf::Color::Blue;
	color_map[GameObjects::snake_obj]	= sf::Color::Green;
	color_map[GameObjects::empty]		= sf::Color::White;
}
void draw_tile(int i, int j) {
	block.setPosition(i * block_width, j * block_height);
	GameObjects obj = table[i][j];
	sf::Color color = color_map[obj];
	block.setFillColor(color);
	window.draw(block);
}
void draw() {
	window.clear();
	for (int i = 0; i < N; i++) 
	for (int j = 0; j < M; j++)
		draw_tile(i, j);
	window.display();
}