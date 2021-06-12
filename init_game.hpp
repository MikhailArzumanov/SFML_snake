#pragma once
#include "environment.hpp"
#define CHARS_AMOUNT 256

extern GameObjects obj_map[CHARS_AMOUNT];

point read_map(std::ifstream& in);

void init_obj_map();

void init_game(std::string path);
