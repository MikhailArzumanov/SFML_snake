#include "game_dynamics.hpp"
void check_next_tile(point p) {
	switch (table[p.x][p.y]) {
	case GameObjects::snake_obj: case GameObjects::wall:
		game_over();
	CASE GameObjects::orange:
		score += ORANGE_SCORE;
		is_orange_eaten = true;
	}
}
void move_head(point& head, Directions direction) {
	head += shifts[direction];
	check_next_tile(head);
	table[head.x][head.y] = GameObjects::snake_obj;
	snake.push(head);
}
void remove_tail(point p) {
	if (!is_orange_eaten) {
		table[p.x][p.y] = GameObjects::empty;
		snake.pop();
	}
}
void move() {
	point head = snake.back(),  tail = snake.front();
	move_head(head, direction);
	remove_tail(tail);
}