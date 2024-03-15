#pragma once
#include"Sprite.h"
#include"memory"
#include<List>
#include"Colider2D.h"

class Map : Colider2D {
public:
	template<class T> using unique_ptr=std::unique_ptr<T>;
	Vector3 GetLeftUpPosition() const override;
	Vector3 GetRightUpPosition() const override;
	Vector3 GetLeftDownPosition() const override;
	Vector3 GetRightDownPosition() const override;
	void Iint(int i,Vector2 pos);
	
	virtual ~Map();
	void Draw();

private:
	unique_ptr<Sprite> sprite_;
	int flooorTexture;
	Vector2 posision_;
	float size = 64.0;
};
class DefaltMap{
public:
	virtual void Initialize()=0;
	void PreAnime();
	void Draw();
	void PostAnime();
	void Iint();
	
	int Getmap(int a, int b) { return map[a][b]; }
	virtual ~DefaltMap() = default;
protected:
	
	static const int Wide = 100;
	static const int High = 720 / 64;
	int map[High][Wide];
	
	std::list<std::unique_ptr<Map>> maps_;
	
};
