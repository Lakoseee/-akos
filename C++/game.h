#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "food.h"

class Game {
public:
    Game(int width, int height);
    ~Game();  // Destruktor
    void run();

private:
    Snake snake;
    Food food;
    int width, height;
    int score;           // Zmienna do przechowywania wyniku
    bool gameOver;

    void render() const;
    void update();
    void handleInput();
    void displayScore() const;      // Funkcja wyświetlająca wynik
    void displayCountdown() const;  // Funkcja wyświetlająca odliczanie
};

#endif
