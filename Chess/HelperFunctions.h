#pragma once
#include <utility>

namespace HelperFunctions {
	double magnitude(std::pair<int, int> vector);//returns the magnitude of a vector
	int dot(std::pair<int, int> vector1, std::pair<int, int> vector2);//returns the dot product of two vectors
	std::pair<int, int> delta(std::pair<int, int> vector1, std::pair<int, int> vector2);//returns a pair containing the delta between two vectors, vector1 - vector2
	std::pair<int, int> distance(std::pair<int, int> vector1, std::pair<int, int> vector2);//returns a pair containing the distance between two vectors, abs(vector1 - vector2)
};