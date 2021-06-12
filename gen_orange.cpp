#include "game_dynamics.hpp"

void gen_orange() {
	int r_x, r_y;
	do {
		r_x = rand() % M;
		r_y = rand() % N;
	} while (table[r_x][r_y] != GameObjects::empty);
	table[r_x][r_y] = orange;
	is_orange_eaten = false;
}