#include "doodlebug.h"
#include <iostream>
#include <time.h>

using namespace std;

Doodlebug::Doodlebug(): Organism('X', -1, -1)
{
  this->setUsed(true);
  this->setTurnsSurvived(1);
  this->setLastEaten(1);
}

//with row and column i.e. location
Doodlebug::Doodlebug(int r, int c) : Organism('X', r, c)
{
  this->setUsed(true);
  this->setTurnsSurvived(1);
  this->setLastEaten(1);
}

void Doodlebug::move(Organism*** board, int row, int column)
{
  int direction = rand() % 4;

  //checking for an Ant
  int notAnt = 0; //number of spots without an Ant
  while(notAnt < 4)
  {

    //up
    if(((direction%4) == 0)) //if not occupied and in bounds
    {
      if((row - 1) < 0)  //if out of bounds check next move action
      {
        direction++;
        notAnt++;
      }
      else if(board[row-1][column]->getChar() == 'O')
      {
        delete[] board[row-1][column];
        board[row - 1][column] = board[row][column];

        //settling in new spot
        board[row - 1][column]->settle(board[row][column]);
        board[row-1][column]->setLastEaten(0);

        board[row][column] = new Organism(row, column); //the bug
        notAnt = 5;
      }
      else
      {
        direction++;
        notAnt++;
      }
    }

    //down
    if(((direction%4) == 1)) //if not occupied and in bounds
    {
      if((row + 1) > 19)  //if out of bounds check next move action
      {
        direction++;
        notAnt++;
      }
      else if(board[row+1][column]->getChar() == 'O')
      {
        delete[] board[row+1][column];
        board[row + 1][column] = board[row][column];

        //settling in new spot
        board[row + 1][column]->settle(board[row][column]);
        board[row+1][column]->setLastEaten(0);

        board[row][column] = new Organism(row, column); //the bug
        notAnt = 5;
      }
      else
      {
        direction++;
        notAnt++;
      }
    }

    //left
    if(((direction%4) == 2)) //if not occupied and in bounds
    {
      if((column - 1) < 0)  //if out of bounds check next move action
      {
        direction++;
        notAnt++;
      }
      else if(board[row][column-1]->getChar() == 'O')
      {
        delete[] board[row][column-1];
        board[row][column-1] = board[row][column];

        //settling in new spot
        board[row][column-1]->settle(board[row][column]);
        board[row][column-1]->setLastEaten(0);

        board[row][column] = new Organism(row, column); //the bug
        notAnt = 5;
      }
      else
      {
        direction++;
        notAnt++;
      }
    }

    //left
    if(((direction%4) == 3)) //if not occupied and in bounds
    {
      if((column + 1) > 19)  //if out of bounds check next move action
      {
        direction++;
        notAnt++;
      }
      else if(board[row][column+1]->getChar() == 'O')
      {
        delete[] board[row][column+1];
        board[row][column+1] = board[row][column];

        //settling in new spot
        board[row][column+1]->settle(board[row][column]);
        board[row][column+1]->setLastEaten(0);

        board[row][column] = new Organism(row, column); //the bug
        notAnt = 5;
      }
      else
      {
        direction++;
        notAnt++;
      }
    }
  }

  direction = rand() % 4;

  int noSpot = 0;
  while(noSpot < 4)
  {
    //up
    if(((direction%4) == 0)) //if not occupied and in bounds
    {
      if((row - 1) < 0)  //if out of bounds check next move action
      {
        direction++;
        noSpot++;
      }
      else if((board[row-1][column]->getUsed()) == false && (board[row][column]->getMoved() == false))
      {
        delete board[row-1][column];
        board[row - 1][column] = board[row][column];

        //settling in new spot
        board[row - 1][column]->settle(board[row][column]);
        board[row-1][column]->setLastEaten( board[row][column]->getLastEaten()+1 );

        board[row][column] = new Organism(row, column); //the bug
        board[row][column]->setUsed(false); //the bug

        noSpot = 5;
      }
      else
      {
        direction++;
        notAnt++;
      }
    }

    //down
    if(((direction%4) == 1)) //if not occupied and in bounds
    {
      if((row + 1) > 19)  //if out of bounds check next move action
      {
        direction++;
        noSpot++;
      }
      else if((board[row+1][column]->getUsed()) == false && (board[row][column]->getMoved() == false))
      {
        delete board[row+1][column];
        board[row + 1][column] = board[row][column];

        //settling in new spot
        board[row + 1][column]->settle(board[row][column]);
        board[row+1][column]->setLastEaten( board[row][column]->getLastEaten()+1 );

        board[row][column] = new Organism(row, column); //the bug
        board[row][column]->setUsed(false); //the bug
        noSpot = 5;
      }
      else
      {
        direction++;
        noSpot++;
      }
    }

    //left
    if(((direction%4) == 2)) //if not occupied and in bounds
    {
      if((column - 1) < 0)  //if out of bounds check next move action
      {
        direction++;
        noSpot++;
      }
      else if((board[row][column-1]->getUsed()) == false && (board[row][column]->getMoved() == false))
      {
        delete board[row][column-1];
        board[row][column-1] = board[row][column];

        //settling in new spot
        board[row][column-1]->settle(board[row][column]);
        board[row][column-1]->setLastEaten( board[row][column]->getLastEaten()+1 );

        board[row][column] = new Organism(row, column); //the bug
        board[row][column]->setUsed(false); //the bug
        noSpot = 5;
      }
      else
      {
        direction++;
        noSpot++;
      }
    }

    //left
    if(((direction%4) == 3)) //if not occupied and in bounds
    {
      if((column + 1) > 19)  //if out of bounds check next move action
      {
        direction++;
        noSpot++;
      }
      else if((board[row][column+1]->getUsed()) == false && (board[row][column]->getMoved() == false))
      {
        delete board[row][column+1];
        board[row][column+1] = board[row][column];

        //settling in new spot
        board[row][column+1]->settle(board[row][column]);
        board[row][column+1]->setLastEaten( board[row][column]->getLastEaten()+1 );

        board[row][column] = new Organism(row, column); //the bug
        board[row][column]->setUsed(false); //the bug

        noSpot = 5;
      }
      else
      {
        direction++;
        noSpot++;
      }
    }
  }

}

void Doodlebug::breed(Organism*** board, int row, int column)
{
  int beenAlive = board[row][column]->getTurnsSurvived();
  if(beenAlive%8 == 0)
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
          board[row - 1][column] = new Doodlebug(row, column);
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
          board[row + 1][column] = new Doodlebug(row, column);
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
          board[row][column-1] = new Doodlebug(row, column);
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
          board[row][column+1] = new Doodlebug (row, column);
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
}

//test by taking away all ants
//not working---look at later
void Doodlebug::starve(Organism*** board, int row, int column)
{
  //cout << "Here" << endl;
  int temp = board[row][column]->getLastEaten();
  if(temp==3)
  {
    delete[] board[row][column];
    board[row][column] = new Organism(row, column);
  }
}

Organism * Doodlebug::settle(Organism *otherOrg)
{
  this->setUsed(true);
  this->setRow(otherOrg->getRow());
  this->setColumn(otherOrg->getColumn());
  //this->setTurnsSurvived(otherOrg->getTurnsSurvived()+1);
  this->setChar(otherOrg->getChar());
  this->setMoved(true);

  return this;
}

/*
void Doodlebug::antNearLeftUp(Organism*** board, int row, int column, int& direction, int& notNum, int action)
{
  //action is the direction it check against
  if(((direction%4) == action)) //if not occupied and in bounds
  {
    if((row) < 0)  //if out of bounds check next move action
    {
      direction++;
      notNum++;
    }
    else if(board[row][column]->getChar() == 'O')
    {
      delete[] board[row][column];
      board[row][column] = board[row][column];

      //settling in new spot
      board[row][column]->settle(board[row][column]);

      board[row][column] = new Organism(row, column); //the bug
      notNum = 10;
    }
    else
    {
      direction++;
      notNum++;
    }
  }
}

void Doodlebug::antNearRightDown(Organism*** board, int row, int column, int& direction, int& notNum, int action)
{
  //action is the direction it check against
  if(((direction%4) == action)) //if not occupied and in bounds
  {
    if((row) < 19)  //if out of bounds check next move action
    {
      direction++;
      notNum++;
    }
    else if(board[row][column]->getChar() == 'O')
    {
      delete[] board[row][column];
      board[row][column] = board[row][column];

      //settling in new spot
      board[row][column]->settle(board[row][column]);

      board[row][column] = new Organism(row, column); //the bug
      notNum = 10;
    }
    else
    {
      direction++;
      notNum++;
    }
  }
}
*/
