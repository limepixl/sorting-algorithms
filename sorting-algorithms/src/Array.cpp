#include "Array.h"

Array::Array(int windowWidth, int windowHeight, int numOfElements) {
	this->width = windowWidth;
	this->height = windowHeight;
	this->n = numOfElements;
}

Array::Array(int windowWidth, int windowHeight, std::vector<sf::RectangleShape> array) {
	this->n = array.size();
	this->width = windowWidth;
	this->height = windowHeight;

	for (int i = 0; i < n; i++) {
		
		sf::RectangleShape bar(sf::Vector2f((float)width / n, array.at(i).value));
		bar.setOrigin(sf::Vector2f(0.0f, array.at(i).value));
		bar.setPosition(sf::Vector2f(i + ((float)width / n - 1) * i, height));
		bar.value = array.at(i).value;
		
		arr.push_back(bar);
	}
}

void Array::GenerateArray() {
	for (int i = 0; i < n; i++) {
		int randNum = rand() % (height)+1;
		sf::RectangleShape bar(sf::Vector2f((float)width / n, randNum));
		bar.setOrigin(sf::Vector2f(0.0f, randNum));
		bar.setPosition(sf::Vector2f(i + ((float)width / n - 1) * i, height));
		bar.value = randNum;
		arr.push_back(bar);
	}
}

void Array::Draw(sf::RenderWindow* window) {
	window->clear(sf::Color(51, 51, 51, 255));
	// Draw here
	for (int i = 0; i < arr.size(); i++) {
		window->draw(arr.at(i));
	}

	window->display();
}

std::vector<class sf::RectangleShape> Array::getArray() {
	return this->arr;
}
