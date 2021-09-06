#include "Snake.h"
#ifndef _SNAKECREATEFOOT_H_
#define _SNAKECREATEFOOT_H_

class CreateFood;
class CreateFood {
 public:
  std::unordered_map<int, std::unordered_map<int, int>> FoodPosition;
  CreateFood(int createfoodnums) : CreateFoodNums(createfoodnums) {}
  ~CreateFood() { FoodPosition.clear(); }
  void CreateSrandFood(Snake_Nature *Snake);
  void IsCheckFood(Snake_Nature *Snake,
                   SnakeTraceDeleteTailNode *TraceTailNode);
  void PrFoodPosition();

 private:
  int CreateFoodNums;
  std::vector<std::pair<int, int>> FoodList;
};
#endif