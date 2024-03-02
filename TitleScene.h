#pragma once
#include "IScene.h"
class TitleScene : public IScene {
public:
	void Iint() override;
	void Update() override;
	void Draw3D() override;
	void Draw2D() override;



};
