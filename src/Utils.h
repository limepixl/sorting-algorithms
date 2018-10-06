#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Utils {
private:
    Utils() {};
public:
    // Generate an already sorted array of 'RectangleShape's
    static std::vector<class RectangleShape> genArray(int numOfElements, sf::RenderWindow* window);
};
