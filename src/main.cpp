#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "RectangleShape.h"
#include "Utils.h"
#include "algorithms/BubbleSort.h"

// Macro to clear the terminal.
#define CLEAR() { std::cout << "\033[2J\033[1;1H"; };

int main() {
	int n, windowWidth, windowHeight, delay;
	bool sorted = false;

	// Ask the user for the window's desired dimensions
	std::cout << "Enter the dimensions of the window.\nWidth: ";
	std::cin >> windowWidth;
	std::cout << "Height: ";
	std::cin >> windowHeight;

    CLEAR();

	// Ask the user for the desired number of bars
	std::cout << "Enter the number of items that need to be sorted.\n";
	std::cin >> n;

	CLEAR();

	// Ask the user for the desired delay between comparisons
	std::cout << "Enter the desired delay between comparisons and draw calls, in milliseconds.\n";
	std::cin >> delay;

	CLEAR();

	// Create window
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Sorting");

	std::vector<RectangleShape> bars = Utils::genArray(n, &window);
	bars = Utils::shuffleArray(bars);

	// Render loop
	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
		}

        if(!sorted) {
            BubbleSort::runSort(bars, &window, delay);
            sorted = true;
        }

        window.display();
	}
	return 0;
}
