#include "main_menu.hpp"

void draw_levels() {
	std::string line;
	int level_counter = 0;
	sf::RectangleShape rect(sf::Vector2f(4, 4));
	window.clear();
	for(std::string cur_path : paths_list){
		int level_X_delay = 10 + (level_counter % 7) * 100, level_Y_delay = 10 + (level_counter / 7) * 100;
		std::ifstream level(cur_path);
		for (int i = 0; i < N; i++) {
			level >> line;
			for (int j = 0; j < N; j++) {
				rect.setFillColor(color_map[obj_map[line[j]]]);
				rect.setPosition(level_X_delay + j * 4, level_Y_delay + i * 4);
				window.draw(rect);
			}
		}
		level.close();
		level_counter++;
	}
	window.display();
}