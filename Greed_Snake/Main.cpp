#include <iostream>

#include "ReleaseMemory.h"
#include "SnakeCreateFood.h"
using namespace std;
int main() {
  Snake_Nature *snake1 = new Snake_Nature(2, 2, UP);
  SnakeTraceDeleteTailNode *TraceTailNode = new SnakeTraceDeleteTailNode();
  CreateFood *FoodNode = new CreateFood(10);
  FoodNode->CreateSrandFood(snake1);
  FoodNode->PrFoodPosition();
  int SnakeControlMoveDirection;
  while (!snake1->SnakeIsCrashSelf()) {
    cin >> SnakeControlMoveDirection;
    snake1->SnakeControlMove(SnakeControlMoveDirection, TraceTailNode);
    FoodNode->IsCheckFood(snake1, TraceTailNode);
    snake1->PrintNodePosition();
  }
  CleanMemory RealseMemory;
  RealseMemory.CleanclassMemory(snake1, TraceTailNode, FoodNode);
  return 0;
}