#pragma once

#include <SFML/Graphics.hpp>
#include <chrono>

class Cell{
    protected:
        sf::RectangleShape cell_property;
    
    public:
        Cell();
        Cell(sf::Vector2f size, sf::Vector2f position);
        int column, row;
        sf::Color state;
    
    public:
        sf::Vector2f size;

    public:
        void update();
        void render(sf::RenderTarget* target);
};
