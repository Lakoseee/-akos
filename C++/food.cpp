#include "food.h"
#include <cstdlib>

Food::Food(int width, int height) : width(width), height(height) {
    generateNewPosition();
}

void Food::generateNewPosition() {
    // Losuj pozycję jedzenia, unikając ścian
    int x = std::rand() % (width - 2) + 1;   // Generuje x w zakresie od 1 do width-2
    int y = std::rand() % (height - 2) + 1;  // Generuje y w zakresie od 1 do height-2
    position = {x, y};
}

std::pair<int, int> Food::getPosition() const {
    return position;
}
