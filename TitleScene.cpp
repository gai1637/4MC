#include "TitleScene.h"

void TitleScene::Iint() { 
	textureHandle_ = TextureManager::Load("Game Title.png");
	sprite_.reset(Sprite::Create(textureHandle_, {0,0}));


}

void TitleScene::Update() {}

void TitleScene::Draw3D() {}

void TitleScene::Draw2D() { sprite_->Draw(); }


