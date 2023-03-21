#include "../../include/cell/Cell.hpp"

//defining constructors
Cell::Cell(){
    //...
}
Cell::Cell(sf::Vector2f size, sf::Vector2f position){
    // auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    // srand(seed);
    int random_number = rand() % 2;
    sf::Color cell_color = random_number == 1 ? sf::Color::White : sf::Color::Transparent;

    this->size = size;

    //forming the shape and related properties
    this->cell_property.setFillColor(cell_color);
    // this->cell_property.setOutlineColor(sf::Color::White);
    // this->cell_property.setOutlineThickness(0.5f);
    this->cell_property.setSize(this->size);
    this->cell_property.setPosition(position);

    //setting up state
    this->state = this->cell_property.getFillColor();
}

//defining functions
void Cell::update(){
    this->cell_property.setFillColor(this->state);
}
void Cell::render(sf::RenderTarget* target){
    target->draw(this->cell_property);
}