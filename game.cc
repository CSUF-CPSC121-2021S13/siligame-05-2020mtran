#include "game.h"
#include "game_element.h"
#include "opponent.h"
#include "player.h"
//project 5
void Game::CreateOpponents() {
  std::unique_ptr<Opponent> o1 = std::make_unique<Opponent>(50, 50);
  opponents.push_back(std::move(o1));
  std::unique_ptr<Opponent> o2 = std::make_unique<Opponent>(100, 50);
  opponents.push_back(std::move(o2));
  std::unique_ptr<Opponent> o3 = std::make_unique<Opponent>(150, 50);
  opponents.push_back(std::move(o3));
  std::unique_ptr<Opponent> o4 = std::make_unique<Opponent>(200, 50);
  opponents.push_back(std::move(o4));
  std::unique_ptr<Opponent> o5 = std::make_unique<Opponent>(250, 50);
  opponents.push_back(std::move(o5));
}

void Game::Init() {
  player.SetX(90);
  player.SetY(10);
}

void Game::UpdateScreen() {
  for (int i = 0; i < opponents.size(); i++) {
    opponents[i]->Draw(Screen);
  }
  for (int j = 0; j < oProjectiles.size(); j++) {
    oProjectiles[j]->Draw(Screen);
  }
  for (int k = 0; k < pProjectiles.size(); k++) {
    pProjectiles[k]->Draw(Screen);
  }
  player.Draw(Screen);
}

void Game::MoveGameElements() {  
  for (int i = 0; i < opponents.size(); i++) {    
    if (opponents[i]->GetIsActive()) {      
      opponents[i]->Move(Screen);    
      }  
      }  for (int i = 0; i < oProjectiles.size(); i++) {    
        if (oProjectiles[i]->GetIsActive()) {      
          oProjectiles[i]->Move(Screen);    
          }  
          }  for (int i = 0; i < pProjectiles.size(); i++) {    
            if (pProjectiles[i]->GetIsActive()) {      
              pProjectiles[i]->Move(Screen);    
            }  
            }
            }

void Game::FilterIntersections() {  
  for (int i = 0; i < opponents.size(); i++) {    
    if (opponents[i]->GetIsActive() && player.GetIsActive() &&        
    opponents[i]->IntersectsWith(&player)) {      
      // opponents_.erase(opponents_.begin() + i);      
      opponents[i]->SetIsActive(false);
      player.SetIsActive(false);
      lost = true;    
      }
    for (int k = 0; k < oProjectiles.size(); k++) {
      if (oProjectiles[i]->IntersectsWith(&player)) {     
      oProjectiles[i]->SetIsActive(false);
      player.SetIsActive(false);
      lost = true; 
      }
      }    
        for (int j = 0; j < pProjectiles.size(); j++) {        
          if (opponents[i]->GetIsActive() &&            
          pProjectiles[j]->GetIsActive() &&            
          pProjectiles[j]->IntersectsWith(opponents[i].get())) {          
            opponents[i]->SetIsActive(false);          
            pProjectiles[j]->SetIsActive(false);
            if (player.GetIsActive() == true) {
            score += 1;        
            }
            }      
            }      
            }
}            

void Game::Start() { Screen.ShowUntilClosed(); }

void Game::OnMouseEvent(const graphics::MouseEvent& event) {  
  if (event.GetMouseAction() == graphics::MouseAction::kMoved ||      
  event.GetMouseAction() == graphics::MouseAction::kDragged) {    
    int new_x = event.GetX() - player.GetWidth() / 2;    
    int new_y = event.GetY() - player.GetHeight() / 2;    
    int old_x = player.GetX();    
    int old_y = player.GetY();    
    player.SetX(new_x);    
    player.SetY(new_y);    
    if (player.IsOutOfBounds(Screen)) {
    player.SetX(old_x);      
    player.SetY(old_y);    
    }  
    }
    }
    void Game::OnAnimationStep() {  
      MoveGameElements();
      LaunchProjectiles();  
      FilterIntersections();
      RemoveInactive();  
      UpdateScreen();  
      Screen.Flush();
      }

    void Game::LaunchProjectiles() {
      for (int i = 0; i < opponents.size(); i++) {
        if (opponents[i]->LaunchProjectile() != nullptr) {
          std::unique_ptr<OpponentProjectile> new_OP = std::make_unique<OpponentProjectile>(opponents[i]->GetX(), 
          opponents[i]->GetY());
          oProjectiles.push_back(std::move(new_OP));
        }
      }
    }

    void Game::RemoveInactive() {
      for (int i = 0; i < opponents.size(); i++) {
        if (opponents[i]->GetIsActive() == false) {
          opponents.erase(opponents.begin());
          i -= 1;
        }
      }
      for (int i = 0; i < oProjectiles.size(); i++) {
        if (oProjectiles[i]->GetIsActive() == false) {
          oProjectiles.erase(oProjectiles.begin());
          i -= 1;
        }
      }
      for (int i = 0; i < pProjectiles.size(); i++) {
        if (pProjectiles[i]->GetIsActive() == false) {
          pProjectiles.erase(pProjectiles.begin());
          i -= 1;
        }
      }
    }
