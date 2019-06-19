//
// Created by Max on 19/05/2019.
//

#ifndef MINI_PROJECT_GRID_MODEL_H
#define MINI_PROJECT_GRID_MODEL_H

#include <vector>
#include <array>

using std::array;

#define CASE grid[line][column]
#define GridSIZE 7
#define GridType array < array <int, GridSIZE>, GridSIZE>

class Grid_Model {
private:
    GridType grid = {};

public:
    Grid_Model() = default;

    GridType& getGrid() { return this->grid; }

    void setValue(int line, int column, int value) { this->CASE = value; }
    int getValue(int line, int column) { return this->CASE; }

    virtual ~Grid_Model() {}
};

#endif //MINI_PROJECT_GRID_MODEL_H
