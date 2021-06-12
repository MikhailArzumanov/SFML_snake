#include "handlers.hpp"

Directions change_map[sf::Keyboard::KeyCount][Directions::directions_amount];

void init_change_map() {
	for (int key = 0; key < sf::Keyboard::KeyCount; key++) 
	for (int direction = 0; direction < Directions::directions_amount; direction++)
		change_map[key][direction] = static_cast<Directions>(direction);

	change_map[sf::Keyboard::Right][Directions::forward] = Directions::right;
	change_map[sf::Keyboard::Left][Directions::forward] = Directions::left;
	change_map[sf::Keyboard::Right][Directions::backward] = Directions::right;
	change_map[sf::Keyboard::Left][Directions::backward] = Directions::left;

	change_map[sf::Keyboard::Up][Directions::right] = Directions::backward;
	change_map[sf::Keyboard::Down][Directions::right] = Directions::forward;
	change_map[sf::Keyboard::Up][Directions::left] = Directions::backward;
	change_map[sf::Keyboard::Down][Directions::left] = Directions::forward;
}
void change_direction(sf::Event& e) {
	direction = change_map[e.key.code][last_direction];
}