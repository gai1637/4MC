#include "IScene.h"

int IScene::sceneNo_=TITLE;

IScene::~IScene(){};

int IScene::GetScene() { return sceneNo_; }