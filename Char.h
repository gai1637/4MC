#pragma once
#include"WorldTransform.h"
#include"ViewProjection.h"
#include"Model.h"
#include"Sprite.h"
#include<memory>
#include"stdint.h"
#include"Colider2D.h"
class Char : public Colider2D {
public:

	virtual void Initialize()=0;
	virtual void Draw()=0;
	virtual void Update()=0;

	const WorldTransform& GetworldTransform() { return worldTransform_; }
	const Vector3 GetPosition() { return worldTransform_.translation_; }

	float GetLeftPosition() const override;
	float GetRightPosition() const override;
	float GetDownPosition() const override;
	float GetUpPosition() const override;

protected:
	WorldTransform worldTransform_;
	std::unique_ptr<Sprite> sprite_=nullptr;
	std::unique_ptr<Model> model = nullptr;
	uint32_t textureHandle_ = 0;
	/*float size = 64.f;*/
};
