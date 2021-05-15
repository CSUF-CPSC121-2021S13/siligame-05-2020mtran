#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "opponent.h"
#include "player.h"
//project 5
#ifndef GAME_H
#define GAME_H

class Game : public graphics::AnimationEventListener, public graphics::MouseEventListener, public GameElement {
 public:
  Game() : Screen(800, 600) {}
  Game(int width, int height) : Screen(width, height) {}
  graphics::Image &GetGameScreen() { return Screen; }
  std::vector<std::unique_ptr<Opponent>> &GetOpponents() { return opponents; }
  std::vector<std::unique_ptr<OpponentProjectile>> &GetOpponentProjectiles() {
    return oProjectiles;
  }
  std::vector<std::unique_ptr<PlayerProjectile>> &GetPlayerProjectiles() { return pProjectiles; }
  Player &GetPlayer() { return player; }
  int GetScore() const { return score; }
  bool HasLost() const { return lost; }
  void Init();
  void UpdateScreen();
  void CreateOpponents();
  void MoveGameElements();  
  void FilterIntersections();  
  void Start();
  void OnMouseEvent(const graphics::MouseEvent& event) override;  
  void OnAnimationStep() override;
  void LaunchProjectiles();
  void RemoveInactive();
  void Draw(graphics::Image &Screen) override;
  void Move(const graphics::Image &Screen) override;
 private:
  graphics::Image Screen;
  std::vector<std::unique_ptr<Opponent>> opponents;
  std::vector<std::unique_ptr<OpponentProjectile>> oProjectiles;
  std::vector<std::unique_ptr<PlayerProjectile>> pProjectiles;
  Player player;
  int width_ = 800;
  int height_ = 600;
  int score = 0;
  bool lost = false; 
};

#endif
