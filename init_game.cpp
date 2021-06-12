#include "init_game.hpp"

void clear_snake() {
	while (snake.size() > 0)
		snake.pop();
}

void read(std::string path) {

	std::ifstream in(path);
	point start_point = read_map(in);
	clear_snake();
	snake.push(start_point);
	int start_direction;
	in >> start_direction;
	direction = static_cast<Directions>(start_direction);
	last_direction = direction;
	in.close();
}

void init_game(std::string path) {
	counter = 0;
	read(path);
}