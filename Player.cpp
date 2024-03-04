
#include "Player.h"

void Player::Initialize() { 
	worldTransform_->Initialize();
	sprite_.reset(Sprite::Create(
	    textureHandle_, {worldTransform_->translation_.x, worldTransform_->translation_.y}));

}

void Player::Update() { 

	BehaviorUpdate();

	worldTransform_->UpdateMatrix(); 
}

void Player::Draw3D(const ViewProjection& viewProjection) {

}

void Player::BehaviorUpdate() { 
	if (behaviorRequest_) {
		behavior_ = behaviorRequest_.value();
		switch (behavior_) {
		case kRoot:
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
		break;
	case kAttack:
		break;
	case kFlyte:
		break;
	default:
		break;

	}
}

void Player::Draw() { sprite_->Draw(); }

