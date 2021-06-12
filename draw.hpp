#pragma once
#include "environment.hpp"

extern sf::Color color_map[GameObjects::objs_amount];

std::string int_to_string(int x);
float min(float x, float y);

void init_score();
void draw_end_score();

void init_color_map();
void draw();