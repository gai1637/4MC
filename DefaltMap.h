#pragma once
#include"Sprite.h"
#include"memory"
class DefaltMap {
	void PreAnime();
	void Draw();
	void PostAnime();
	void Iint();
	DefaltMap();

protected:
	static const int Wide = 100;
	static const int High = 720 / 32;
	int map[High][Wide];
	std::unique_ptr<Sprite> floor[High][Wide];
	int flooorTexture;
};
