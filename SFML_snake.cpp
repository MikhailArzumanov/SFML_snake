//#pragma comment(lib, "libname.lib")
#include "draw.hpp"
#include "handlers.hpp"
#include "init_game.hpp"
#include "environment.hpp"
#include "game_dynamics.hpp"
#include "environment_functions.hpp"
#include "main_menu.hpp"

void cycle(sf::Clock clock);
int main(){
	init_environment();
	do {
		choose_level("levels.txt");
		while(!is_game_over && window.isOpen())
			cycle(the_clock);
	} while (window.isOpen());
	close_game();
}
void tick() {	
	counter++;
	event_handler();
	if (counter > 180) {
		last_direction = direction;
		counter = 0;
		move();
	}
	if (is_orange_eaten)
		gen_orange();
	draw();
}
void cycle(sf::Clock clock) {
	float time = clock.getElapsedTime().asMilliseconds();
	if (60.0f * time > 1000.0f) {
		clock.restart();
		tick();
	}
}