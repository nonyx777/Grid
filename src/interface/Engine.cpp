#include "../../include/interface/Engine.h"

//defining initializer functions
void Engine::initVariables(){
    this->window = nullptr;

    //loading the font
    try{
        this->font.loadFromFile("../fonts/dejavu-sans/ttf/DejaVuSans.ttf");
    }catch(...){
        std::cout << "Couldn't load the font" << std::endl;
    }
}
void Engine::initWindow(){
    this->video_mode.width = 600;
    this->video_mode.height = 600;
    this->window = new sf::RenderWindow(this->video_mode, "Grid", sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close);
    this->window->setFramerateLimit(60);

    this->size = this->video_mode.width/60;
    this->column = 60;
    this->row = 60;
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
            case sf::Event::MouseWheelScrolled:
                if(this->event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel){
                    if(this->event.mouseWheelScroll.delta > 0)
                        if(this->cell_type < 3)
                            this->cell_type++;
                        else
                            this->cell_type = 0;
                    else if(this->event.mouseWheelScroll.delta < 0)
                        if(this->cell_type > 0)
                            this->cell_type--;
                        else
                            this->cell_type = 3;
                }
                break;
        }
    }
}
void Engine::update(){
    this->pollEvent();
    this->mouse_position = sf::Mouse::getPosition(*this->window);
    this->mouse_position_view = this->window->mapPixelToCoords(this->mouse_position);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        this->spawnParticle(this->mouse_position_view);

    //assigning the text to display
    std::string text_ = this->cell_type == 1 ? 
    sand_text : this->cell_type == 2 ? 
    water_text : this->cell_type == 3 ? 
    rock_text : empty_text;

    this->setText(text_);

    //...
    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->column; j++){
            this->grid_matrix[i][j].update();
        }
    }

    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->column; j++){
            this->simulation.simulateParticle(this->grid_matrix[i][j], this->grid_matrix);
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

    this->window->draw(this->text);

    this->window->display();
}

//defining custom functions
void Engine::configureGridLayout(int column, int row){
    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->column; j++){
            Cell cell = Cell(sf::Vector2f(this->size, this->size), sf::Vector2f(j * this->size, i * this->size));
            cell.column = j;
            cell.row = i;
            cell.type = Cell().EMPTY;
            this->grid_matrix[i][j] = cell;
        }
    }
}
void Engine::spawnParticle(sf::Vector2f mouse_position){
    int row_index = floor(mouse_position.y/10.0);
    int column_index = floor(mouse_position.x/10.0);

    this->grid_matrix[row_index][column_index].type = this->cell_type == 1 ? 
    Cell().SAND : this->cell_type == 2 ? 
    Cell().WATER : this->cell_type == 3 ? 
    Cell().ROCK : Cell().EMPTY;
}
void Engine::setText(std::string particle_text){
    this->text.setFont(this->font);
    this->text.setString(particle_text);
    this->text.setCharacterSize(18);
    this->text.setFillColor(sf::Color::White);
    this->text.setPosition(sf::Vector2f(this->video_mode.width/1.2f, this->video_mode.height/1.1f));
}