#include "DefaltMap.h"
#include"TextureManager.h"

void DefaltMap::Draw() { 

	for (std::unique_ptr<Sprite>& floor : floors) {
		floor->Draw();
	}


}

void DefaltMap::Iint() {
	flooorTexture = TextureManager::Load("PlayerResouce/kari.png");
	for (int i = 0; i < High; i++) {
		for (int j = 0; j < Wide; j++) {
			if (map[i][j] ==1) {
				std::unique_ptr<Sprite> newfloor;
				newfloor = std::make_unique<Sprite>();
				newfloor.reset(Sprite::Create(flooorTexture, {64.f * j, 64.f * i}));
				floors.push_back(std::move(newfloor));
			}
			
			
			
			
		}
	}
}

DefaltMap::~DefaltMap() {}


