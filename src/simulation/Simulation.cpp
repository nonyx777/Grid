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
    float vertical_number = 0.f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(2 - 0)));

    if(grid_vector[row+1][column].type == Cell().EMPTY){
        grid_vector[row+1][column].type = Cell().SAND;
        grid_vector[row][column].type = Cell().EMPTY;
    }

    else if(grid_vector[row+1][column].type == Cell().WATER){
        grid_vector[row+1][column].type = Cell().SAND;
        grid_vector[row][column].type = Cell().WATER;
    }

    else if(vertical_number <= 1.f){
        if(grid_vector[row+1][column-1].type == Cell().EMPTY){
            grid_vector[row+1][column-1].type = Cell().SAND;
            grid_vector[row][column].type = Cell().EMPTY;
        }
    }

    else if(vertical_number > 1.f){
        if(grid_vector[row+1][column+1].type == Cell().EMPTY){
            grid_vector[row+1][column+1].type = Cell().SAND;
            grid_vector[row][column].type = Cell().EMPTY;
        }
    }
}
void Simulation::simulateWater(Cell &cell, std::vector<std::vector<Cell>>& grid_vector){
    int row = cell.row;
    int column = cell.column;

    auto seed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    srand(seed);
    float vertical_number = 0.f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(2 - 0)));
    float horizontal_number = 0.f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(2 - 0)));


    if(grid_vector[row+1][column].type == Cell().EMPTY){
        grid_vector[row+1][column].type = Cell().WATER;
        grid_vector[row][column].type = Cell().EMPTY;
    }

    else if(vertical_number <= 1.f){
        if(grid_vector[row+1][column-1].type == Cell().EMPTY){
            grid_vector[row+1][column-1].type = Cell().WATER;
            grid_vector[row][column].type = Cell().EMPTY;
        }

        else if(horizontal_number <= 1.f){
            if(column != 0 && grid_vector[row][column-1].type == Cell().EMPTY){
                grid_vector[row][column-1].type = Cell().WATER;
                grid_vector[row][column].type = Cell().EMPTY;
            }
        }

        else if(horizontal_number > 1.f){
            if(column != 59 && grid_vector[row][column+1].type == Cell().EMPTY){
                grid_vector[row][column+1].type = Cell().WATER;
                grid_vector[row][column].type = Cell().EMPTY;
            }   
        }
    }

    else if(vertical_number > 1.f){
        if(grid_vector[row+1][column+1].type == Cell().EMPTY){
            grid_vector[row+1][column+1].type = Cell().WATER;
            grid_vector[row][column].type = Cell().EMPTY;
        }

        else if(horizontal_number <= 1.f){
            if(column != 0 && grid_vector[row][column-1].type == Cell().EMPTY){
                grid_vector[row][column-1].type = Cell().WATER;
                grid_vector[row][column].type = Cell().EMPTY;
            }
        }

        else if(horizontal_number > 1.f){
            if(column != 59 && grid_vector[row][column+1].type == Cell().EMPTY){
                grid_vector[row][column+1].type = Cell().WATER;
                grid_vector[row][column].type = Cell().EMPTY;
            }   
        }
    }
}