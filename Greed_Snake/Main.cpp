#include <iostream>

#include "Snake.h"
using namespace std;
int main() {
  Snake_Nature snake1(1, 1, UP);
  snake1.SnakeMoveDown();
  cout << snake1.SnakeNodePosition_X << endl;
  return 0;
}