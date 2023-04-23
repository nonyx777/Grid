#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>

const sf::Color sand_color = sf::Color(183, 119, 41, 255);
const sf::Color water_color = sf::Color(5, 195, 221, 255);
const sf::Color rock_color = sf::Color(219, 226, 233, 255);
const sf::Color empty_color = sf::Color::Transparent;


class Cell{
    public:
        sf::RectangleShape cell_property;
    
    public:
        enum Type{
            EMPTY,
            SAND,
            WATER,
            ROCK
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
    
    public:
        void setColor();
};
