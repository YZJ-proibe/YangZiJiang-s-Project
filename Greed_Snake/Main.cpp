#include <iostream>

#include "ReleaseMemory.h"
#include "SnakeCreateFood.h"
#include "SnakeMap.h"
using namespace std;
int main() {
  Snake_Nature *snake1 = new Snake_Nature(2, 2, UP);
  SnakeTraceDeleteTailNode *TraceTailNode = new SnakeTraceDeleteTailNode();
  CreateFood *FoodNode = new CreateFood(10);
  SnakeCreateMap *CreateMap = new SnakeCreateMap();

  CreateMap->SnakeCreateMapObstacle(snake1, FoodNode);
  CreateMap->PrObstaclePosition();
  
  FoodNode->CreateSrandFood(snake1);
  FoodNode->PrFoodPosition();

  int SnakeControlMoveDirection;
  while (snake1->SnakeIsCrashSelf() && CreateMap->SnakeIsGameOver(snake1)) {
    cin >> SnakeControlMoveDirection;
    snake1->SnakeControlMove(SnakeControlMoveDirection, TraceTailNode);
    FoodNode->IsCheckFood(snake1, TraceTailNode);
    snake1->PrintNodePosition();
  }
  CleanMemory RealseMemory;
  RealseMemory.CleanclassMemory(snake1, TraceTailNode, FoodNode);
  return 0;
}