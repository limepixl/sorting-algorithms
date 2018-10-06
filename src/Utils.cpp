#include "Utils.h"
#include "RectangleShape.h"

std::vector<RectangleShape> Utils::genArray(int n, sf::RenderWindow* window) {
    // Store the window's dimensions
    sf::Vector2u windowSize = window->getSize();
    float width = windowSize.x;
    float height = windowSize.y;

    // Create a vector for all 'RectangleShape's to be stored in
    std::vector<RectangleShape> rects;

    // Generate n number of rectangles
    for(int i = 1; i < n; i++) {
        RectangleShape rect(sf::Vector2f(width / n, ((height/n) * i)));

        // Set their color, origin position (bottom left of rectangle)
        // and set their position according to the width and height of the window
        rect.setFillColor(sf::Color(200,200,200,255));
        rect.setOrigin(sf::Vector2f(0.0f, (height/n) * i);
        rect.setPosition(sf::Vector2f(i + ((width / n - 1) * i, height));

        // Set the value for each rectangle (this actually gets sorted).
        rect.value = i;

        // Store the rect in the temp vector
        rects.push_back(rect);
    }
}
