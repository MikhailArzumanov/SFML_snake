#pragma once
#include "environment.hpp"
#include "init_game.hpp"
#include "draw.hpp"

extern std::string levels_path;
extern bool was_choosed;
extern std::vector<std::string> paths_list;

void handle_choose();

void draw_levels();
void choose_level(std::string list_path);