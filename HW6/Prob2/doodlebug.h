#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "organism.h"

class Doodlebug : public Organism
{
public:
  Doodlebug();
  Doodlebug(int r, int c);
  void move(Organism*** board, int row, int column);
  void breed(Organism*** board, int row, int column);
  void starve(Organism*** board, int row, int column);
  Organism * settle(Organism *otherOrg);

  //accessors
  int getLastEaten() {return lastEaten;}

  //mutators
  void setLastEaten(int num) {lastEaten = num;}
private:
  int lastEaten;
  void antNearLeftUp(Organism*** board, int row, int column,
        int& direction, int& notNum, int action);
  void antNearRightDown(Organism*** board, int row, int column,
        int& direction, int& notNum, int action);
};
#endif //DOODLEBUG_H
