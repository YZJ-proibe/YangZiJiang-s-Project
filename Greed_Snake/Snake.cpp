#include "Snake.h"

#include <iostream>

Snake_Nature::Snake_Nature(int SNPX, int SNPY, int SND) {
  Snake_Node SnakeHead(SNPX, SNPY, SND);
  Snake_Node SnakeBodyFirstNode(SNPX + 1, SNPY, SND);
  Snake_Node SnakeBodySecondNode(SNPX + 2, SNPY, SND);
  Snake_Node SnakeBodyThirdNode(SNPX + 3, SNPY, SND);
  Snake_Node SnakeBodyFourthNode(SNPX + 4, SNPY, SND);
  SnakePosition.push_back(SnakeHead);
  SnakePosition.push_back(SnakeBodyFirstNode);
  SnakePosition.push_back(SnakeBodySecondNode);
  SnakePosition.push_back(SnakeBodyThirdNode);
  SnakePosition.push_back(SnakeBodyFourthNode);
  SnakeMapvis[SNPX][SNPY] = 1;
  SnakeMapvis[SNPX + 1][SNPY] = 1;
  SnakeMapvis[SNPX + 2][SNPY] = 1;
  SnakeMapvis[SNPX + 3][SNPY] = 1;
  SnakeMapvis[SNPX + 4][SNPY] = 1;
}

void Snake_Nature::SnakeMove() {
  int NewPosition_X;
  int NewPosition_Y;
  auto SnakeHead = this->SnakePosition.begin();
  int NewDirection = SnakeHead->SnakeDirectionOrStyle;
  switch (SnakeHead->SnakeDirectionOrStyle) {
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
  this->SnakeMapvis[SnakeTail->SnakeNodePosition_X]
                   [SnakeTail->SnakeNodePosition_Y]--;
  this->SnakePosition.erase(SnakeTail);
  this->SnakeMapvis[NewPosition_X][NewPosition_Y]++;
  Snake_Node NewSnakeHead(NewPosition_X, NewPosition_Y, NewDirection);
  this->SnakePosition.insert(SnakePosition.begin(), NewSnakeHead);
}

void Snake_Nature::SnakeMoveUp() {
  if (SnakeIsForbidControlDirection(UP)) {
    return;
  }

  this->SnakePosition.begin()->SnakeDirectionOrStyle = UP;
  this->SnakeMove();
}

void Snake_Nature::SnakeMoveDown() {
  if (SnakeIsForbidControlDirection(DOWN)) {
    return;
  }

  this->SnakePosition.begin()->SnakeDirectionOrStyle = DOWN;
  this->SnakeMove();
}

void Snake_Nature::SnakeMoveLeft() {
  if (SnakeIsForbidControlDirection(LEFT)) {
    return;
  }

  this->SnakePosition.begin()->SnakeDirectionOrStyle = LEFT;
  this->SnakeMove();
}

void Snake_Nature::SnakeMoveRight() {
  if (SnakeIsForbidControlDirection(RIGHT)) {
    return;
  }

  this->SnakePosition.begin()->SnakeDirectionOrStyle = RIGHT;
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
              << ')' << x.SnakeDirectionOrStyle << std::endl;
  }
  std::cout << std::endl;
}

bool Snake_Nature::SnakeIsForbidControlDirection(
    int SnakeControlMoveDirection) {
  auto Direction = this->SnakePosition.begin()->SnakeDirectionOrStyle;
  if ((Direction == UP && SnakeControlMoveDirection == DOWN) ||
      (Direction == DOWN && SnakeControlMoveDirection == UP)) {
    return true;
  }

  if ((Direction == LEFT && SnakeControlMoveDirection == RIGHT) ||
      (Direction == RIGHT && SnakeControlMoveDirection == LEFT)) {
    return true;
  }
  return false;
}

bool Snake_Nature::SnakeIsCrashSelf() {
  int SnakeHead_X = this->SnakePosition.begin()->SnakeNodePosition_X;
  int SnakeHead_Y = this->SnakePosition.begin()->SnakeNodePosition_Y;
  auto SnakeHeadVisTimes = SnakeMapvis[SnakeHead_X][SnakeHead_Y];
  return SnakeHeadVisTimes > 1;
}