#include "handlers.hpp"
#define CASE break; case


void process_event(sf::Event& e) {
	switch (e.type) {
	case sf::Event::Closed:
		window.close();
	CASE sf::Event::KeyPressed:
		change_direction(e);
	}
}

void event_handler() {
	sf::Event e;
	while (window.pollEvent(e))
		process_event(e);
}