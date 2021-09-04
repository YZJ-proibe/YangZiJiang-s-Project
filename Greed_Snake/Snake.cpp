#include "Snake.h"

#include <iostream>

void Snake_Nature::SnakeMove() {
  int NewPosition_X;
  int NewPosition_Y;
  auto SnakeHead = this->SnakePosition.begin();
  int NewDirection = SnakeHead->SnakeDirection;
  switch (SnakeHead->SnakeDirection) {
    case UP:
      NewPosition_X = SnakeHead->SnakeNodePosition_X - 1;
      NewPosition_Y = SnakeHead->SnakeNodePosition_Y;
      break;
    case DOWN:
      NewPosition_X = SnakeHead->SnakeNodePosition_X + 1;
      NewPosition_Y = SnakeHead->SnakeNodePosition_Y;
      break;
    case LEFT:
      NewPosition_X = SnakeHead->SnakeNodePosition_X;
      NewPosition_Y = SnakeHead->SnakeNodePosition_Y - 1;
      break;
    case RIGHT:
      NewPosition_X = SnakeHead->SnakeNodePosition_X;
      NewPosition_Y = SnakeHead->SnakeNodePosition_Y + 1;
      break;
    default:
      break;
  }
  auto SnakeTail = --(this->SnakePosition.end());
  this->SnakePosition.erase(SnakeTail);
  Snake_Node NewSnakeHead(NewPosition_X, NewPosition_Y, NewDirection);
  this->SnakePosition.insert(SnakePosition.begin(), NewSnakeHead);
}

void Snake_Nature::SnakeMoveUp() {
  this->SnakePosition.begin()->SnakeDirection = UP;
  this->SnakeMove();
}

void Snake_Nature::SnakeMoveDown() {
  this->SnakePosition.begin()->SnakeDirection = DOWN;
  this->SnakeMove();
}

void Snake_Nature::SnakeMoveLeft() {
  this->SnakePosition.begin()->SnakeDirection = LEFT;
  this->SnakeMove();
}

void Snake_Nature::SnakeMoveRight() {
  this->SnakePosition.begin()->SnakeDirection = RIGHT;
  this->SnakeMove();
}

void Snake_Nature::SnakeControlMove(int SnakeControlMoveDirection) {
  switch (SnakeControlMoveDirection) {
    case UP:
      this->SnakeMoveUp();
      break;
    case DOWN:
      this->SnakeMoveDown();
      break;
    case LEFT:
      this->SnakeMoveLeft();
      break;
    case RIGHT:
      this->SnakeMoveRight();
      break;
    default:
      break;
  }
}
void Snake_Nature::PrintNodePosition() {
  for (auto x : SnakePosition) {
    std::cout << '(' << x.SnakeNodePosition_X << ',' << x.SnakeNodePosition_Y
              << ')' << x.SnakeDirection << std::endl;
  }
  std::cout << std::endl;
}