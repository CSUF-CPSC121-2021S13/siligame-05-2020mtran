#include <iostream>
#include "cpputils/graphics/image.h"
#include "game_element.h"
#ifndef OPPONENT_H
#define OPPONENT_H
//project 5

class OpponentProjectile : public GameElement {
 public:
  OpponentProjectile() : OpponentProjectile(0, 0) {}
  OpponentProjectile(int x, int y) : GameElement(x, y, 5, 5) {}
  void Draw(graphics::Image &Screen) override;
  void SetX(int x) { x_ = x; }
  void SetY(int y) { y_ = y; }
  int GetX() const { return x_; }
  int GetY() const { return y_; }
  int GetWidth() const { return kWidth_; }
  int GetHeight() const { return kHeight_; }
  void Move(const graphics::Image &Screen) override;
 private:
  const int kWidth_ = 5;
  const int kHeight_ = 5;
};

class Opponent : public GameElement {
 public:
  Opponent() : Opponent(0, 0) {}
  Opponent(int x, int y) : GameElement(x, y, 50, 50) {}
  void Draw(graphics::Image &Screen) override;
  void SetX(int x) { x_ = x; }
  void SetY(int y) { y_ = y; }
  int GetX() const { return x_; }
  int GetY() const { return y_; }
  int GetWidth() const { return kWidth_; }
  int GetHeight() const { return kHeight_; }
  void Move(const graphics::Image &Screen) override;
  std::unique_ptr<OpponentProjectile> LaunchProjectile();
 private:
  const int kWidth_ = 50;
  const int kHeight_ = 50;
  int counter_ = 0;
};

#endif
