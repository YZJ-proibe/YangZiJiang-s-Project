#include "ReleaseMemory.h"
void CleanMemory::CleanclassMemory(Snake_Nature* Snake,
                                   SnakeTraceDeleteTailNode* TraceNodeTail,
                                   CreateFood* FoodNode) {
  delete Snake;
  delete TraceNodeTail;
  delete FoodNode;
}