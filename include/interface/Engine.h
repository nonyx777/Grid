#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../cell/Cell.hpp"
#include <math.h>
#include "../simulation/Simulation.hpp"

using namespace std;

//particle names
const std::string empty_text = "EMPTY";
const std::string sand_text = "SAND";
const std::string water_text = "WATER";
const std::string rock_text = "ROCK";

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
        Simulation simulation;

        //mouse position
        sf::Vector2i mouse_position;
        sf::Vector2f mouse_position_view;

        //grid related variabless
        int size;
        int row;
        int column;
        Cell grid_matrix[100][100];//hard coded, should change if row and column change //default 30 30

        //cell type represented by an integer
        int cell_type;

        //text related variables(what kind of particle)
        sf::Font font;
        sf::Text text;

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
        void setText(std::string particle_text);

        //Accessors
        const bool running() const;
};