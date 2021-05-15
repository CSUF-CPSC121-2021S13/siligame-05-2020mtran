#include "player.h"
#include "cpputils/graphics/image.h"
//project 5
// Draw player
void Player::Draw(graphics::Image &Screen) {
  Screen.DrawRectangle(x_, y_, 50, 50, 255, 0, 0);
}
// Draw player projectile
void PlayerProjectile::Draw(graphics::Image &Screen) {
  Screen.DrawRectangle(x_, y_, 5, 5, 255, 0, 0);
}

void Player::Move(const graphics::Image &Screen) {}

void PlayerProjectile::Move(const graphics::Image &Screen) {
  SetY(GetY() - 3);
  if (IsOutOfBounds(Screen)) {
    SetIsActive(false);
  }
}
