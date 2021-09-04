#include <iostream>
#include <list>
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
    Snake_Node SnakeHead(SNPX, SNPY, SND);
    Snake_Node SnakeBodyFirstNode(SNPX + 1, SNPY, SND);
    Snake_Node SnakeBodySecondNode(SNPX + 2, SNPY, SND);
    Snake_Node SnakeBodyThirdNode(SNPX + 3, SNPY, SND);
    SnakePosition.push_back(SnakeHead);
    SnakePosition.push_back(SnakeBodyFirstNode);
    SnakePosition.push_back(SnakeBodySecondNode);
    SnakePosition.push_back(SnakeBodyThirdNode);
  }

  ~Snake_Nature() {}
  void SnakeMoveUp();
  void SnakeMoveDown();
  void SnakeMoveLeft();
  void SnakeMoveRight();
  void SnakeMove();
  void SnakeControlMove(int SnakeControlMoveDirection);
  void PrintNodePosition();
  void SnakeEatFood();

 private:
  int SnakeHeadSize;
  int SnakeBodySize;
  std::list<Snake_Node> SnakePosition;
};
