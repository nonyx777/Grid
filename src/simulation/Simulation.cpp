#include "../../include/simulation/Simulation.hpp"


void Simulation::simulateParticle(Cell &cell, std::vector<std::vector<Cell>>& grid_vector){
    if(cell.type == Cell().SAND)
        this->simulateSand(cell, grid_vector);
    else if(cell.type == Cell().WATER)
        this->simulateWater(cell, grid_vector);
}
void Simulation::simulateSand(Cell &cell, std::vector<std::vector<Cell>>& grid_vector){
    int row = cell.row;
    int column = cell.column;

    auto seed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    srand(seed);
    float number = 0.f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(1 - 0)));

    if(grid_vector[row+1][column].type == Cell().EMPTY){
        grid_vector[row+1][column].type = Cell().SAND;
        grid_vector[row][column].type = Cell().EMPTY;
    }
    else if(grid_vector[row+1][column].type == Cell().WATER){
        grid_vector[row+1][column].type = Cell().SAND;
        grid_vector[row][column].type = Cell().WATER;
    }
    //run a random number generator
    //call the left check function if the number is 0
    //call the right check function if the number is 1

    else if(number <= 0.5f)
        this->checkLeftSand(row, column, grid_vector);
    else if(number > 0.5f)
        this->checkRightSand(row, column, grid_vector);
}
void Simulation::simulateWater(Cell &cell, std::vector<std::vector<Cell>>& grid_vector){
    int row = cell.row;
    int column = cell.column;
    if(grid_vector[row+1][column].type == Cell().EMPTY){
        grid_vector[row+1][column].type = Cell().WATER;
        grid_vector[row][column].type = Cell().EMPTY;
    }
    else if(grid_vector[row+1][column-1].type == Cell().EMPTY){
        grid_vector[row+1][column-1].type = Cell().WATER;
        grid_vector[row][column].type = Cell().EMPTY;
    }
    else if(grid_vector[row+1][column+1].type == Cell().EMPTY){
        grid_vector[row+1][column+1].type = Cell().WATER;
        grid_vector[row][column].type = Cell().EMPTY;
    }
    else if(column != 0 && grid_vector[row][column-1].type == Cell().EMPTY){
        grid_vector[row][column-1].type = Cell().WATER;
        grid_vector[row][column].type = Cell().EMPTY;
    }
    else if(column != 59 && grid_vector[row][column+1].type == Cell().EMPTY){
        grid_vector[row][column+1].type = Cell().WATER;
        grid_vector[row][column].type = Cell().EMPTY;
    }
}

//sand....
void Simulation::checkLeftSand(int row, int column, std::vector<std::vector<Cell>>& grid_vector){
    if(grid_vector[row+1][column-1].type == Cell().EMPTY){
        grid_vector[row+1][column-1].type = Cell().SAND;
        grid_vector[row][column].type = Cell().EMPTY;
    }
}
void Simulation::checkRightSand(int row, int column, std::vector<std::vector<Cell>>& grid_vector){
    if(grid_vector[row+1][column+1].type == Cell().EMPTY){
        grid_vector[row+1][column+1].type = Cell().SAND;
        grid_vector[row][column].type = Cell().EMPTY;
    }
}