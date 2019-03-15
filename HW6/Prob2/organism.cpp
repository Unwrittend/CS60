#include "organism.h"
#include <iostream>

using std::cout;
using std::endl;

Organism::Organism() : repChar(' '), turnsSurvived(0), row(-1), column(-1), spotUsed(false), moved(false)
{
  //purposefully empty
}

Organism::Organism(int r, int c) :
    repChar(' '), turnsSurvived(0), row(r), column(c), spotUsed(false), moved(false)
{
  //purposefully empty
}

Organism::Organism(char ch, int r, int c) :
    repChar(ch), turnsSurvived(0), row(r), column(c), spotUsed(false), moved(false)
{
  //purposefully empty
}

/*
Organism * Organism::operator =(Organism * otherOrganism)
{
  this->setChar(otherOrganism->getChar());
  this->setTurnsSurvived(otherOrganism->getTurnsSurvived());
  this->setUsed(otherOrganism->getUsed());
  return this;
}
*/

void Organism::move(Organism*** board, int row, int column)
{
  return;
/*
  cout << "ERROR: USING ORGANISM CLASS FUNC MOVE" << endl;
  exit(1);
  */
}

/*
void Organism::move(Board& game, int row, int column)
{
  cout << "ERROR: USING ORGANISM CLASS FUNC MOVE" << endl;
  exit(1);
}
*/

void Organism::breed(Organism*** board, int row, int column)
{
  return;
/*
  cout << "ERROR: USING ORGANISM CLASS FUNC BREED" << endl;
  exit(1);
  */
}

Organism * Organism::settle(Organism *otherOrg)
{
  return this;
}


void Organism::chooseDirection(Organism*** board, int row, int column,
        int& notNum, int& direction, int bound)
{
  return;
/*
  if(((direction%4) == 0)) //if not occupied and in bounds
  {
    if((row) < bound)  //if out of bounds check next move action
    {
      direction++;
      notNum++;
    }
    else if(board[row][column]->getUsed() == false)
    {
      delete board[row][column];
      board[row][column] = new Organism(row, column);
      notNum = 10; //stops while loop meaning spot found
    }
    else  //if board[row-1][column] is occupied
    {
      direction++;
      notNum++;
    }
  }
  */
}
