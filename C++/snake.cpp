#include "snake.h"
#include <cstddef> // Dodane dla size_t

Snake::Snake(int startX, int startY) : direction(1, 0) { // Początkowy ruch w prawo
    body.push_back({startX, startY});
}

void Snake::setDirection(int dx, int dy) {
    // Nie pozwól na cofanie się w przeciwnym kierunku
    if (dx != -direction.first || dy != -direction.second) {
        direction = {dx, dy};
    }
}

void Snake::move() {
    std::pair<int, int> newHead = {body.front().first + direction.first, body.front().second + direction.second};
    body.insert(body.begin(), newHead);  // Dodaj nową głowę
    body.pop_back();  // Usuwamy ogon
}

void Snake::grow() {
    body.push_back(body.back());  // Dodaj nowy segment węża
}

std::vector<std::pair<int, int>> Snake::getBody() const {
    return body;
}

bool Snake::checkCollision(int width, int height) const {
    auto head = body.front();
    
    // Kolizja ze ścianami (pamiętaj, że ściany są na pozycjach 0 i width-1 oraz 0 i height-1)
    if (head.first <= 0 || head.first >= width - 1 || head.second <= 0 || head.second >= height - 1) {
        return true;
    }
    
    // Kolizja z własnym ciałem
    for (size_t i = 1; i < body.size(); ++i) {
        if (body[i] == head) {
            return true;
        }
    }
    return false;
}
