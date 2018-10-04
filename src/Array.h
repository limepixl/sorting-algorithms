#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "RectangleShape.h"
class Array {
public:
	Array(int windowWidth, int windowHeight, int numOfElements);

	Array(int windowWidth, int windowHeight, std::vector<RectangleShape> array);

	void GenerateArray();

	void Draw(class sf::RenderWindow* window);

	void Shuffle(Array &array);

	std::vector<RectangleShape> getArray();

private:
	int width, height, n;

	std::vector<RectangleShape> arr;
};
