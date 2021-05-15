#include <iostream>
#include "cpputils/graphics/image.h"
//project 5
#ifndef GAMEELEMENT_H
#define GAMEELEMENT_H

class GameElement {
 public:
  GameElement() {
    x_ = 0;
    y_ = 0;
    width_ = 50;
    height_ = 50;
  }
  GameElement(int x, int y, int width, int height)
      : x_(x), y_(y), width_(width), height_(height) {}
  virtual void Draw(graphics::Image &) = 0;
  void SetX(int x) { x_ = x; }
  void SetY(int y) { y_ = y; }
  int GetX() const { return x_; }
  int GetY() const { return y_; }
  int GetWidth() const { return width_; }
  int GetHeight() const { return height_; }
  void SetIsActive(bool isactive) {
      is_active = isactive;
  }
  bool GetIsActive() {
      return is_active;
  }
  virtual void Move(const graphics::Image &Screen) = 0;
  bool IntersectsWith(GameElement* game_element);
  bool IsOutOfBounds(const graphics::Image &Screen);
 protected:
  int x_;
  int y_;
  int width_;
  int height_;

  private:
    bool is_active = true;
};

#endif
