#include "DefaltMap.h"
#include"TextureManager.h"
Map::~Map() {}

void Map::Draw() { sprite_->Draw(); }

Vector3 Map::GetLeftUpPosition() const 
{ 
	Vector3 vector;
	vector.x = posision_.x;
	vector.y = posision_.y;
	vector.z = 0;
	return vector; 
}

Vector3 Map::GetRightUpPosition() const 
{ 
	Vector3 vector;
	vector.x = posision_.x+size;
	vector.y = posision_.y;
	vector.z = 0;
	return vector; 
}

Vector3 Map::GetLeftDownPosition() const 
{
	Vector3 vector;
	vector.x = posision_.x ;
	vector.y = posision_.y+ size;
	vector.z = 0;
	return vector;
}

Vector3 Map::GetRightDownPosition() const 
{ 
	Vector3 vector;
	vector.x = posision_.x + size;
	vector.y = posision_.y+ size;
	vector.z = 0;
	return vector;
}

void Map::Iint(int i, Vector2 pos) {
	size = 64.f;
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

