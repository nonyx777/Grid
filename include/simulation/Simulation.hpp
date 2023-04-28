#include <iostream>
#include <SFML/Graphics.hpp>
#include "../cell/Cell.hpp"
#include <math.h>
#include <chrono>
#include <thread>

class Simulation{
    public:
        void simulateParticle(Cell &cell, Cell (&grid_matrix)[100][100]);
        void simulateSand(Cell &cell, Cell (&grid_matrix)[100][100]);
        void simulateWater(Cell &cell, Cell (&grid_matrix)[100][100]);
};