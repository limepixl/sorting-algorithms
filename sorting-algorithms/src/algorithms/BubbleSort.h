#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
class BubbleSort {
private:
	BubbleSort() {};

public:
	static bool runSort(std::vector<sf::RectangleShape> arr, sf::RenderWindow* window, int delay);
};