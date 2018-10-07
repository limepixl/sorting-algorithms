#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

// Utility class
class Utils {
private:
    Utils() {};
public:
    // Generate an already sorted array of RectangleShapes
    static std::vector<class RectangleShape> genArray(int numOfElements, sf::RenderWindow* window);

    // Shuffle an existing array of RectangleShapes
    static std::vector<class RectangleShape> shuffleArray(std::vector<class RectangleShape> arr);
};
