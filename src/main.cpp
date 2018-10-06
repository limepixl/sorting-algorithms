#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

// Custom RectangleShape class
#include "RectangleShape.h"

int main() {
	int n, windowWidth, windowHeight;

	// Ask the user for the window's desired dimensions
	std::cout << "Enter the dimensions of the window.\nWidth: ";
	std::cin >> windowWidth;
	std::cout << "Height: ";
	std::cin >> windowHeight;

	// Ask the user for the desired number of bars
	std::cout << "Enter the number of items that need to be sorted.\n";
	std::cin >> n;

	// Create window
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Title");

	// Render loop
	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
		}


	}
	return 0;
}
