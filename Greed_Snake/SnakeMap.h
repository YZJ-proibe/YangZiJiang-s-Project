#include "SnakeCreateFood.h"
#ifndef _SNAKEMAP_H_
#define _SNAKEMAP_H_
class SnakeCreateMap;
class SnakeCreateMap {
 public:
  std::unordered_map<int, std::unordered_map<int, int> > MapObstaclePosition;
  SnakeCreateMap()
      : MapHeight(WorldHeight), MapWidth(WorldWidth), MapObstacleSize(10) {}
  SnakeCreateMap(int mapheight, int mapwidth, int mapobstaclesize)
      : MapHeight(mapheight),
        MapWidth(mapwidth),
        MapObstacleSize(mapobstaclesize) {}
  void SnakeCreateMapObstacle(Snake_Nature* Snake, CreateFood* Food);
  void PrObstaclePosition();
  bool SnakeIsGameOver(Snake_Nature* Snake);

 private:
  int MapHeight = WorldHeight;
  int MapWidth = WorldWidth;
  int MapObstacleSize = 10;
  std::vector<std::pair<int, int> > MapObstacleList;
};
#endif