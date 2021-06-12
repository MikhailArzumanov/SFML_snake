#include "game_dynamics.hpp"

void game_over() {
	draw();
	draw_end_score();
	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e))
			switch (e.type) {
			case sf::Event::KeyPressed:
				is_game_over = true;
				goto END;
			}
	}
END:
	std::cout << "...\n";
}