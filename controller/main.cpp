#include <iostream>
#include <QApplication>

#include "../model/Player.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Grid *gridP1 = new Grid();
    Grid *gridP2 = new Grid();
    Player *p1 = new Player(1, *gridP1, *gridP2);
    Player *p2 = new Player(2, *gridP2, *gridP1);

    gridP1->display();
    gridP2->display();

    return 0;
}