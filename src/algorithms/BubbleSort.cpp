#include "BubbleSort.h"
#include <algorithm>
#include <thread>
#include <chrono>

bool BubbleSort::runSort(std::vector<RectangleShape> arr, sf::RenderWindow* window, int delay) {
	int n = arr.size();

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr.at(j).value > arr.at(j + 1).value) {
				sf::Vector2f firstPos = arr.at(j).getPosition();
				sf::Vector2f secondPos = arr.at(j+1).getPosition();

				std::iter_swap(arr.begin() + j, arr.begin() + j + 1);

				arr.at(j).setPosition(firstPos);
				arr.at(j+1).setPosition(secondPos);

				arr.at(j+1).setFillColor(sf::Color(255, 0, 0, 255));

				window->clear(sf::Color(51, 51, 51, 255));
				for (int k = 0; k < arr.size(); k++) {
					window->draw(arr.at(k));
				}
				window->display();

				arr.at(j + 1).setFillColor(sf::Color(200, 200, 200, 255));

				std::this_thread::sleep_for(std::chrono::milliseconds(delay));
			}
		}
	}

	window->clear(sf::Color(51, 51, 51, 255));
	for (int i = 0; i < n; i++) {
		arr.at(i).setFillColor(sf::Color(200, 200, 200, 255));
		window->draw(arr.at(i));
	}
	window->display();

	return true;
}

