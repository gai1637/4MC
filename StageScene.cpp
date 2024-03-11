#include "StageScene.h"
#include"Map.h"
void StageScene::Iint() { 
	viewProjection_.Initialize();
	player_ = std::make_unique<Player>();
	player_->Initialize();
	stage_ = 0;
	Map[0] = std::make_unique<Map1>();
	Map[0]->Initialize();
	
	}

void StageScene::Update() { 
	
	
	player_->Update(); 

	player_->PlayerMove();


}

void StageScene::Draw3D() { player_->Draw3D(viewProjection_); }

void StageScene::Draw2D() {
	player_->Draw();
	Map[stage_]->Draw();
}

