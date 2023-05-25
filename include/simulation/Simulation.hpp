#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "../cell/Cell.hpp"
#include <math.h>
#include <chrono>
#include <thread>

class Simulation{
    public:
        void simulateParticle(Cell &cell, std::vector<std::vector<Cell>>& grid_vector);
        void simulateSand(Cell &cell, std::vector<std::vector<Cell>>& grid_vector);
        void simulateWater(Cell &cell, std::vector<std::vector<Cell>>& grid_vector);

        //
        void checkLeftSand(int row, int column, std::vector<std::vector<Cell>>& grid_Vector);
        void checkRightSand(int row, int column, std::vector<std::vector<Cell>>& grid_Vector);
};