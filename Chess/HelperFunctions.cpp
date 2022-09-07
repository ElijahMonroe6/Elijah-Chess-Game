#include "HelperFunctions.h"

using namespace std;

namespace HelperFunctions {

	double magnitude(pair<int, int> vector) {

		return sqrt(pow(vector.first, 2) + pow(vector.second, 2));

	};

	int dot(pair<int, int> vector1, pair<int, int> vector2) {

		return (vector1.first * vector2.first) + (vector1.second * vector2.second);

	};

	pair<int, int> delta(pair<int, int> vector1, pair<int, int> vector2) {

		return make_pair(vector1.first - vector2.first, vector1.second - vector2.second);

	};

	pair<int, int> delta(pair<int, int> vector1, pair<int, int> vector2) {

		return make_pair(abs(vector1.first - vector2.first), abs(vector1.second - vector2.second));

	};

}