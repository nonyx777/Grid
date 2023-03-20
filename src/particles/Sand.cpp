#include <SFML/Graphics.hpp>
#include "../../include/cell/Cell.hpp"


class Sand : public Cell{
	public:
		Sand(sf::Vector2f position, sf::Vector2f size){
			this->cell_property.setFillColor(sf::Color::Black);
			this->cell_property.setSize(size);
			this->cell_property.setPosition(position);
			this->size = size;
		}
	public:
		void update(float dt){
			//...
		}
		void render(sf::RenderTarget* target){
			target->draw(this->cell_property);
		}
};
