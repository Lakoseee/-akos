#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <utility>

class Snake {
public:
    Snake(int startX, int startY);
    void move();
    void grow();
    bool checkCollision(int width, int height) const;
    std::vector<std::pair<int, int>> getBody() const;
    void setDirection(int dx, int dy);

private:
    std::vector<std::pair<int, int>> body;
    std::pair<int, int> direction;  // Przechowuje aktualny kierunek ruchu
};

#endif
