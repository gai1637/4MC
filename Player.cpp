#include"TextureManager.h"
#include "Player.h"
#include"imgui.h"

void Player::Initialize() { 
	textureHandle_ = TextureManager::Load("PlayerREsouce/kari.png");
	
	worldTransform_.translation_ = {100.f, 100.f, 0.f};
	worldTransform_.Initialize();
	PrePos = worldTransform_.translation_;
	speed = 0.f;
	jumpSpeed = 0.f;
	sprite_.reset(Sprite::Create(
	    textureHandle_, {worldTransform_.translation_.x, worldTransform_.translation_.y}));
	model = std::make_unique<Model>();
	model.reset(Model::CreateFromOBJ("box", true));
	input_ = Input::GetInstance();
	size_ = 64;
}

void Player::Update() { 

	BehaviorUpdate();
	ImGui::Begin("a");
	ImGui::DragFloat("%f", &speed);
	ImGui::End();
	worldTransform_.UpdateMatrix(); 
}

void Player::Draw3D(const ViewProjection& viewProjection) {
	model->Draw(worldTransform_, viewProjection);
}

void Player::BehaviorUpdate() { 
	if (behaviorRequest_) {
		behavior_ = behaviorRequest_.value();
		switch (behavior_) {
		case kRoot:
			kRootInitialize();
			break;
		case kAttack:
			break;
		case kFlyte:
			break;
		default:
			break;
		}
		behaviorRequest_ = std::nullopt;
	}
	switch (behavior_) {
	case kRoot:
		KRootUpdate();
		break;
	case kAttack:
		break;
	case kFlyte:
		break;
	default:
		break;

	}
}

void Player::PlayerMove() {
worldTransform_.translation_ = PrePos;
	sprite_.reset(Sprite::Create(
	    textureHandle_, {worldTransform_.translation_.x, worldTransform_.translation_.y}));
}

void Player::kRootInitialize() {
	
}

void Player::KRootUpdate() { 
	
	const float acceleration = 1.f;
	const float MaxSpeed = 10.0f;
	const float gravity = 0.0f;
	if (Input::GetInstance()->GetJoystickState(0, joyState)) {
		bool isMoving = false;
		const float threshold = 0.7f;
		float move = (float)joyState.Gamepad.sThumbLX / SHRT_MAX;
		if (move > threshold||move<-threshold) {
			isMoving = true;
			
		} else {
			speed = 0.0f;
		}
		if (isMoving) {
			
			PrePos.x += speed*move;
			
			if (speed<=MaxSpeed)
			speed += acceleration;
			
			
		} 
		if (joyState.Gamepad.wButtons & XINPUT_GAMEPAD_A) {
			jumpSpeed = 1.0f;
		}

	} else
	{
		if (input_->PushKey(DIK_A)) {
			PrePos.x-=speed;
			if (speed<=MaxSpeed)
			speed += acceleration;
		}else if (input_->PushKey(DIK_D)) {
			PrePos.x += speed;
			if (speed<=MaxSpeed)
			speed += acceleration;
		} else {
			speed = 0.f;
		}
		if (input_->TriggerKey(DIK_SPACE)) {
			jumpSpeed = 1.f;
		}
		if (input_->IsPressMouse(0)) {
			behaviorRequest_ = Behavior::kAttack;
		}
		
	}
	PrePos.y += jumpSpeed;
	jumpSpeed -= gravity;
	
}

void Player::Draw() { sprite_->Draw(); }

