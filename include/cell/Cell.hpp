#include <SFML/Graphics.hpp>

class Cell{
    private:
        sf::RectangleShape cell_property;
    
    public:
        Cell();
        Cell(sf::Vector2f size, sf::Vector2f position);
    
    public:
        sf::Vector2f size;

    public:
        void render(sf::RenderTarget* target);
};