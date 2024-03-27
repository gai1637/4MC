#include "StageScene.h"
#include"Map.h"
void StageScene::Iint() { 
	viewProjection_.Initialize();
	player_ = std::make_unique<Player>();
	player_->Initialize();
	stage_ = 0;
	Map_[stage_] = std::make_unique<Map1>();
	Map_[stage_]->Initialize();
	colisionManager_ = std::make_unique<ColisionManager>();
	maps_ = Map_[stage_]->GetMapList();
	}

void StageScene::Update() { 
	
	
	player_->Update(); 

	CheckAllColisions();

	player_->PlayerMove();
}

void StageScene::Draw3D() { player_->Draw3D(viewProjection_); }

void StageScene::Draw2D() {
	player_->Draw();
	/*Map_[stage_]->Draw();*/
	for (const std::unique_ptr<Map>&map : maps_) {
		map->Draw();
	}
}

void StageScene::CheckAllColisions() { 
	colisionManager_->Reset();
	colisionManager_->AddColider(player_.get());
	for (const std::unique_ptr<Map>&map : maps_) {
		colisionManager_->AddColider(map.get());
	}
	colisionManager_->CheckAllColisions();
}

