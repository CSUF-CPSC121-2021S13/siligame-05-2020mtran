#include <iostream>
#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "opponent.h"
#ifndef PLAYER_H
#define PLAYER_H
//project 5
class Player : public GameElement {
 public:
  Player() : Player(0, 0) {}
  Player(int x, int y) : GameElement(x, y, 50, 50) {}
  void Draw(graphics::Image &Screen) override;
  
  void SetX(int x) { x_ = x; }
  void SetY(int y) { y_ = y; }
  int GetX() { return x_; }
  int GetY() { return y_; }
  int GetWidth() { return kWidth_; }
  int GetHeight() { return kHeight_; }
  void Move(const graphics::Image &image) override;
 private:
  const int kWidth_ = 50;
  const int kHeight_ = 50;
};

class PlayerProjectile : public GameElement {
 public:
  PlayerProjectile() : PlayerProjectile(0, 0) {}
  PlayerProjectile(int x, int y) : GameElement(x, y, 5, 5) {}
  void Draw(graphics::Image &Screen);
  
  void SetX(int x) { x_ = x; }
  void SetY(int y) { y_ = y; }
  int GetX() { return x_; }
  int GetY() { return y_; }
  int GetWidth() { return kWidth_; }
  int GetHeight() { return kHeight_; }
  void Move(const graphics::Image &Screen);
 private:
  const int kWidth_ = 5;
  const int kHeight_ = 5;
};

#endif
