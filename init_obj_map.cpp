#include "init_game.hpp"

GameObjects obj_map[CHARS_AMOUNT];

void init_obj_map() {
	obj_map['W'] = GameObjects::wall;
	obj_map['E'] = GameObjects::empty;
}