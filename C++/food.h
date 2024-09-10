#ifndef FOOD_H
#define FOOD_H

#include <utility>

class Food {
public:
    Food(int width, int height);
    void generateNewPosition();
    std::pair<int, int> getPosition() const;

private:
    std::pair<int, int> position;
    int width, height;
};

#endif
