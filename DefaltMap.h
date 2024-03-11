#pragma once
#include"Sprite.h"
#include"memory"
#include<List>
class DefaltMap {
public:
	void PreAnime();
	void Draw();
	void PostAnime();
	void Iint();
	virtual void Initialize() = 0;
	virtual ~DefaltMap();

protected:
	
	static const int Wide = 100;
	static const int High = 720 / 64;
	int map[High][Wide];
	std::list <std::unique_ptr<Sprite>> floors;

	int flooorTexture;
};
