#include "SnakeCreateFood.h"
void CreateFood::CreateSrandFood(Snake_Nature* Snake) {
  for (int i = 0; i < this->CreateFoodNums; i++) {
    int FoodPosition_X = rand() % WorldHeight;
    FoodPosition_X=FoodPosition_X == 0 ? FoodPosition_X + 1 : FoodPosition_X;
    int FoodPosition_Y = rand() % WorldWidth;
    FoodPosition_Y=FoodPosition_Y == 0 ? FoodPosition_Y + 1 : FoodPosition_Y;
    while (Snake->SnakeMapvis[FoodPosition_X][FoodPosition_Y] ||
           this->FoodPosition[FoodPosition_X][FoodPosition_Y]) {
      FoodPosition_X = rand() % WorldHeight;
      FoodPosition_X=FoodPosition_X == 0 ? FoodPosition_X + 1 : FoodPosition_X;

      FoodPosition_Y = rand() % WorldWidth;
      FoodPosition_Y=FoodPosition_Y == 0 ? FoodPosition_Y + 1 : FoodPosition_Y;
    }
    this->FoodPosition[FoodPosition_X][FoodPosition_Y] = 1;
    FoodList.push_back(std::make_pair(FoodPosition_X, FoodPosition_Y));
  }
}

void CreateFood::IsCheckFood(Snake_Nature* Snake,
                             SnakeTraceDeleteTailNode* TraceTailNode) {
  if (this->FoodPosition[Snake->SnakeHead_X][Snake->SnakeHead_Y]) {
    FoodPosition[Snake->SnakeHead_X][Snake->SnakeHead_Y] = 0;
    Snake->SnakeInsertNode(TraceTailNode);
  }
}

void CreateFood::PrFoodPosition() {
  for (auto x : FoodList) {
    std::cout << "Food" << ' ' << x.first << ' ' << x.second << std::endl;
  }
}