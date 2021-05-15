#include <iostream>
#include "game.h"
#include "game_element.h"
#include "opponent.h"
#include "player.h"
//project 5
int main() {
  Game game;
  game.Init();
  game.UpdateScreen();
  game.Start();
}
