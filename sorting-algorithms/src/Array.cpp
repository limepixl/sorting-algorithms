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
		sf::RectangleShape bar(sf::Vector2f((float)width / n, ((float)height / n) * array.at(i).value));
		bar.setFillColor(sf::Color(200, 200, 200, 255));
		bar.setOrigin(sf::Vector2f(0.0f, ((float)height / n) * array.at(i).value));
		bar.setPosition(sf::Vector2f(i + ((float)width / n - 1) * i, height));
		bar.value = array.at(i).value;
		
		arr.push_back(bar);
	}
}

void Array::GenerateArray() {
	for (int i = 1; i <= n; i++) {
		sf::RectangleShape bar(sf::Vector2f((float)width / n, ((float)height/n) * i));
		bar.setFillColor(sf::Color(200, 200, 200, 255));
		bar.setOrigin(sf::Vector2f(0.0f, ((float)height / n) * i));
		bar.setPosition(sf::Vector2f(i + ((float)width / n - 1) * i, height));
		bar.value = i;
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

void Array::Shuffle(Array& array) {
	std::vector<sf::RectangleShape> arrayOfRects = array.getArray();
	int size = arrayOfRects.size();

	for (int i = 0; i < size; i++) {
		int index = i + rand() % (size - i);
		std::iter_swap(arrayOfRects.begin() + i, arrayOfRects.begin() + index);
	}

	array = Array(width, height, arrayOfRects);
}

std::vector<class sf::RectangleShape> Array::getArray() {
	return this->arr;
}
