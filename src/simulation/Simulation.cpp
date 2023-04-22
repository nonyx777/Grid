#include "../../include/simulation/Simulation.hpp"


void Simulation::simulateParticle(Cell &cell, Cell (&grid_matrix)[60][60]){
    if(cell.type == Cell().SAND)
        this->simulateSand(cell, grid_matrix);
    else if(cell.type == Cell().WATER)
        this->simulateWater(cell, grid_matrix);
}
void Simulation::simulateSand(Cell &cell, Cell (&grid_matrix)[60][60]){
    int row = cell.row;
    int column = cell.column;

    if(grid_matrix[row+1][column].type == Cell().EMPTY){
        grid_matrix[row+1][column].type = Cell().SAND;
        std::this_thread::sleep_for(std::chrono::microseconds(500));
        grid_matrix[row][column].type = Cell().EMPTY;
    }
    else if(grid_matrix[row+1][column-1].type == Cell().EMPTY){
        grid_matrix[row+1][column-1].type = Cell().SAND;
        std::this_thread::sleep_for(std::chrono::microseconds(500));
        grid_matrix[row][column].type = Cell().EMPTY;
    }
    else if(grid_matrix[row+1][column+1].type == Cell().EMPTY){
        grid_matrix[row+1][column+1].type = Cell().SAND;
        std::this_thread::sleep_for(std::chrono::microseconds(500));
        grid_matrix[row][column].type = Cell().EMPTY;
    }
}
void Simulation::simulateWater(Cell &cell, Cell (&grid_matrix)[60][60]){
    //..
}