#include "../../include/interface/Engine.h"

//defining initializer functions
void Engine::initVariables(){
    this->window = nullptr;
}
void Engine::initWindow(){
    this->video_mode.width = 600;
    this->video_mode.height = 600;
    this->window = new sf::RenderWindow(this->video_mode, "Grid", sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close);
    this->window->setFramerateLimit(60);

    this->column = this->video_mode.width/60.f;
    this->row = this->video_mode.height/60.f;
    //calling grid layout function
    this->configureGridLayout(this->column, this->row);
}

//defining constructor and destructor
Engine::Engine(){
    this->initVariables();
    this->initWindow();
}
Engine::~Engine(){
    delete this->window;
}

//defining accessors
const bool Engine::running() const{
    return this->window->isOpen();
}

//defining window functions
void Engine::pollEvent(){
    while(this->window->pollEvent(this->event)){
        switch(this->event.type){
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::MouseButtonPressed:
                if(this->event.mouseButton.button == sf::Mouse::Left)
                    this->spawnParticle(this->mouse_position_view);
        }
    }
}
void Engine::update(){
    this->pollEvent();
    this->mouse_position = sf::Mouse::getPosition(*this->window);
    this->mouse_position_view = this->window->mapPixelToCoords(this->mouse_position);

    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->column; j++){
            this->grid_matrix[i][j].update();
        }
    }
}
void Engine::render(){
    this->window->clear(sf::Color::Black);
    
    for(int i = 0; i < 60; i++){
        for(int j = 0; j < 60; j++){
            this->grid_matrix[i][j].render(this->window);
        }
    }
    this->window->display();
}

//defining custom functions
void Engine::configureGridLayout(int column, int row){
    for(int i = 0; i < 60; i++){
        for(int j = 0; j < 60; j++){
            Cell cell = Cell(sf::Vector2f(10.f, 10.f), sf::Vector2f(j * column, i * row));
            cell.column = j;
            cell.row = i;
            this->grid_matrix[i][j] = cell;
        }
    }
}
void Engine::spawnParticle(sf::Vector2f mouse_position){
    int row_index = floor(mouse_position.y/10.0);
    int column_index = floor(mouse_position.x/10.0);

    this->grid_matrix[row_index][column_index].cell_property.setFillColor(sf::Color(100, 50, 90, 255));
}