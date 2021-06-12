#include "init_game.hpp"

void read_line(std::ifstream& in, int i, std::string& line) {
	std::getline(in, line);
	for (int j = 0; j < M; j++)
		table[j][i] = obj_map[line[j]];
}

void read_table(std::ifstream& in) {
	std::string line;
	for (int i = 0; i < N; i++)
		read_line(in, i, line);
}

point read_map(std::ifstream& in) {
	read_table(in);
	
	int start_x, start_y;
	int orange_x, orange_y;
	in >> start_x >> start_y;
	table[start_x][start_y] = GameObjects::snake_obj;
	return point{start_x, start_y};
}