#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "../RectangleShape.h"
class BubbleSort {
private:
	BubbleSort() {};

public:
	static bool runSort(std::vector<RectangleShape> arr, sf::RenderWindow* window, int delay);
};
