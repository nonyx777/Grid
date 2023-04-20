#include "../../include/ConwaysRuleOfLife/Crol.hpp"

Crol::Crol(){
    //...
}

//defining functions
void Crol::neighbourCheck(Cell &cell, Cell (&grid_matrix)[60][60]){

    std::this_thread::sleep_for(std::chrono::nanoseconds(1));

    //check neighbouring cells' state
    int total = 0;

    total = grid_matrix[cell.row-1][cell.column-1].state == sf::Color::White ? total + 1 : total + 0; 
    total = grid_matrix[cell.row-1][cell.column].state == sf::Color::White ? total + 1 : total + 0; 
    total = grid_matrix[cell.row-1][cell.column+1].state == sf::Color::White ? total + 1 : total + 0; 
    total = grid_matrix[cell.row][cell.column-1].state == sf::Color::White ? total + 1 : total + 0; 
    total = grid_matrix[cell.row][cell.column+1].state == sf::Color::White ? total + 1 : total + 0;

    if(cell.row != 59){
        total = grid_matrix[cell.row+1][cell.column-1].state == sf::Color::White ? total + 1 : total + 0; 
        total = grid_matrix[cell.row+1][cell.column].state == sf::Color::White ? total + 1 : total + 0; 
        total = grid_matrix[cell.row+1][cell.column+1].state == sf::Color::White ? total + 1 : total + 0; 
    }

    // for(int i = cell.row-1; i <= cell.row+1; i++){
    //     for(int j = cell.column-1; j <= cell.column+1; j++){
    //         if(row != cell.row && col != cell.column){
    //             total = grid_matrix[i][j].state == sf::Color::White ? total + 1 : total + 0;
    //             std::cout << "row: " << row << "col: " << col << std::endl;
    //         }
    //     }
    // }

    //changing state depending on the state of the neighbours
    if(total == 3)
        cell.state = sf::Color::White;
    else if(total < 2)
        cell.state = sf::Color::Transparent;
    else if(total > 3)
        cell.state = sf::Color::Transparent;
}