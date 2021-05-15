#include "game_element.h"
#include "cpputils/graphics/image.h"
//project 5
void GameElement::Draw(graphics::Image &Screen) {
  Screen.DrawRectangle(x_, y_, 5, 5, 0, 0, 0);
}

bool GameElement::IntersectsWith(GameElement* game_element) {
  if (game_element->GetX() + game_element->GetWidth() >=
          x_ ||  // right side of object intersecting with left side of player
      game_element->GetX() <= x_ + width_ ||  // left side of object intersecting
                                           // with right side of player
      game_element->GetY() + game_element->GetHeight() <=
          y_ ||  // bottom of object intersecting with top of player
      game_element->GetY() >=
          y_ + height_) {  // top of object intersecting with bottom of player
    return true;
  } else {
    return false;
  }
}

bool GameElement::IsOutOfBounds(const graphics::Image &Screen) {
  if (x_ > Screen.GetWidth() || x_ < 0
  || y_ > Screen.GetHeight() || y_ < 0) {
    return true;
  } else {
    return false;
  }
}
