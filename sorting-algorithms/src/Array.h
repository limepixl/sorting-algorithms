#pragma once

// Forward declare...
#include <SFML/Graphics.hpp>
#include <vector>
class Array {
public:
	Array(int windowWidth, int windowHeight, int numOfElements);

	Array(int windowWidth, int windowHeight, std::vector<sf::RectangleShape> array);

	void GenerateArray();

	void Draw(class sf::RenderWindow* window);

	void Shuffle(Array &array);

	std::vector<sf::RectangleShape> getArray();

private:
	int width, height, n;

	std::vector<sf::RectangleShape> arr;
};