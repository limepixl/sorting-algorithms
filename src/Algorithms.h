#pragma once
#include <vector> 
#include "RectangleShape.h"
#include <chrono>
#include <thread>

namespace BubbleSort {
	void runSort(std::vector<RectangleShape>& arr, sf::RenderWindow* window, int delay) {
		int n = arr.size();
		for(int i = 0; i < n - 1; i++) {
			for(int j = 0; j < n - 1 - i; j++) {
				if(arr[j].value > arr[j + 1].value) {
					sf::Vector2f firstPos = arr[j].getPosition();
					sf::Vector2f secondPos = arr[j + 1].getPosition();

					std::iter_swap(arr.begin() + j, arr.begin() + j + 1);

					arr[j].setPosition(firstPos);
					arr[j + 1].setPosition(secondPos);

					arr[j + 1].setFillColor(sf::Color(255, 0, 0, 255));

					window->clear(sf::Color(51, 51, 51, 255));

					for(unsigned int k = 0; k < arr.size(); k++) {
						window->draw(arr[k]);
					}

					window->display();

					arr[j + 1].setFillColor(sf::Color(200, 200, 200, 255));

					std::this_thread::sleep_for(std::chrono::milliseconds(delay));
				}
			}
		}

		// Clear unwanted red colored rectangles after the sorting is finished
		window->clear(sf::Color(51, 51, 51, 255));
		for(int i = 0; i < n; i++) {
			arr[i].setFillColor(sf::Color(200, 200, 200, 255));
			window->draw(arr[i]);
		}
		window->display();
	}
}

namespace InsertionSort {
	void runSort(std::vector<RectangleShape>& arr, sf::RenderWindow* window, int delay) {
		int n = arr.size();
		for(int i = 0; i < n; i++) {
			for(int j = i; j > 0; j--) {
				if(arr[j - 1].value > arr[j].value) {
					sf::Vector2f firstPos = arr[j - 1].getPosition();
					sf::Vector2f secondPos = arr[j].getPosition();

					std::iter_swap(arr.begin() + j, arr.begin() + j - 1);

					arr[j - 1].setPosition(firstPos);
					arr[j].setPosition(secondPos);

					arr[j - 1].setFillColor(sf::Color(255, 0, 0, 255));

					window->clear(sf::Color(51, 51, 51, 255));
					for(unsigned int k = 0; k < arr.size(); k++) {
						window->draw(arr[k]);
					}
					window->display();

					arr[j - 1].setFillColor(sf::Color(200, 200, 200, 255));

					std::this_thread::sleep_for(std::chrono::milliseconds(delay));
				}
			}
		}

		// Clear unwanted red colored rectangles after the sorting is finished
		window->clear(sf::Color(51, 51, 51, 255));
		for(int i = 0; i < n; i++) {
			arr[i].setFillColor(sf::Color(200, 200, 200, 255));
			window->draw(arr[i]);
		}
		window->display();
	}
}