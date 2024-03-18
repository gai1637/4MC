#include "StageScene.h"
#include"Map.h"
void StageScene::Iint() { 
	viewProjection_.Initialize();
	player_ = std::make_unique<Player>();
	player_->Initialize();
	stage_ = 0;
	Map_[0] = std::make_unique<Map1>();
	Map_[0]->Initialize();
	colisionManager_ = std::make_unique<ColisionManager>();
	}

void StageScene::Update() { 
	
	
	player_->Update(); 

	player_->PlayerMove();

	CheckAllColisions();
}

void StageScene::Draw3D() { player_->Draw3D(viewProjection_); }

void StageScene::Draw2D() {
	player_->Draw();
	Map_[stage_]->Draw();
}

void StageScene::CheckAllColisions() { 
	colisionManager_->Reset();
	colisionManager_->AddColider(player_.get());
	for (const std::unique_ptr<Map>&map : Map_[stage_]->GetMapList()) {
		colisionManager_->AddColider(map.get());
	}
	colisionManager_->CheckAllColisions();
}

