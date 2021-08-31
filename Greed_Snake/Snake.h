#include <iostream>
#include <vector>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
class Snake_Node;
class Snake_Nature;

class Snake_Node {
 public:
  int SnakeNodePosition_X;
  int SnakeNodePosition_Y;
  int SnakeDirection;
  Snake_Node(int SNPX, int SNPY, int SND)
      : SnakeNodePosition_X(SNPX),
        SnakeNodePosition_Y(SNPY),
        SnakeDirection(SND) {}
  ~Snake_Node() {}
};

class Snake_Nature : public Snake_Node {
 public:
  Snake_Nature(int SNPX, int SNPY, int SND)
      : Snake_Node(SNPX, SNPY, SND), SnakeHeadSize(1), SnakeBodySize(3) {
    Snake_Node SnakeNode(SNPX, SNPY, SND);
    SnakePosition.push_back(SnakeNode);
  }
  ~Snake_Nature() {}
  void SnakeMoveUp();
  void SnakeMoveDown();
  void SnakeMoveLeft();
  void SnakeMoveRight();
  void SnakeMove();
  void SnakeEatFood();

 private:
  int SnakeHeadSize;
  int SnakeBodySize;
  std::vector<Snake_Node> SnakePosition;
};
