#include <thread>
#include <iostream>
#include <chrono>
#include "../cell/Cell.hpp"

class Crol{
    public:
        Crol();
    public:
        void neighbourCheck(Cell &cell, Cell (&grid_matrix)[60][60]);
};