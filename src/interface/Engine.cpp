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

    this->size = this->video_mode.width/100;
    this->column = 100;
    this->row = 100;
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

    for(int i = this->row-2; i > 1; i--){
        for(int j = this->column-2; j > 1; j--){
            this->grid_vector[i][j].update();
            if(this->grid_vector[i][j].type == Cell().SAND || this->grid_vector[i][j].type == Cell().WATER){
                this->simulation.simulateParticle(this->grid_vector[i][j], this->grid_vector);
            }
        }
    }
    
}
void Engine::render(){
    this->window->clear(sf::Color::Black);
    
    for(int i = 0; i < this->grid_vector.size(); i++){
        for(int j = 0; j < this->grid_vector[i].size(); j++){
            this->grid_vector[j][i].render(this->window);
        }
    }

    this->window->draw(this->text);

    this->window->display();
}

//defining custom functions
void Engine::configureGridLayout(int column, int row){
    for(int i = 0; i < this->row; i++){
        std::vector<Cell> vec_in;
        for(int j = 0; j < this->column; j++){
            Cell cell = Cell(sf::Vector2f(this->size, this->size), sf::Vector2f(j * this->size, i * this->size));
            cell.column = j;
            cell.row = i;
            cell.type = Cell().EMPTY;
            vec_in.push_back(cell);
        }
        this->grid_vector.push_back(vec_in);
    }
}
void Engine::spawnParticle(sf::Vector2f mouse_position){
    int row_index = floor(mouse_position.y/this->size);
    int column_index = floor(mouse_position.x/this->size);

    if(row_index < 5 || row_index > 95)
        return;
    if(column_index < 5 || column_index > 95)
        return;

    //selecting multiple cells
    for(int i = row_index - 5; i < row_index + 5; i++){
        for(int j = column_index - 5; j < column_index + 5; j++){
            this->grid_vector[i][j].type = this->cell_type == 1 ?
            Cell().SAND : this->cell_type == 2 ?
            Cell().WATER : this->cell_type == 3 ?
            Cell().ROCK : Cell().EMPTY;
        }
    }
}
void Engine::setText(std::string particle_text){
    this->text.setFont(this->font);
    this->text.setString(particle_text);
    this->text.setCharacterSize(18);
    this->text.setFillColor(sf::Color::White);
    this->text.setPosition(sf::Vector2f(this->video_mode.width/1.2f, this->video_mode.height/1.1f));
}