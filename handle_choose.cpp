#include "main_menu.hpp"

void proccess_click(sf::Event& e) {
	int x = e.mouseButton.x, y = e.mouseButton.y;
	x -= 10; y -= 10;
	if ((x % 100 <= 80) && (y % 100 <= 80)) {
		int X = x / 100, Y = y/100;
		int i = X + Y * 8;
		if (i < paths_list.size()) {
			init_game(paths_list[i]);
			was_choosed = true;
			is_game_over = false;
			is_orange_eaten = true;
			paths_list.clear();
			score = 0;
		}
	}
}
void proccess_choose(sf::Event& e) {
	switch (e.type) {
	case sf::Event::Closed:
		window.close();
	case sf::Event::MouseButtonPressed:
		proccess_click(e);
	}
}
void handle_choose() {
	sf::Event e;
	while (window.pollEvent(e))
		proccess_choose(e);
}