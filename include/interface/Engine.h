#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../cell/Cell.hpp"

using namespace std;

class Engine{
    private:
        //initializer functions
        void initVariables();
        void initWindow();

        //window variables
        sf::RenderWindow* window;
        sf::VideoMode video_mode;
        sf::Event event;

        //instantiating objects

        //mouse position
        sf::Vector2i mouse_position;
        sf::Vector2f mouse_position_view;

        //grid related variabless
        std::vector<Cell> cells;
        int column, row;

    public:
        //constructor and destructor
        Engine();
        ~Engine();

        //window functions
        void pollEvent();
        void update();
        void render();

        //custom functions
        void configureGridLayout(int column, int row);

        //Accessors
        const bool running() const;
};