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
	Vector3 GetPrepos() { return PrePos; }
	void SetPrepos(const Vector3& pos) { PrePos = pos; }
	const float GetSize() { return size; }
	void PlayerMove();
	
private:
	void kRootInitialize();
	void KRootUpdate();

private:
	Input* input_;
	Behavior behavior_ = Behavior::kRoot;
	std::optional<Behavior> behaviorRequest_ = std::nullopt;
	XINPUT_STATE joyState;
	Vector3 PrePos;
	float speed;
	float jumpSpeed;
	
};
