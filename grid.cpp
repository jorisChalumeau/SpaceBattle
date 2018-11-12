#include "grid.h"

Grid::Grid() {
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            _table[i][j] = {Coord(j+1),Coord(i+1),UNKOWN};
        }
    }
}

void Grid::display() {
    for(int i=0;i<10;i++) {
        std::cout << "--------------------\n";
        for(int j=0;j<10;j++) {
            std::cout << "|" << _table[i][j].value;
        }
        std::cout << "\n";
    }
    std::cout << "--------------------\n";
}

Grid::~Grid() = default;
