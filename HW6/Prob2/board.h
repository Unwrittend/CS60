#ifndef BOARD_H
#define BOARD_H

#include "ant.h"
#include "doodlebug.h"

//needs destructor
class Board
{
public:
  Board();  //populates in constructor
  void print();
  void print2();  //for testing purposes
  void step();
  Organism getTile(int row, int column) {return *(tile[row][column]);}
  ~Board();
private:
  Organism ***tile; //3d dynamic array of pointers
  int boardLength;
  bool popMax(int critterCount, int max); //have you fully populated the board yet?
  void reset();
};

#endif //BOARD_H
