//#pragma comment(lib, "libname.lib")

#include <iostream>
#include <queue>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <fstream>
#include <sstream>



using namespace std;

////////////////////////////////////////////////////////////////

struct point {
	int x, y;
};

enum GameObjects {
	empty,
	snake_obj,
	orange,
	wall
};

enum Directions {
	forward = 0,
	right = 1,
	backward = 2,
	left = 3
};


void clear_snake();
void create_table();


const int N = 20, M = 20, ORANGE_SCORE = 50;
sf::RenderWindow window(sf::VideoMode(1280, 720), "Snake.exe");
int score = 0;
int counter;
bool is_orange_eaten = true;
std::queue<point> snake;
GameObjects** table;
Directions direction;

sf::Font score_font;
sf::Text score_txt;

void clear_snake() {
	while (snake.size() > 0)
		snake.pop();
}

void create_table() {
	table = new GameObjects * [N];
	for (int i = 0; i < N; i++)
		table[i] = new GameObjects[M];
}

////////////////////////////////////////////////////////////////



point shifts[4] = {
	point{0,1},
	point{1,0},
	point{0,-1},
	point{-1,0}
};

void remove_tail(point p);
void move_head(point& head, Directions direction);
void check_next_tile(point p);
void gen_orange();
void move();
void change_direction(sf::Event e);
void draw();
void cycle(sf::Clock clock);
void init_game(string path);
void game_over();


int main(){
	score_font.loadFromFile("fonts/ar-destine.ttf");
	score_txt.setFont(score_font);
	score_txt.setCharacterSize(45);
	score_txt.setFillColor(sf::Color::Black);

	sf::Clock clock;
	counter = 0;
	srand(time(0));
	create_table();
	init_game("maps/stdmap");
	while(window.isOpen())
		cycle(clock);
}

void game_over() {
	draw();
	std::ostringstream s;
	s << score;
	score_txt.setString(s.str());
	score_txt.setPosition(300, 300);
	window.draw(score_txt);
	window.display();
	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			switch (e.type) {
			case sf::Event::KeyPressed:
				exit(0);
				break;
			}
		}
	}
}

void init_game(string path) {GameObjects obj_map[256];
	obj_map['W'] = GameObjects::wall;
	obj_map['E'] = GameObjects::empty;
	ifstream in(path);
	string line;
	for (int i = 0; i < N; i++) {
		getline(in, line);
		for (int j = 0; j < M; j++)
			table[i][j] = obj_map[line[j]];
	}
	int start_x, start_y;
	in >> start_x >> start_y;
	table[start_x][start_y] = GameObjects::snake_obj;
	point start_point = point{start_x, start_y};
	clear_snake();
	snake.push(start_point);
	int start_direction;
	in >> start_direction;
	direction = static_cast<Directions>(start_direction);
	in.close();
}
void cycle(sf::Clock clock) {
	float time = clock.getElapsedTime().asMilliseconds();
	if (time > 1000.0f / 60.0f) {
		clock.restart();
		counter++;
		sf::Event e;
		while (window.pollEvent(e)) {
			switch (e.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				change_direction(e);
				break;
			default:
				break;
			}
		}

		if (counter > 180) {
			counter = 0;
			move();
		}
		if (is_orange_eaten)
			gen_orange();
		draw();
	}
}
void draw() {
	float block_height = 720.0f / N;
	float block_width = min(block_height, 1280.0f / M);
	sf::RectangleShape block(sf::Vector2f(block_width, block_height));
	window.clear();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			block.setPosition(i * block_width, j * block_height);
			switch (table[i][j]) {
			case GameObjects::wall:
				block.setFillColor(sf::Color::Red);
				break;
			case GameObjects::orange:
				block.setFillColor(sf::Color::Blue);
				break;
			case GameObjects::snake_obj:
				block.setFillColor(sf::Color::Green);
				break;
			case GameObjects::empty:
				block.setFillColor(sf::Color::White);
				break;
			default:
				block.setFillColor(sf::Color::Black);
			}
			window.draw(block);
		}
	window.display();


}
void change_direction(sf::Event e) {
	switch (e.key.code) {
	case sf::Keyboard::Right:
		if (direction != Directions::left)
			direction = Directions::right;
		break;
	case sf::Keyboard::Down:
		if (direction != Directions::backward)
			direction = Directions::forward;
		break;
	case sf::Keyboard::Left:
		if (direction != Directions::right)
			direction = Directions::left;
		break;
	case sf::Keyboard::Up:
		if (direction != Directions::forward)
			direction  = Directions::backward;
		break;
	}
}
void move() {
	point head = snake.back(), tail = snake.front();
	move_head(head, direction);
	remove_tail(tail);
}
void gen_orange() {
	int r_x, r_y;
	do {
		r_x = rand() % M;
		r_y = rand() % N;
	} while (table[r_x][r_y] != GameObjects::empty);
	table[r_x][r_y] = orange;
	is_orange_eaten = false;
}
void check_next_tile(point p) {
	switch (table[p.x][p.y]) {
	case GameObjects::snake_obj:
	case GameObjects::wall:
		game_over();
		break;
	case GameObjects::orange:
		score += ORANGE_SCORE;
		is_orange_eaten = true;
	}
}
void move_head(point& head, Directions direction) {
	point shift = shifts[direction];
	head.x += shift.x;
	head.y += shift.y;
	check_next_tile(head);
	table[head.x][head.y] = GameObjects::snake_obj;
	snake.push(head);
}
void remove_tail(point p) {
	if (!is_orange_eaten) {
		int x = p.x, y = p.y;
		table[x][y] = GameObjects::empty;
		snake.pop();
	}
	//else is_orange_eaten = false;
}