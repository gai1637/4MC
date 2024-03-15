#include "Map.h"



void Map1::Initialize() { 
	for (int i = 0; i < High; i++) {
		for (int j = 0; j < Wide; j++) {
			map[i][j] = premap[i][j];
		}
	}
	Iint();
}

Map1::~Map1() {}
