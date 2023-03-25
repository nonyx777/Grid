#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
// #include "../cell/Cell.hpp"
// #include "../../src/Particles/Sand.cpp"
// #include "../../src/Particles/Water.cpp"
#include "../particles/Particle.hpp"
#include "../ConwaysRuleOfLife/Crol.hpp"

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
        Crol crol;

        //mouse position
        sf::Vector2i mouse_position;
        sf::Vector2f mouse_position_view;

        //grid related variabless
        int row;
        int column;
        Cell grid_matrix[30][30];//hard coded, should change if row and column change

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