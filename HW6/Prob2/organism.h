#ifndef ORGANISM_H
#define ORGANISM_H

class Organism
{
public:
  Organism();
  Organism(int r, int c);
  Organism(char ch, int r, int c);
  //void operator =(Organism * otherOrganism);  //defined
  //virtual void move();
  virtual void move(Organism*** board, int row, int column);

  //virtual void move(Board& game, int row, int column);
  virtual void breed(Organism*** board, int row, int column);
  virtual Organism * settle(Organism *otherOrg);
  void chooseDirection(Organism*** board, int row, int column, int& notNum, int& direction, int bound);

  //accessors
  char getChar() {return repChar;}
  int getTurnsSurvived() {return turnsSurvived;}
  int getRow() {return row;}
  int getColumn() {return column;}
  bool getUsed() {return spotUsed;}
  bool getMoved() {return moved;}

  //mutators
  void setChar(char c) {repChar = c;}
  void setTurnsSurvived(int num) {turnsSurvived = num;}
  void setRow(int num) {row = num;}
  void setColumn(int num) {column = num;}
  void setUsed(bool bo) {spotUsed = bo;}
  void setMoved(bool bo) {moved = bo;}

  //virtual accessors and mutators for Doodlebug
  //accessors
  virtual int getLastEaten() {return -1;}

  //mutators
  virtual void setLastEaten(int num) {return;}
  //functions
  virtual void starve(Organism*** board, int row, int column) {return;}

protected:

private:
  char repChar; //is 'O'
  int turnsSurvived;
  int row;
  int column;
  bool spotUsed;
  bool moved;

};

#endif //ORGANISM_H
