#include "DefaltMap.h"
#include"TextureManager.h"
Map::~Map() {}

void Map::Draw() { sprite_->Draw(); }

float Map::GetLeftPosition() const { return posision_.x; }

float Map::GetUpPosition() const { return posision_.y; }

float Map::GetDownPosition() const { return posision_.y + size_ - 1; }

float Map::GetRightPosition() const { return posision_.x+size_-1; }

void Map::Iint(int i, Vector2 pos) {
	size_ = 64.f;
	flooorTexture = TextureManager::Load("PlayerResouce/kari.png");

	posision_ = pos;
	switch (i) {
	case 1:
		sprite_ = std::make_unique<Sprite>();
		sprite_.reset(Sprite::Create(flooorTexture,posision_));
		break;
	default:
		break;
	}
}

void DefaltMap::Draw() { 

	for (std::unique_ptr<Map>&map_ : maps_) {
		map_->Draw();
	}


}

void DefaltMap::Iint() {
	
	for (int i = 0; i < High; i++) {
		for (int j = 0; j < Wide; j++) {
			if (map[i][j] ==1) {
				unique_ptr<Map> newMap_;
				newMap_ = std::make_unique<Map>();
				newMap_->Iint(1, {64.f * j, 64.f * i});
				maps_.push_back(std::move(newMap_));

			}
			
			
			
			
		}
	}
}

