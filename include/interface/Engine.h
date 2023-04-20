#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../cell/Cell.hpp"
#include <math.h>

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
        int size;
        int row;
        int column;
        Cell grid_matrix[60][60];//hard coded, should change if row and column change //default 30 30

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
        void spawnParticle(sf::Vector2f mouse_position);

        //Accessors
        const bool running() const;
};