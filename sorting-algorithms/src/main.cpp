#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Array.h"
#include "algorithms/BubbleSort.h"

int main() {
	int n, windowWidth, windowHeight;
	bool sorted = false;
	
	// Ask the user for the window's desired dimensions
	std::cout << "Enter the dimensions of the window.\nWidth: ";
	std::cin >> windowWidth;
	std::cout << "Height: ";
	std::cin >> windowHeight;

	// Ask the user for the desired number of bars
	std::cout << "Enter the number of items that need to be sorted.\n(For the most aesthetically pleasing effect use the same number as the height of the window.)\n";
	std::cin >> n;
	// TODO : Currently, the bars' height is determined also by the number of bars. Fix this behaviour.

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
			if (BubbleSort::runSort(arr.getArray(), &window)) {
				sorted = true;
				std::cout << "Finished sort!\n";
			}
		}
	}
	return 0;
}