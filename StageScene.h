#pragma once
#include "IScene.h"
#include "ViewProjection.h"
#include"FollowCamera.h"
#include<memory>
#include"Player.h"
#include"DefaltMap.h"
class StageScene : public IScene {
public:
	void Iint() override;
	void Update() override;
	void Draw3D() override;
	void Draw2D() override;
	
private:
	std::unique_ptr<Player> player_;
	std::unique_ptr<DefaltMap> Map[2];
	ViewProjection viewProjection_;
	uint32_t stage_;
};
