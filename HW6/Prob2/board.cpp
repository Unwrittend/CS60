#include "board.h"

#include <iostream>
#include <time.h>
using namespace std;

Board::Board()
{

  //initialize a 20 x 20 dynamic board
  boardLength = 20;
  tile = new Organism ** [boardLength];
  for(int index = 0; index < boardLength; index++)
  {
    tile[index] = new Organism * [boardLength];
  }
  for(int row = 0; row < boardLength; row++)
  {
    for(int column = 0; column < boardLength; column++)
    {
      tile[row][column] = new Organism(' ', row, column);
    }
  }


  //populate ants
  int antCount = 0;
  bool antDone = false;
  const int antMax = 100;
  do {
    for(int row = 0; row < boardLength; row++)
    {
      for(int column = 0; column < boardLength; column++)
      {
        if(popMax(antCount, antMax))
        {
          if(tile[row][column]->getUsed() == false)
          {
            if(rand() % 10 == 0) //10% chance to populate tile
            {
              Organism *temp = tile[row][column];
              tile[row][column] = new Ant(row, column);
              delete [] temp;
              antCount++;
            }
          }
        }
      }
    }
  } while(popMax(antCount, antMax));


  //populate doodlebug
  int dooCount = 0;
  bool dooDone = false;
  int dooMax = 5;
  //cout << dooCount;


  do {
    for(int row = 0; row < boardLength; row++)
    {
      for(int column = 0; column < boardLength; column++)
      {
        if(popMax(dooCount, dooMax))
        {
          if(tile[row][column]->getUsed() == false)
          {
            if(rand() % 200 == 0) //.5% chance to populate tile
            {
              Organism *temp = tile[row][column];
              tile[row][column] = new Doodlebug(row, column);
              delete [] temp;
              dooCount++;
            }
          }
        }
      }
    }
  } while(popMax(dooCount, dooMax));

}

void Board::print()
{
  for(int row = 0; row < boardLength; row++)
  {
    cout << "|";

    for(int column = 0; column < boardLength; column++)
    {
      cout << tile[row][column]->getChar() << "|";
      //cout << tile[row][column]->getLastEaten() << "|";

      //cout << tile[row][column]->getTurnsSurvived() << "|";

      //cout << tile[row][column]->getRow() << "|";
      //cout << tile[row][column]->getUsed() << "|";
      //cout << tile[row][column]->getMoved() << "|";
    }
    cout << endl;

  }
  cout << endl;

}

void Board::print2()
{
  for(int row = 0; row < boardLength; row++)
  {
    cout << "|";

    for(int column = 0; column < boardLength; column++)
    {
      //cout << tile[row][column]->getChar() << "|";
      //cout << tile[row][column]->getLastEaten() << "|";
      cout << tile[row][column]->getUsed() << "|";
      //cout << tile[row][column]->getTurnsSurvived() << "|";

      //cout << tile[row][column]->getRow() << "|";
      //cout << tile[row][column]->getMoved() << "|";
    }
    cout << endl;

  }
  cout << endl;

}



void Board::step()
{

  //move
  for(int row = 0; row < boardLength; row++)
  {
    for(int column = 0; column < boardLength; column++)
    {
      tile[row][column]->starve(tile, row, column);
      tile[row][column]->move(tile, row, column);
    }
  }

  //breed
  for(int row = 0; row < boardLength; row++)
  {
    for(int column = 0; column < boardLength; column++)
    {
      tile[row][column]->breed(tile, row, column);
      tile[row][column]->setTurnsSurvived(tile[row][column]->getTurnsSurvived()+1);
    }
  }

  reset();
}


bool Board::popMax(int critterCount, int max)
{
  if(critterCount < max)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Board::reset()
{
  for(int row = 0; row < boardLength; row++)
  {
    for(int column = 0; column < boardLength; column++)
    {
      tile[row][column]->setMoved(false);
    }
  }
}


Board::~Board()
{
  for(int row = 0; row < 0; row++)
  {
    for(int column = 0; column < 0; column++)
    {
      delete[] tile[row][column];
    }
  }
}
