#include "SnakeCreateFood.h"
#ifndef _RELEASEMEMORY_H_
#define _RELEASEMEMORY_H_
class CleanMemory;
class CleanMemory {
 public:
  CleanMemory() {}
  ~CleanMemory() {}
  void CleanclassMemory(Snake_Nature* Snake,
                        SnakeTraceDeleteTailNode* TraceNodeTail,
                        CreateFood* FoodNode);
};
#endif