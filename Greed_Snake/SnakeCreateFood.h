#include "Snake.h"
class CreateFood {
 public:
  CreateFood(int createfoodnums) : CreateFoodNums(createfoodnums) {}
  ~CreateFood() { FoodPosition.clear(); }
  void CreateSrandFood(Snake_Nature *Snake);
  void PrFoodPosition();

 private:
  int CreateFoodNums;
  std::vector<std::pair<int, int>> FoodList;
  std::unordered_map<int, std::unordered_map<int, int>> FoodPosition;
};