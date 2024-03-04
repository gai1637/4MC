#pragma once
#include "IScene.h"
#include"stdint.h"
#include"TextureManager.h"
#include<memory>
#include"Sprite.h"
class TitleScene : public IScene {
public:
	void Iint() override;
	void Update() override;
	void Draw3D() override;
	void Draw2D() override;

private:
	uint32_t textureHandle_ = 0;
	std::unique_ptr<Sprite> sprite_ = nullptr;


};
