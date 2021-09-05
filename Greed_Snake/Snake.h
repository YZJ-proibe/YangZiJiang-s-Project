#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define FoodCell 4
#define ObstacleCell 5
#define NormalCell 6
#define WorldWidth 100
#define WorldHeight 100
class Snake_Node;
class Snake_Nature;

class Snake_Node {
 public:
  int SnakeNodePosition_X;
  int SnakeNodePosition_Y;
  int SnakeDirectionOrStyle;
  Snake_Node()
      : SnakeNodePosition_X(1), SnakeNodePosition_Y(1), SnakeDirectionOrStyle(NormalCell) {}
  Snake_Node(int SNPX, int SNPY, int SND)
      : SnakeNodePosition_X(SNPX),
        SnakeNodePosition_Y(SNPY),
        SnakeDirectionOrStyle(SND) {}
  ~Snake_Node() {}
};

class Snake_Nature : public Snake_Node {
 public:
  std::unordered_map<int, std::unordered_map<int, int> > SnakeMapvis;
  Snake_Nature(int SNPX = 1, int SNPY = 1, int SND = 0);
  ~Snake_Nature() { SnakeMapvis.clear(); }
  void SnakeMoveUp();
  void SnakeMoveDown();
  void SnakeMoveLeft();
  void SnakeMoveRight();
  void SnakeMove();
  void SnakeControlMove(int SnakeControlMoveDirection);
  bool SnakeIsForbidControlDirection(int SnakeControlMoveDirection);
  bool SnakeIsCrashSelf();
  void PrintNodePosition();
  void SnakeEatFood();

 private:
  int SnakeHeadSize = 1;
  int SnakeBodySize = 3;
  std::list<Snake_Node> SnakePosition;
  //std::unordered_map<int, std::unordered_map<int, int> > SnakeMapvis;
};
