#include <iostream>
#include <string>
#include <time.h>
#include "organism.h"
#include "ant.h"
#include "doodlebug.h"
#include "board.h"

using namespace std;



int main()
{
  srand(time(NULL));

  Board game;
  game.print();
  cout << "Press spacebar to continue and x to exit" << endl;
  char stepper = 'a'; //arbitrary 'a' initialization
  while(stepper != 'x')
  {
    cin.get(stepper);
    if(stepper == ' ')
    {
      game.step();
      game.print();
      //game.print2();
    }
  }
  return 0;
}
