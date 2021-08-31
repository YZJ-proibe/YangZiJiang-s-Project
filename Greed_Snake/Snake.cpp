#include "Snake.h"

#include <iostream>

void Snake_Nature::SnakeMove() {
  int NewPosition_X;
  int NewPosition_Y;
  int NewDirection = this->SnakePosition[0].SnakeDirection;
  switch (this->SnakePosition[0].SnakeDirection) {
    case UP:
      NewPosition_X = SnakePosition[0].SnakeNodePosition_X - 1;
      NewPosition_Y = SnakePosition[0].SnakeNodePosition_Y;
      break;
    case DOWN:
      NewPosition_X = SnakePosition[0].SnakeNodePosition_X + 1;
      NewPosition_Y = SnakePosition[0].SnakeNodePosition_Y;
      break;
    case LEFT:
      NewPosition_X = SnakePosition[0].SnakeNodePosition_X;
      NewPosition_Y = SnakePosition[0].SnakeNodePosition_Y - 1;
      break;
    case RIGHT:
      NewPosition_X = SnakePosition[0].SnakeNodePosition_X;
      NewPosition_Y = SnakePosition[0].SnakeNodePosition_Y + 1;
      break;
    default:
      break;
  }
  int i = SnakePosition.size() - 1;
  for (; i - 1 >= 0; i--) {
    SnakePosition[i] = SnakePosition[i - 1];
  }
  SnakePosition[0].SnakeDirection = NewDirection;
  SnakePosition[0].SnakeNodePosition_X = NewPosition_X;
  SnakePosition[0].SnakeNodePosition_Y = NewPosition_Y;
}

void Snake_Nature::SnakeMoveUp() {
  this->SnakePosition[0].SnakeDirection = UP;
  this->SnakeMove();
}

void Snake_Nature::SnakeMoveDown() {
  this->SnakePosition[0].SnakeDirection = DOWN;
  this->SnakeMove();
}

void Snake_Nature::SnakeMoveLeft() {
  this->SnakePosition[0].SnakeDirection = LEFT;
  this->SnakeMove();
}

void Snake_Nature::SnakeMoveRight() {
  this->SnakePosition[0].SnakeDirection = RIGHT;
  this->SnakeMove();
}