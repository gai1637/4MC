#pragma once
#include "IScene.h"
class GameOverScene : public IScene {
	void Iint() override;
	void Update() override;
	void Draw3D() override;
	void Draw2D() override;
};
