#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define WorldWidth 100
#define WorldHeight 100


#ifndef _SNAKE_H_
#define _SNAKE_H_

class Snake_Node;
class Snake_Nature;
class SnakeTraceDeleteTailNode;

class Snake_Node {
 public:
  int SnakeNodePosition_X;
  int SnakeNodePosition_Y;
  int SnakeDirection;
  Snake_Node()
      : SnakeNodePosition_X(1), SnakeNodePosition_Y(1), SnakeDirection(UP) {}
  Snake_Node(int SNPX, int SNPY, int SND)
      : SnakeNodePosition_X(SNPX),
        SnakeNodePosition_Y(SNPY),
        SnakeDirection(SND) {}
  ~Snake_Node() {}
};

class Snake_Nature : public Snake_Node {
 public:
  std::unordered_map<int, std::unordered_map<int, int> > SnakeMapvis;
  int SnakeHead_X;
  int SnakeHead_Y;

  Snake_Nature(int SNPX = 1, int SNPY = 1, int SND = 0);
  ~Snake_Nature() { SnakeMapvis.clear(); }
  void SnakeMoveUp(SnakeTraceDeleteTailNode* TraceTailNode);
  void SnakeMoveDown(SnakeTraceDeleteTailNode* TraceTailNode);
  void SnakeMoveLeft(SnakeTraceDeleteTailNode* TraceTailNode);
  void SnakeMoveRight(SnakeTraceDeleteTailNode* TraceTailNode);
  void SnakeMove(SnakeTraceDeleteTailNode* TraceTailNode);
  void SnakeControlMove(int SnakeControlMoveDirection,
                        SnakeTraceDeleteTailNode* TraceTailNode);
  bool SnakeIsForbidControlDirection(int SnakeControlMoveDirection);
  bool SnakeIsCrashSelf();
  void PrintNodePosition();
  void SnakeInsertNode(SnakeTraceDeleteTailNode* TraceTailNode);

 private:
  int SnakeHeadSize = 1;
  int SnakeBodySize = 4;
  std::list<Snake_Node> SnakePosition;
};

class SnakeTraceDeleteTailNode {
 public:
  SnakeTraceDeleteTailNode(int tailnode_x = 0, int tailnode_y = 0,
                           int tailnodedirection = 0)
      : TraceDeleteTailNode_X(tailnode_x),
        TraceDeleteTailNode_Y(tailnode_y),
        TraceDeleteTailNodeDirection(tailnodedirection) {}
  ~SnakeTraceDeleteTailNode() {}
  void SnakeUpdateDeleteTailNode(int TDTN_X, int TDTN_Y, int TDTND);
  int TraceDeleteTailNode_X;
  int TraceDeleteTailNode_Y;
  int TraceDeleteTailNodeDirection;
};
#endif