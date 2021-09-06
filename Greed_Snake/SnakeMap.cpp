#include "SnakeMap.h"
void SnakeCreateMap::SnakeCreateMapObstacle(Snake_Nature* Snake,
                                            CreateFood* Food) {
  for (int i = 0; i < this->MapObstacleSize; i++) {
    int ObstaclePosition_X = rand() % this->MapHeight;
    ObstaclePosition_X =
        ObstaclePosition_X == 0 ? ObstaclePosition_X + 1 : ObstaclePosition_X;
    int ObstaclePosition_Y = rand() % this->MapWidth;
    ObstaclePosition_Y =
        ObstaclePosition_Y == 0 ? ObstaclePosition_Y + 1 : ObstaclePosition_Y;
    while (Snake->SnakeMapvis[ObstaclePosition_X][ObstaclePosition_Y] ||
           this->MapObstaclePosition[ObstaclePosition_X][ObstaclePosition_Y] ||
           Food->FoodPosition[ObstaclePosition_X][ObstaclePosition_Y]) {
      ObstaclePosition_X = rand() % WorldHeight;
      ObstaclePosition_X =
          ObstaclePosition_X == 0 ? ObstaclePosition_X + 1 : ObstaclePosition_X;

      ObstaclePosition_Y = rand() % WorldWidth;
      ObstaclePosition_Y =
          ObstaclePosition_Y == 0 ? ObstaclePosition_Y + 1 : ObstaclePosition_Y;
    }
    this->MapObstaclePosition[ObstaclePosition_X][ObstaclePosition_Y] = 1;
    this->MapObstacleList.push_back(
        std::make_pair(ObstaclePosition_X, ObstaclePosition_Y));
  }
}

bool SnakeCreateMap::SnakeIsGameOver(Snake_Nature* Snake) {
  int SnakeHead_X = Snake->SnakeHead_X;
  int SnakeHead_Y = Snake->SnakeHead_Y;
  if (this->MapObstaclePosition[SnakeHead_X][SnakeHead_Y]) {
    std::cout << "Game Over!" << std::endl;
    return false;
  }
  return true;
}

void SnakeCreateMap::PrObstaclePosition() {
  for (auto it : this->MapObstacleList) {
    std::cout << "Obstacle: " << it.first << ' ' << it.second << std::endl;
  }
}