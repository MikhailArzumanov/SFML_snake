#include "environment_functions.hpp"

void allocate_table() {
	table = new GameObjects * [N];
	for (int i = 0; i < N; i++)
		table[i] = new GameObjects[M];
}
void init_environment() {
	srand(time(0));
	allocate_table();

	init_color_map();
	init_score();
	init_obj_map();
	init_change_map();
}
void free_table() {
	for (int i = 0; i < N; i++)
		delete[] table[i];
	delete[] table;
}
void close_game() {
	free_table();
}