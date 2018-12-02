#include "grid.h"

Grid::Grid() {
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            _table[i][j] = new Coordinate(Coord(j+1),Coord(i+1));
        }
    }
}

void Grid::display() {
    for(int i=0;i<10;i++) {
        std::cout << "--------------------\n";
        for(int j=0;j<10;j++) {
            std::cout << "|" << _table[i][j]->_value;
        }
        std::cout << "|\n";
    }
    std::cout << "--------------------\n";
}

void Grid::fillShipH(Coordinate start, Coordinate end){
    for(int i=start._hCoord ; i<=end._hCoord ; i++){
        Coord c;
        if(i==1)
            c=A;
        else if(i==2)
            c=B;
        else if(i==3)
            c=C;
        else if(i==4)
            c=D;
        else if(i==5)
            c=E;
        else if(i==6)
            c=F;
        else if(i==7)
            c=G;
        else if(i==8)
            c=H;
        else if(i==9)
            c=I;
        else if(i==10)
            c=J;
        else
            c=NONE;
        _table[start._vCoord][i] = new Coordinate(c, start._vCoord, HIDDEN);
    }
}

void Grid::fillShipV(Coordinate start, Coordinate end){
    for(int i=start._vCoord ; i<=end._vCoord ; i++){
        Coord c;
        if(i==1)
            c=A;
        else if(i==2)
            c=B;
        else if(i==3)
            c=C;
        else if(i==4)
            c=D;
        else if(i==5)
            c=E;
        else if(i==6)
            c=F;
        else if(i==7)
            c=G;
        else if(i==8)
            c=H;
        else if(i==9)
            c=I;
        else if(i==10)
            c=J;
        else
            c=NONE;
        _table[i][start._hCoord] = new Coordinate(c, start._vCoord, HIDDEN);
    }
}

Grid::~Grid() = default;
