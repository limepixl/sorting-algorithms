#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "RectangleShape.h"
#include "Utils.h"
#include "Algorithms.h"

// All sorting algorithms stored in an enum
enum SortType {
	BUBBLE_SORT,
	INSERTION_SORT
};

int main() {
	int n, windowWidth, windowHeight, delay, sortType;
	bool sorted = false;

	// Ask the user for the window's desired dimensions
	std::cout << "Enter the dimensions of the window.\nWidth: ";
	std::cin >> windowWidth;
	std::cout << "Height: ";
	std::cin >> windowHeight;

	// Ask the user for the desired number of bars
	std::cout << "Enter the number of items that need to be sorted.\n";
	std::cin >> n;

	// Ask the user for the desired delay between comparisons
	std::cout << "Enter the delay between comparisons and draw calls, in milliseconds.\n";
	std::cin >> delay;

	// Ask the user for which algorithm to use
	std::cout << "Enter the algorithm you would like to use.\n";
	std::cout << "(BubbleSort = 0 | InsertionSort = 1)\n";
	std::cin >> sortType;

	// Create window
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Sorting");

	std::vector<RectangleShape> bars = Utils::genArray(n, &window);
	Utils::shuffleArray(bars);

	// Render loop
	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (!sorted) {
			switch (sortType) {
			case BUBBLE_SORT:
				BubbleSort::runSort(bars, &window, delay);
				sorted = true;
				break;

			case INSERTION_SORT:
				InsertionSort::runSort(bars, &window, delay);
				sorted = true;
				break;

			default:
				std::cout << "Invalid value for sort algorithm type entered!\n";
				return 0;
			}
		}
		else {
			window.clear(sf::Color(51, 51, 51, 255));
			for (int i = 0; i < n; i++) {
				window.draw(bars[i]);
			}
			window.display();
		}
	}
	return 0;
}
