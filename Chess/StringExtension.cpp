#include "StringExtension.h"

using namespace std;

namespace stringExtension {

	list<string> split(string input, char delimiter) {

		list<string> output;
		string current = "";

		for (int i = 0; i < input.size(); i++) {

			if (input[i] == delimiter) {

				output.push_back(current);
				current = "";

			}
			else {

				current += input[i];

			}

		}

		output.push_back(current);
		return output;

	};

}