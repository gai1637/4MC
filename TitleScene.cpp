#include "TitleScene.h"

void TitleScene::Iint() { 
	textureHandle_ = TextureManager::Load("Game Title.png");
	sprite_.reset(Sprite::Create(textureHandle_, {0,0}));
	input_ = Input::GetInstance();

}

void TitleScene::Update() {
	XINPUT_STATE joyState;
	if (Input::GetInstance()->GetJoystickState(0, joyState)) {
		if (joyState.Gamepad.wButtons & XINPUT_GAMEPAD_B) {
			sceneNo_ = STAGE;
		}

	}
	if (input_->TriggerKey(DIK_SPACE)) {
		sceneNo_ = STAGE;
	}
	
}

void TitleScene::Draw3D() {}

void TitleScene::Draw2D() { sprite_->Draw(); }


