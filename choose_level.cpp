#include "main_menu.hpp"

bool was_choosed;
std::vector<std::string> paths_list;

void read_paths(std::string list_path) {
	std::string cur_path;
	std::ifstream list(list_path);
	int count; list >> count;
	while (count-- > 0) {
		list >> cur_path;
		paths_list.push_back(cur_path);
	}
	list.close();
}

void choose_level(std::string list_path) {
	read_paths(list_path);
	draw_levels();
	was_choosed = false;
	while(!was_choosed && window.isOpen())
		handle_choose();

}