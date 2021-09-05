#include <iostream>
#include "SnakeCreateFood.h"
using namespace std;
int main() {
  Snake_Nature *snake1=new Snake_Nature(2, 2, UP);
  CreateFood Food(10);
  snake1->PrintNodePosition();
  Food.CreateSrandFood(snake1);
  Food.PrFoodPosition();
  int SnakeControlMoveDirection;
  /*while (!snake1.SnakeIsCrashSelf()) {
    cin >> SnakeControlMoveDirection;
    snake1.SnakeControlMove(SnakeControlMoveDirection);
    snake1.PrintNodePosition();
  }*/
  return 0;
}