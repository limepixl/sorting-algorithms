#include "Utils.h"
#include "RectangleShape.h"

std::vector<RectangleShape> Utils::genArray(int n, sf::RenderWindow* window) {
    // Store the window's dimensions
    sf::Vector2u windowSize = window->getSize();
    float width = windowSize.x;
    float height = windowSize.y;

    // Create a vector for all RectangleShapes to be stored in
    std::vector<RectangleShape> rects;

    // Generate n number of rectangles
    for(int i = 1; i <= n; i++) {
        RectangleShape rect(sf::Vector2f(width / n, ((height/n) * i)));

        // Set their color, origin position (bottom left of rectangle)
        // and set their position according to the width and height of the window
        rect.setFillColor(sf::Color(200,200,200,255));
        rect.setOrigin(sf::Vector2f(0.0f, (height/n) * i));
        rect.setPosition(sf::Vector2f(i + ((width / n) - 1) * (i-1), height));

        // Set the value for each rectangle (this actually gets sorted).
        rect.value = i;

        // Store the rect in the temp vector
        rects.push_back(rect);
    }

    return rects;
}

std::vector<RectangleShape> Utils::shuffleArray(std::vector<RectangleShape> arr) {
    // Size of the array
    int sz = arr.size();

    for(int i = 0; i < sz; i++) {
        int index = i + rand() % (sz - i);

        sf::Vector2f firstPos = arr.at(i).getPosition();
        sf::Vector2f secondPos = arr.at(index).getPosition();

        std::iter_swap(arr.begin() + i, arr.begin() + index);

        arr.at(i).setPosition(firstPos);
        arr.at(index).setPosition(secondPos);
    }

    return arr;
}
