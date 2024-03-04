#pragma once
#include "IScene.h"
#include "ViewProjection.h"
#include"FollowCamera.h"
#include<memory>
class StageScene : public IScene {
public:
	void Iint() override;
	void Update() override;
	void Draw3D() override;
	void Draw2D() override;

private:

};
