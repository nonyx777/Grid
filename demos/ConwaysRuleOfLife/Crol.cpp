#include "../../include/ConwaysRuleOfLife/Crol.hpp"

Crol::Crol(){
    //...
}

//defining functions
void Crol::neighbourCheck(Cell &cell, std::vector<Cell> &cells){

    std::this_thread::sleep_for(std::chrono::microseconds(5));

    //check neighbouring cells' state
    int total = 0;
    for(Cell &cell_neighbour : cells){
        if(cell_neighbour.row == (cell.row - 1) || cell_neighbour.row == (cell.row + 1)){
            if(cell_neighbour.column == (cell.column - 1) || cell_neighbour.column == (cell.column) || cell_neighbour.column == (cell.column + 1)){
                total = cell_neighbour.state == sf::Color::White ? total + 1 : total + 0;
            }
        }

        if(cell_neighbour.row == cell.row){
            if(cell_neighbour.column == (cell.column - 1) || cell_neighbour.column == (cell.column + 1)){
                total = cell_neighbour.state == sf::Color::White ? total + 1 : total + 0;
            }
        }

        // std::cout << total << std::endl;
    }

    //changing state depending on the state of the neighbours
    if(total == 3)
        cell.state = sf::Color::White;
    else if(total < 2)
        cell.state = sf::Color::Transparent;
    else if(total > 3)
        cell.state = sf::Color::Transparent;
}