#pragma once
#include <SFML/Graphics.hpp>

class InsertionSort {
private:
    InsertionSort() {};

public:
    // Run the insertion sort
    static void runSort(std::vector<class RectangleShape> arrayOfRects, sf::RenderWindow* window, int delay);
};
