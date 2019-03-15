//-------
//boggle
//-------

#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <ctime>

using namespace std;

struct tile
{
    char letter;
    bool used;
};

void populate(tile board[][4]);
void reset(tile board[][4]);
void unboggle(string word, tile board[][4], int row, int column, int index, string madeWord, set<string>& possibleWord);
void print(tile board[][4]);




int main()
{
  srand(time(NULL));
  tile board[4][4];
  populate(board);
  print(board);

  set<string> possibleWord;

  ifstream infile;
  infile.open("words.txt");
  while(!infile.eof())
  {
      string dictionaryWord;
      infile >> dictionaryWord;

      for(int row = 0; row < 4; row++)
      {
          for(int column = 0; column < 4; column++)
          {
              unboggle(dictionaryWord, board, row, column, 0, "", possibleWord);
              reset(board);
          }
      }

  }
  infile.close();

  for(auto temp:possibleWord)
  {
    cout << temp << endl;
  }

  return 0;
}



void unboggle(string word, tile board[][4], int row, int column, int index, string madeWord, set<string>& possibleWord)
{

    if( (row >= 0 && row < 4) && (column >= 0 && column < 4) && (board[row][column].used == false) && (index < word.size()) )
    {


        if(word.at(index) == board[row][column].letter)
        {
            board[row][column].used = true;
            madeWord += board[row][column].letter;

            unboggle(word, board, row-1, column, index+1, madeWord, possibleWord);
            unboggle(word, board, row-1, column-1, index+1, madeWord, possibleWord);
            unboggle(word, board, row-1, column+1, index+1, madeWord, possibleWord);
            unboggle(word, board, row, column-1, index+1, madeWord, possibleWord);
            unboggle(word, board, row, column+1, index+1, madeWord, possibleWord);
            unboggle(word, board, row+1, column, index+1, madeWord, possibleWord);
            unboggle(word, board, row+1, column-1, index+1, madeWord, possibleWord);
            unboggle(word, board, row+1, column+1, index+1, madeWord, possibleWord);
        }
        else
        {
            return;
        }

        if( (word.size() - 1 == index) && (word == madeWord) )
        {
            possibleWord.insert(word);
            return;
        }
    }
    else //out of bounds
    {
        return;
    }
}

void populate(tile board[][4])
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
          int randLetr = rand() % 26;
          board[i][j].letter = ('a' + randLetr);
          board[i][j].used = false;  //i.e. they have not yet been used
        }
    }
}

void reset(tile board[][4])
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            board[i][j].used = false;  //i.e. they have not yet been used
        }
    }
}

void print(tile board[][4])
{
  //row 1
  cout << "|";
  for(int j = 0; j < 4; j++)
  {
    cout << board[0][j].letter << "|";
  }
  cout << endl;

  //row 2
  cout << "|";
  for(int j = 0; j < 4; j++)
  {
    cout << board[1][j].letter << "|";
  }
  cout << endl;

  //row 3
  cout << "|";
  for(int j = 0; j < 4; j++)
  {
    cout << board[2][j].letter << "|";
  }
  cout << endl;

  //row 4
  cout << "|";
  for(int j = 0; j < 4; j++)
  {
    cout << board[3][j].letter << "|";
  }
  cout << endl;
}
