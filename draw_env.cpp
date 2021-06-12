#include "draw.hpp"

std::string int_to_string(int x) {
	std::ostringstream s;
	s << x;
	return s.str();
}

float min(float x, float y) {
	return x > y ? y : x;
}