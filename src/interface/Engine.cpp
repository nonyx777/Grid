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

    this->column = this->video_mode.width/30.f;
    this->row = this->video_mode.height/30.f;
    //calling grid layout function
    this->configureGridLayout(this->column + 10, this->row + 10);
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

    for(Cell &cell : this->cells)
        this->crol.neighbourCheck(cell, this->cells);

    for(Cell &cell : this->cells)
        cell.update();
}
void Engine::render(){
    this->window->clear(sf::Color::Black);
    for(Cell &cell : this->cells){
        cell.render(this->window);
    }
    this->window->display();
}

//defining custom functions
void Engine::configureGridLayout(int column, int row){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            Cell cell = Cell(sf::Vector2f(30.f, 30.f), sf::Vector2f(j * column, i * row));
            cell.column = j;
            cell.row = i;
            this->cells.push_back(cell);
        }
    }
}