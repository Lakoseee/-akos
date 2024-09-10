#include "game.h"
#include <ncurses.h>
#include <iostream>
#include <thread>      // Do odliczania
#include <chrono>      // Do opóźnienia

Game::Game(int width, int height) 
    : snake(width / 2, height / 2), food(width, height), score(0), gameOver(false), width(width), height(height) {
    initscr();          // Inicjalizuje ncurses
    cbreak();           // Wyłącza buforowanie linii
    noecho();           // Wyłącza echo klawiszy
    keypad(stdscr, TRUE); // Pozwala używać klawiszy specjalnych
    timeout(100);       // Ustawia czas oczekiwania na klawisz
    curs_set(0);        // Ukrywa kursor
}


Game::~Game() {
    endwin();           // Kończy pracę z ncurses
    std::cout << "Game Over! Your score: " << score << std::endl;
}

void Game::run() {
    displayCountdown();  // Dodajemy odliczanie przed rozpoczęciem gry

    while (!gameOver) {
        handleInput();
        update();
        render();
        refresh();  // Odśwież ekran
    }
}

void Game::handleInput() {
    int ch = getch();  // Pobiera wciśnięty klawisz

    switch (ch) {
        case KEY_UP:                    // Ruch
        case 'w':
            snake.setDirection(0, -1);
            break;
        case KEY_DOWN:
        case 's':
            snake.setDirection(0, 1);
            break;
        case KEY_LEFT:
        case 'a':
            snake.setDirection(-1, 0);  
            break;
        case KEY_RIGHT:
        case 'd':
            snake.setDirection(1, 0);  
            break;
        case 'q':
            gameOver = true;   // Zakończenie gry
            break;
        default:
            break;  // ignorowanie innych klawiszy
    }
}

void Game::update() {
    snake.move();  // Przesuń węża zgodnie z aktualnym kierunkiem

    // Sprawdzenie kolizji
    if (snake.checkCollision(width, height)) {
        gameOver = true;
    }

    // Sprawdzenie, czy wąż zjadł jedzenie
    if (snake.getBody()[0] == food.getPosition()) {
        snake.grow();
        food.generateNewPosition();
        score += 10;  // Dodajemy 10 punktów za każdy owoc
    }
}

void Game::render() const {
    clear();  // Czyści ekran

    // Rysowanie ścian (ramki)
    for (int x = 0; x < width; ++x) {
        mvprintw(0, x, "#");         // Górna ściana
        mvprintw(height - 1, x, "#"); // Dolna ściana
    }

    for (int y = 0; y < height; ++y) {
        mvprintw(y, 0, "#");          // Lewa ściana
        mvprintw(y, width - 1, "#");  // Prawa ściana
    }

    // Rysowanie węża
    for (const auto& segment : snake.getBody()) {
        mvprintw(segment.second, segment.first, "0");
    }

    // Rysowanie jedzenia
    mvprintw(food.getPosition().second, food.getPosition().first, "o");

    // Wyświetlanie wyniku
    mvprintw(height, 0, "Score: %d", score);

    // Wyświetlenie zmian
    refresh();
}

void Game::displayCountdown() const {
    for (int i = 3; i > 0; --i) {
        clear();
        mvprintw(height / 2, width / 2 - 5, "Starting in %d...", i);
        mvprintw((height + 4) / 2, width / 2 - 2, "Q to quit");
        refresh();
        std::this_thread::sleep_for(std::chrono::seconds(1));  // Odliczanie co sekundę
    }
    clear();
    refresh();
}
