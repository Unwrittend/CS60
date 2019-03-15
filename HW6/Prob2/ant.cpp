#include "ant.h"
#include <iostream>
#include <time.h>
//#include <cstddef>

using namespace std;

//creates an ant with a symbol 'O' which has been alive 0 turns
//all ants start this way
Ant::Ant() : Organism('O', -1, -1)
{
  this->setUsed(true);
  this->setTurnsSurvived(1);
}

//with row and column i.e. location
Ant::Ant(int r, int c) : Organism('O', r, c)
{
  this->setUsed(true);
  this->setTurnsSurvived(1);
}


//from left to right
void Ant::move(Organism*** board, int row, int column)
{

  //srand(time(NULL));  //initialized earlier
  int direction = rand() % 4;

/*
  int notOpen = 0;
  while(notOpen < 4)
  {
    //up
    board[row][column]->chooseDirection(board, row-1, column, notOpen, direction, 0);
    //down
    board[row][column]->chooseDirection(board, row+1, column, notOpen, direction, 19);
    //up
    board[row][column]->chooseDirection(board, row, column-1, notOpen, direction, 0);
    //up
    board[row][column]->chooseDirection(board, row, column+1, notOpen, direction, 19);
  }
*/

  int notOpen = 0;
  while(notOpen < 4)
  {
    //up
    if(((direction%4) == 0)) //if not occupied and in bounds
    {
      if((row - 1) < 0)  //if out of bounds check next move action
      {
        direction++;
        notOpen++;
      }
      else if((board[row-1][column]->getUsed()) == false && (board[row][column]->getMoved() == false))
      {
        delete board[row-1][column];
        board[row - 1][column] = board[row][column];

        //settling in new spot
        board[row - 1][column]->settle(board[row][column]);

        board[row][column] = new Organism(row, column); //the bug
        board[row][column]->setUsed(false); //the bug

        notOpen = 5;
      }
      else
      {
        direction++;
        notOpen++;
      }
    }

    //down
    if(((direction%4) == 1)) //if not occupied and in bounds
    {
      if((row + 1) > 19)  //if out of bounds check next move action
      {
        direction++;
        notOpen++;
      }
      else if(((board[row+1][column]->getUsed()) == false) && (board[row][column]->getMoved() == false))
      {
        delete board[row+1][column];
        board[row + 1][column] = board[row][column];

        //settling in new spot
        board[row + 1][column]->settle(board[row][column]);

        board[row][column] = new Organism(row, column); //correct one
        board[row][column]->setUsed(false); //the bug

        notOpen = 5;
      }
      else
      {
        direction++;
        notOpen++;
      }
    }

    //left
    if(((direction%4) == 2)) //if not occupied and in bounds
    {
      if((column - 1) < 0)  //if out of bounds check next move action
      {
        direction++;
        notOpen++;
      }
      else if(((board[row][column-1]->getUsed()) == false) && (board[row][column]->getMoved() == false))
      {
        delete board[row][column-1];
        board[row][column-1] = board[row][column];

        //settling in new spot
        board[row][column-1]->settle(board[row][column]);

        board[row][column] = new Organism(row, column); //correct one
        board[row][column]->setUsed(false); //the bug

        notOpen = 5;
      }
      else
      {
        direction++;
        notOpen++;
      }
    }

    //right
    if(((direction%4) == 3)) //if not occupied and in bounds
    {
      if((column + 1) > 19)  //if out of bounds check next move action
      {
        direction++;
        notOpen++;
      }
      else if(((board[row][column+1]->getUsed()) == false) && (board[row][column]->getMoved() == false))
      {
        delete board[row][column+1];
        board[row][column+1] = board[row][column];

        //settling in new spot
        board[row][column+1]->settle(board[row][column]);

        board[row][column] = new Organism(row, column); //correct one
        board[row][column]->setUsed(false); //the bug

        notOpen = 5;
      }
      else
      {
        direction++;
        notOpen++;
      }
    }
  }
} //end of func move


void Ant::breed(Organism*** board, int row, int column)
{
  int beenAlive = board[row][column]->getTurnsSurvived();
  if(beenAlive%3 == 0)
  {
    int direction = rand()%4;
    int notOpen = 0; //number of spots unavailable
    while(notOpen < 4)
    {
      if(((direction%4) == 0)) //if not occupied and in bounds
      {
        if((row - 1) < 0)  //if out of bounds check next move action
        {
          direction++;
          notOpen++;
        }
        else if(board[row-1][column]->getUsed() == false)
        {
          delete board[row-1][column];
          board[row - 1][column] = new Ant(row, column);
          notOpen = 5; //stops while loop meaning spot found
        }
        else  //if board[row-1][column] is occupied
        {
          direction++;
          notOpen++;
        }
      }
      if(((direction%4) == 1))
      {
        if((row + 1) > 19)  //if out of bounds check next move action
        {
          direction++;
          notOpen++;
        }
        else if(board[row+1][column]->getUsed() == false)
        {
          delete board[row+1][column];
          board[row + 1][column] = new Ant(row, column);
          notOpen = 5; //stops while loop meaning spot found
        }
        else  //if board[row-1][column] is occupied
        {
          direction++;
          notOpen++;
        }
      }
      if(((direction%4) == 2))
      {
        if((column - 1) < 0)  //if out of bounds check next move action
        {
          direction++;
          notOpen++;
        }
        else if(board[row][column-1]->getUsed() == false)
        {
          delete board[row][column-1];
          board[row][column-1] = new Ant(row, column);
          notOpen = 5; //stops while loop meaning spot found
        }
        else  //if board[row-1][column] is occupied
        {
          direction++;
          notOpen++;
        }
      }
      if(((direction%4) == 3))
      {
        if((column + 1) > 19)  //if out of bounds check next move action
        {
          direction++;
          notOpen++;
        }
        else if(board[row][column+1]->getUsed() == false)
        {
          delete board[row][column+1];
          board[row][column+1] = new Ant(row, column);
          notOpen = 5; //stops while loop meaning spot found
        }
        else  //if board[row-1][column] is occupied
        {
          direction++;
          notOpen++;
        }
      }
    }
  }
  //else nothing
} //end of func breed

Organism * Ant::settle(Organism *otherOrg)
{
  this->setUsed(true);
  this->setRow(otherOrg->getRow());
  this->setColumn(otherOrg->getColumn());
  //this->setTurnsSurvived(otherOrg->getTurnsSurvived()+1);
  this->setChar(otherOrg->getChar());
  this->setMoved(true);

  return this;
}

void Ant::chooseDirection(Organism*** board, int row, int column,
        int& notNum, int& direction, int bound)
{
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
      board[row][column] = board[row][column];

      //settling in new spot
      board[row][column]->settle(board[row][column]);

      board[row][column] = new Organism(row, column); //correct one
      notNum = 10; //stops while loop meaning spot found
    }
    else  //if board[row-1][column] is occupied
    {
      direction++;
      notNum++;
    }
  }
}
