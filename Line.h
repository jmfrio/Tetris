#ifndef LINE_H
#define LINE_H

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "Piece.h"

class Line : public Piece {
  public:
    Line(int size=4);
    virtual void fillVec();
  private:
    string color;
};

#endif
