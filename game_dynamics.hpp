#pragma once
#include "environment.hpp"
#include "draw.hpp"
#define CASE break; case

extern point shifts[directions_amount];

void check_next_tile(point p);
void remove_tail(point p);
void move_head(point& head, Directions direction);
void move();

void gen_orange();

void game_over();

