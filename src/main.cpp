#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Array.h"
#include "algorithms/BubbleSort.h"
#include "RectangleShape.h"

int main() {
	int n, windowWidth, windowHeight;
	bool sorted = false;
	int milliseconds;

	// Ask the user for the window's desired dimensions
	std::cout << "Enter the dimensions of the window.\nWidth: ";
	std::cin >> windowWidth;
	std::cout << "Height: ";
	std::cin >> windowHeight;

	// Ask the user for the desired number of bars
	std::cout << "Enter the number of items that need to be sorted.\n";
	std::cin >> n;

	// Ask the user for the desired delay between comparisons
	std::cout << "Enter the desired delay between comparisons. (in milliseconds) :\n";
	std::cin >> milliseconds;

	// Create window
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Title");

	// Generate a random array of bars
	Array arr(windowWidth, windowHeight, n);
	arr.GenerateArray();
	arr.Shuffle(arr);

	// Render loop
	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (!sorted) {
			if (BubbleSort::runSort(arr.getArray(), &window, milliseconds)) {
				sorted = true;
				std::cout << "Finished sort!\n";
			}
		}
	}
	return 0;
}
