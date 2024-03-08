#include "DefaltMap.h"
#include"TextureManager.h"

DefaltMap::DefaltMap() { 
	flooorTexture = TextureManager::Load("PlayerResouce/kari.png");
	for (int i = 0; i < High; i++) {
		for (int j = 0; j < Wide; j++) {
			floor[i][j] = std::make_unique<Sprite>();
			if (map[i][j] == 1) {
				floor[i][j].reset(Sprite::Create(flooorTexture, {(float)i*32,(float)j*32}));
			} else {
				floor[i][j] = nullptr;
			}
		}
	}
	
	
}
