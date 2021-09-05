#include "SnakeCreateFood.h"
void CreateFood::CreateSrandFood(Snake_Nature *Snake) {
  for (int i = 0; i < this->CreateFoodNums; i++) {
    int FoodPosition_X = rand() % WorldHeight;
    int FoodPosition_Y = rand() % WorldWidth;
    while (Snake->SnakeMapvis[FoodPosition_X][FoodPosition_Y] ||
           this->FoodPosition[FoodPosition_X][FoodPosition_Y]) {
      FoodPosition_X = rand() % WorldHeight;
      FoodPosition_Y = rand() % WorldWidth;
    }
    this->FoodPosition[FoodPosition_X][FoodPosition_Y] = 1;
    FoodList.push_back(std::make_pair(FoodPosition_X, FoodPosition_Y));
  }
}
void CreateFood::PrFoodPosition() {
  for (auto x : FoodList) {
    std::cout << "Food" << ' ' << x.first << ' ' << x.second << std::endl;
  }
}