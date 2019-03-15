#ifndef ANT_H
#define ANT_H

#include "organism.h"

class Ant : public Organism
{
public:
  Ant();
  Ant(int r, int c);
  void move(Organism*** board, int row, int column);
  void breed(Organism*** board, int row, int column);
  void chooseDirection(Organism*** board, int row, int column, int& notNum, int& direction, int bound);
  Organism * settle(Organism *otherOrg);
  //virtual from Doodlebug
  //accessors
  virtual int getLastEaten() {return -1;}

  //mutators
  virtual void setLastEaten(int num) {return;}

  //functions
  void starve(Organism*** board, int row, int column) {return;}


protected:

private:

};

#endif //ANT_H
