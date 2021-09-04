#include <iostream>

#include "Snake.h"
using namespace std;
int main() {
  Snake_Nature snake1(2, 2, UP);
  int SnakeControlMoveDirection;
  while(cin>>SnakeControlMoveDirection)
  {
        snake1.SnakeControlMove(SnakeControlMoveDirection);
        snake1.PrintNodePosition();
  }
  return 0;
}