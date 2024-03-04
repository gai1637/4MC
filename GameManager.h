#pragma once
#include<memory>
#include"IScene.h"
#include"StageScene.h"
#include"TitleScene.h"
#include"ClearScene.h"
#include"GameOverScene.h"
class GameManager {
private:
	//シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArr_[4];

	//どのステージを呼び出すかを管理する変数
	int currentSceneNo_;//現在のシーン
	int prevSceneNo_;//前のシーン
public:
	GameManager();

	

	void Update();
	void Draw3D();
	void Draw2D();
};
