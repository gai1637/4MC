#pragma once
#include "IScene.h"
class StageScene : public IScene {
	void Iint() override;
	void Update() override;
	void Draw3D() override;
	void Draw2D() override;
};
