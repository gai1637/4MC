#pragma once
#include "Char.h"
#include"Input.h"
#include"optional"
enum Behavior {
	kRoot,//通常状態
	kAttack,//攻撃状態
	kFlyte,//飛行状態


};
class Player : public Char {
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Draw3D(const ViewProjection& viewProjection);
	void BehaviorUpdate();

private:
	Input* input_;
	Behavior behavior_ = Behavior::kRoot;
	std::optional<Behavior> behaviorRequest_ = std::nullopt;
};
