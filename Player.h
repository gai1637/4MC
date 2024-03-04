#pragma once
#include "Char.h"
#include"Input.h"
#include"optional"
enum Behavior {
	kRoot,//’Êíó‘Ô
	kAttack,//UŒ‚ó‘Ô
	kFlyte,//”òsó‘Ô


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
