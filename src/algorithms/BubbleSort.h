#pragma once
#include <SFML/Graphics.hpp>

class BubbleSort {
private:
    BubbleSort() {};

public:
    // Run the bubble sort
    static void runSort(std::vector<class RectangleShape> arrayOfRects, sf::RenderWindow* window, int delay);
};
