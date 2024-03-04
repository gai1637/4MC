#pragma once
#include"WorldTransform.h"
#include"ViewProjection.h"
#include"Model.h"
#include"Sprite.h"
#include<memory>
#include"stdint.h"
class Char {
public:
	virtual void Initialize()=0;
	virtual void Draw()=0;
	virtual void Update()=0;

	WorldTransform* GetworldTransform() { return worldTransform_; }
	Vector3 GetPosition() { return worldTransform_->translation_; }

protected:
	WorldTransform* worldTransform_=nullptr;
	std::unique_ptr<Sprite> sprite_=nullptr;
	std::unique_ptr<Model> model = nullptr;
	uint32_t textureHandle_ = 0;
};
