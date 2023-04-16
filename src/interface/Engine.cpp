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
            case sf::Event::MouseButtonPressed:
                if(this->event.mouseButton.button == sf::Mouse::Left)
                    this->selectSource(this->mouse_position_view);
                else if(this->event.mouseButton.button == sf::Mouse::Right)
                    this->selectEnd(this->mouse_position_view);
        }
    }
}
void Engine::update(){
    this->pollEvent();
    this->mouse_position = sf::Mouse::getPosition(*this->window);
    this->mouse_position_view = this->window->mapPixelToCoords(this->mouse_position);

    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            this->grid_matrix[i][j].update();
        }
    }
}
void Engine::render(){
    this->window->clear(sf::Color::Black);
    
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            this->grid_matrix[i][j].render(this->window);
        }
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
            this->grid_matrix[i][j] = cell;
        }
    }
}
void Engine::selectSource(sf::Vector2f mouse_position){
    int row_index = floor(mouse_position.y/30.0);
    int column_index = floor(mouse_position.x/30.0);

    this->grid_matrix[row_index][column_index].cell_property.setFillColor(sf::Color::Green);
}
void Engine::selectEnd(sf::Vector2f mouse_position){
    int row_index = floor(mouse_position.y/30.0);
    int column_index = floor(mouse_position.x/30.0);

    this->grid_matrix[row_index][column_index].cell_property.setFillColor(sf::Color::Red);
}