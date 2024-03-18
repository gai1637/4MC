#pragma once
#include"Colider2D.h"
#include"list"
#include"Vector3.h"
#include"Vector4.h"
class ColisionManager {
private:
	std::list<Colider2D*> coliders_;

public:
	void Reset();
	void CheckColisionPair(Colider2D* coliderA, Colider2D* coliderB);
	void CheckAllColisions();
	void AddColider(Colider2D* colider);
};
