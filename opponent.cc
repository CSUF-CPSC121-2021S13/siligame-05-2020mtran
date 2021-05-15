#include "opponent.h"
#include "cpputils/graphics/image.h"
//project 5
// Draw opponent
void Opponent::Draw(graphics::Image &Screen) {
  Screen.DrawRectangle(x_, y_, 50, 50, 158, 0, 158);
}
// Draw opponent projectile
void OpponentProjectile::Draw(graphics::Image &Screen) {
  Screen.DrawRectangle(x_, y_, 5, 5, 158, 0, 158);
}

void Opponent::Move(const graphics::Image &Screen) {
  if (!IsOutOfBounds(Screen)) {
    for (int i = 0; i < 1; i++) {
    SetX(GetX() + 5);
    
  }
  for (int j = 0; j < 1; j++) {
    SetY(GetY() + 5);
    
  } } else {
    SetIsActive(false);
  }
}

void OpponentProjectile::Move(const graphics::Image &Screen) {
  if (IsOutOfBounds(Screen)) {
    SetIsActive(false);
  }
  SetY(GetY() - 3);
}

std::unique_ptr<OpponentProjectile> Opponent::LaunchProjectile() {
  counter_ += 1;
  if (counter_ % 10 == 0) {
    std::unique_ptr<OpponentProjectile> OP_Object = std::make_unique<OpponentProjectile>(GetX(), GetY());
    return std::move(OP_Object); 
  } else {
    return nullptr;
  }
}
