#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>

class Cell{
    public:
        sf::RectangleShape cell_property;
    
    public:
        enum Type{
            SAND,
            WATER
        };

    public:
        Cell();
        Cell(sf::Vector2f size, sf::Vector2f position);
        int column, row;
        sf::Color state;
        Type type;
    
    public:
        sf::Vector2f size;


    public:
        void update();
        void render(sf::RenderTarget* target);
};
