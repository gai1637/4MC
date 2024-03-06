#include "StageScene.h"

void StageScene::Iint() { 
	viewProjection_.Initialize();
	player_ = std::make_unique<Player>();
	player_->Initialize();
	}

void StageScene::Update() { player_->Update(); }

void StageScene::Draw3D() { player_->Draw3D(viewProjection_); }

void StageScene::Draw2D() { player_->Draw(); }

StageScene::StageScene() { }
