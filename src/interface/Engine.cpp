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

    this->column = 60.f;
    this->row = 60.f;

    this->size = this->video_mode.width/this->column;

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
        }
    }
}
void Engine::update(){
    this->pollEvent();
    this->mouse_position = sf::Mouse::getPosition(*this->window);
    this->mouse_position_view = this->window->mapPixelToCoords(this->mouse_position);


    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->column; j++){
            this->crol.neighbourCheck(this->grid_matrix[i][j], this->grid_matrix);
        }
    }

    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->column; j++){
            this->grid_matrix[i][j].update();
        }
    }
}
void Engine::render(){
    this->window->clear(sf::Color::Black);
    
    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->column; j++){
            this->grid_matrix[i][j].render(this->window);
        }
    }
    this->window->display();
}

//defining custom functions
void Engine::configureGridLayout(int column, int row){
    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->column; j++){
            Cell cell = Cell(sf::Vector2f(10.f, 10.f), sf::Vector2f(j * this->size, i * this->size));
            cell.column = j;
            cell.row = i;
            this->grid_matrix[i][j] = cell;
        }
    }
}