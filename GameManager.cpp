#include "GameManager.h"

GameManager::GameManager() {
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();
	
	sceneArr_[GAMEOVER] = std::make_unique<GameOverScene>();
	
	currentSceneNo_ = TITLE;

	sceneArr_[currentSceneNo_]->Iint();

}



void GameManager::Update() { 
	prevSceneNo_ = currentSceneNo_;
	currentSceneNo_ = sceneArr_[currentSceneNo_]->GetScene();

	if (prevSceneNo_ != currentSceneNo_) {
		sceneArr_[currentSceneNo_]->Iint();
	}

	sceneArr_[currentSceneNo_]->Update();

}

void GameManager::Draw3D() {}

void GameManager::Draw2D() { sceneArr_[currentSceneNo_]->Draw2D(); }
